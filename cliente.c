#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include "tabuleiro.h"

#pragma comment(lib, "ws2_32.lib")

int main() {
    WSADATA wsa;
    SOCKET s;
    struct sockaddr_in servidor;
    char buffer[100];

    Tabuleiro tab;
    inicializarTabuleiro(&tab);

    // 1. Inicializa o Winsock
    printf("Inicializando Winsock...\n");
    if (WSAStartup(MAKEWORD(2,2), &wsa) != 0) {
        printf("Falha. Erro: %d\n", WSAGetLastError());
        return 1;
    }

    // 2. Cria o Socket
    s = socket(AF_INET, SOCK_STREAM, 0);
    if (s == INVALID_SOCKET) {
        printf("Criacao do socket falhou: %d\n", WSAGetLastError());
        return 1;
    }

    // 3. Configura o endereço do servidor (localhost)
    servidor.sin_addr.s_addr = inet_addr("127.0.0.1"); //ip do proprio computador, em outro computador é diferente
    servidor.sin_family = AF_INET; //protocolo IPv4
    servidor.sin_port = htons(8888); //porta que o servidor abriu (8888)

    // 4. Conecta ao servidor
    //Se o servidor não estiver ligado, ele falha
    if (connect(s, (struct sockaddr *)&servidor, sizeof(servidor)) < 0) {
        printf("Erro ao conectar ao servidor.\n");
        return 1;
    }

    printf("Conectado ao Servidor com sucesso! O jogo vai comecar.\n");

    int rodada = 0;
    int vencedor = -1;

    desenha(&tab);

    while (rodada < 9 && vencedor == -1) {
        // Servidor (X) joga nas rodadas pares (0, 2, 4...)
        if (rodada % 2 == 0) {
            printf("Aguardando a jogada do Servidor (X)...\n");
            memset(buffer, 0, sizeof(buffer));
            int bytes_recebidos = recv(s, buffer, sizeof(buffer), 0);
            if (bytes_recebidos <= 0) {
                printf("O servidor desconectou.\n");
                break;
            }

            int posicao = atoi(buffer);
            int linha = (posicao - 1) / 3;
            int coluna = (posicao - 1) % 3;

            marcaJogada(&tab, linha, coluna, VALOR_X);
        } 
        // Cliente é o Jogador 2 (O) e joga nas rodadas ímpares (1, 3, 5...)
        else {
            int posicao;
            while (1) {
                printf("Sua vez (O). Digite a posicao de 1 a 9: ");
                if (scanf("%d", &posicao) != 1) {
                    printf("Entrada invalida!\n");
                    buffer_stdin();
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

                // Marca no tabuleiro do cliente
                marcaJogada(&tab, linha, coluna, VALOR_O);

                // Envia a jogada para o servidor
                sprintf(buffer, "%d", posicao);
                send(s, buffer, strlen(buffer), 0);
                break;
            }
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

    closesocket(s);
    WSACleanup();
    return 0;
}