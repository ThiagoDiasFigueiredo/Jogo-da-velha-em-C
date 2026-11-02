#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include "tabuleiro.h"

int main() {
    WSADATA versao;
    SOCKET s, novo_socket;
    struct sockaddr_in server, cliente;
    int c;
    char mensagem[100];

    Tabuleiro tab;
    inicializarTabuleiro(&tab);

    // 1. Inicializa o Winsock
    printf("Inicializando Winsock...\n");
    if (WSAStartup(MAKEWORD(2,2), &versao) != 0) { //versão 2.2 do Winsock, se der != 0, deu erro.
        printf("Falha. Erro: %d\n", WSAGetLastError());
        return 1;
    }

    // 2. Cria o Socket
    s = socket(AF_INET, SOCK_STREAM, 0);
    if (s == INVALID_SOCKET) {
        printf("Criacao do socket falhou: %d\n", WSAGetLastError());
        return 1;
    }

    // 3. Prepara a estrutura do servidor
    server.sin_family = AF_INET; //Protocolo IPv4 (é IP)
    server.sin_addr.s_addr = INADDR_ANY;  
    server.sin_port = htons(8888);//A porta que vai ser utilizada

    // 4. Faz o Bind
    if (bind(s, (struct sockaddr *)&server, sizeof(server)) == SOCKET_ERROR) { 
        printf("Bind falhou: %d\n", WSAGetLastError());
        return 1;
    }
    //O bind "amarra" o socket a porta 8888 (definida anteriormente)
    // 5. Ouve por conexões

    listen(s, 3);
    printf("Aguardando conexao do Cliente na porta 8888...\n");

    c = sizeof(struct sockaddr_in);
    novo_socket = accept(s, (struct sockaddr *)&cliente, &c); //O accept congela o programa e espera alguem entrar
    if (novo_socket == INVALID_SOCKET) {
        printf("Aceite falhou: %d\n", WSAGetLastError());
        return 1;
    }
    //se o cliente for aceito, ele vai para a variavel novo_socket e o socket antigo fica livre

    //Jogo normal
    printf("Cliente conectado! O jogo vai comecar.\n");

    int rodada = 0;
    int vencedor = -1;

    desenha(&tab);

    while (rodada < 9 && vencedor == -1) {
        // Servidor é o Jogador 1 (X) e sempre começa as rodadas pares (0, 2, 4...)
        if (rodada % 2 == 0) {
            int posicao;
            while (1) {
                printf("Sua vez (X). Digite a posicao de 1 a 9: ");
                if (scanf("%d", &posicao) != 1) {
                    printf("Entrada invalida!\n");
                    buffer(); // Limpa mensagem caso necessário
                    continue;
                }
                if (posicao < 1 || posicao > 9) {
                    printf("Posicao invalida! Escolha de 1 a 9.\n");
                    continue;
                }

                int linha = (posicao - 1) / 3;
                int coluna = (posicao - 1) % 3;

                if (tab.M[linha][coluna] != 0) {
                    printf("Essa casa ja esta ocupada!\n");
                    continue;
                }

                // Marca no tabuleiro do servidor
                marcaJogada(&tab, linha, coluna, VALOR_X);
                
                // Envia a jogada para o cliente
                sprintf(mensagem, "%d", posicao);
                send(novo_socket, mensagem, strlen(mensagem), 0);
                break;
            }
        } 
        // Vez do Cliente (O) nas rodadas ímpares (1, 3, 5...)
        else {
            printf("Aguardando a jogada do Cliente (O)...\n");
            memset(mensagem, 0, sizeof(mensagem));
            int bytes_recebidos = recv(novo_socket, mensagem, sizeof(mensagem), 0);
            if (bytes_recebidos <= 0) {
                printf("O cliente desconectou.\n");
                break;
            }

            int posicao = atoi(mensagem); //A função atoi transforma caractere em número. Ex: "7" vira 7
            int linha = (posicao - 1) / 3;
            int coluna = (posicao - 1) % 3;
            
            marcaJogada(&tab, linha, coluna, VALOR_O);
        }

        rodada++;
        desenha(&tab);
        vencedor = temVencedor(&tab);
    }

    // Resultado final
    if (vencedor == 1) {
        printf(" " VERMELHO "JOGADOR X (Servidor) VENCEU!\n" RESET " ");
    } else if (vencedor == 2) {
        printf(" " VERDE "JOGADOR O (Cliente) VENCEU!\n" RESET " ");
    } else {
        printf(" " AMARELO "EMPATE!\n" RESET " ");
    }

    closesocket(novo_socket);
    closesocket(s);
    WSACleanup();
    return 0;
}