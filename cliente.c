// arquivo: cliente.c
#include <stdio.h>
#include "tabuleiro.h"
#include "online.h"

int main() {
    Tabuleiro tab;
    inicializarTabuleiro(&tab);

    char ip_servidor[50];
    printf("Digite o IP do Servidor (ex: 127.0.0.1): ");
    scanf("%s", ip_servidor);

    JogadorRemoto remoto;
    remoto.tipo = VALOR_X; // O servidor remoto jogará com 'X'

    // Função dedicada do Cliente
    conecta(&remoto, ip_servidor, 8888);

    int rodada = 0;
    int vencedor = -1;
    desenha(&tab);

    while (rodada < 9 && vencedor == -1) {
        if (rodada % 2 == 0) {
            // Vez do Servidor (X) via rede
            printf("Aguardando a jogada do Servidor (X)...\n");
            jogaRemoto(&remoto, &tab);
        } else {
            // Vez do Cliente (O)
            int posicao;
            while (1) {
                printf("Sua vez (O). Digite a posicao de 1 a 9: ");
                if (scanf("%d", &posicao) != 1) {
                    printf("Entrada invalida!\n");
                    buffer();
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
                marcaJogada(&tab, linha, coluna, VALOR_O);
                enviaJogada(&remoto, posicao);
                break;
            }
        }

        rodada++;
        desenha(&tab);
        vencedor = temVencedor(&tab);
    }

    if (vencedor == 1) {
        printf(" " VERMELHO "JOGADOR X (Servidor) VENCEU!\n" RESET " ");
    } else if (vencedor == 2) {
        printf(" " VERDE "JOGADOR O (Cliente) VENCEU!\n" RESET " ");
    } else {
        printf(" " AMARELO "EMPATE!\n" RESET " ");
    }

    fechaConexao(&remoto);
    return 0;
}