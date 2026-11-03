// arquivo: servidor.c
#include <stdio.h>
#include "tabuleiro.h"
#include "online.h"

int main() {
    Tabuleiro tab;
    inicializarTabuleiro(&tab);

    JogadorRemoto remoto;
    remoto.tipo = VALOR_O; // O cliente remoto jogará com 'O'

    // Função dedicada do Servidor
    aceitaConexao(&remoto, 8888);

    int rodada = 0;
    int vencedor = -1;
    desenha(&tab);

    while (rodada < 9 && vencedor == -1) {
        if (rodada % 2 == 0) {
            // Vez do Servidor (X)
            int posicao;
            while (1) {
                printf("Sua vez (X). Digite a posicao de 1 a 9: ");
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
                marcaJogada(&tab, linha, coluna, VALOR_X);
                enviaJogada(&remoto, posicao);
                break;
            }
        } else {
            // Vez do Cliente (O) via rede
            printf("Aguardando a jogada do Cliente (O)...\n");
            jogaRemoto(&remoto, &tab);
        }

        rodada++;
        desenha(&tab);
        vencedor = temVencedor(&tab);
    }

    fechaConexao(&remoto);
    return 0;
}