// arquivo: online.h
#ifndef ONLINE_H
#define ONLINE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include "tabuleiro.h"

// Estrutura para gerenciar a conexão remota
typedef struct {
    SOCKET socket_conexao;
    int tipo; // VALOR_X ou VALOR_O
} JogadorRemoto;

// Inicializa o Winsock
void inicializarWinsock() {
    WSADATA versao;
    printf("Inicializando Winsock...\n");
    if (WSAStartup(MAKEWORD(2,2), &versao) != 0) {
        printf("Falha ao inicializar. Erro: %d\n", WSAGetLastError());
        exit(1);
    }
}

// Função para o Servidor aceitar a conexão do cliente
void aceitaConexao(JogadorRemoto *remoto, int porta) {
    inicializarWinsock();
    SOCKET s = socket(AF_INET, SOCK_STREAM, 0);
    if (s == INVALID_SOCKET) {
        printf("Criacao do socket falhou: %d\n", WSAGetLastError());
        exit(1);
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(porta);

    if (bind(s, (struct sockaddr *)&server, sizeof(server)) == SOCKET_ERROR) {
        printf("Bind falhou: %d\n", WSAGetLastError());
        exit(1);
    }

    listen(s, 3);
    printf("Aguardando conexao do Cliente na porta %d...\n", porta);

    struct sockaddr_in cliente;
    int c = sizeof(struct sockaddr_in);
    remoto->socket_conexao = accept(s, (struct sockaddr *)&cliente, &c);
    
    if (remoto->socket_conexao == INVALID_SOCKET) {
        printf("Aceite falhou: %d\n", WSAGetLastError());
        exit(1);
    }
    printf("Cliente conectado! O jogo vai comecar.\n");
    closesocket(s); // Fecha o socket de escuta, pois já aceitou o cliente
}

// Função para o Cliente se conectar a um servidor
void conecta(JogadorRemoto *remoto, const char *ip, int porta) {
    inicializarWinsock();
    remoto->socket_conexao = socket(AF_INET, SOCK_STREAM, 0);
    if (remoto->socket_conexao == INVALID_SOCKET) {
        printf("Criacao do socket falhou: %d\n", WSAGetLastError());
        exit(1);
    }

    struct sockaddr_in servidor;
    servidor.sin_addr.s_addr = inet_addr(ip);
    servidor.sin_family = AF_INET;
    servidor.sin_port = htons(porta);

    printf("Conectando ao servidor %s:%d...\n", ip, porta);
    if (connect(remoto->socket_conexao, (struct sockaddr *)&servidor, sizeof(servidor)) < 0) {
        printf("Erro ao conectar ao servidor.\n");
        exit(1);
    }
    printf("Conectado ao Servidor com sucesso! O jogo vai comecar.\n");
}

// Envia a jogada pela rede
void enviaJogada(JogadorRemoto *remoto, int posicao) {
    char mensagem[100];
    sprintf(mensagem, "%d", posicao);
    send(remoto->socket_conexao, mensagem, strlen(mensagem), 0);
}

// Recebe a jogada do adversário pela rede
void jogaRemoto(JogadorRemoto *remoto, Tabuleiro *tab) {
    char mensagem[100];
    memset(mensagem, 0, sizeof(mensagem));
    
    int bytes_recebidos = recv(remoto->socket_conexao, mensagem, sizeof(mensagem), 0);
    if (bytes_recebidos <= 0) {
        printf("O adversario desconectou.\n");
        exit(1);
    }

    int posicao = atoi(mensagem);
    int linha = (posicao - 1) / 3;
    int coluna = (posicao - 1) % 3;

    marcaJogada(tab, linha, coluna, remoto->tipo);
}

// Fecha a conexão ao fim do jogo
void fechaConexao(JogadorRemoto *remoto) {
    closesocket(remoto->socket_conexao);
    WSACleanup();
}

#endif