// arquivo: jogadorTeclado.h
#ifndef JOGADORTECLADO_H
#define JOGADORTECLADO_H

#include <stdio.h>
#include "tabuleiro.h"

typedef struct {
    int tipo; // VALOR_X (4) ou VALOR_O (1)
} JogadorTeclado;

void jogaTeclado(JogadorTeclado *jogador, Tabuleiro *tab) {
    int posicao;
    int linha = 0, coluna = 0;

    while (1) {
        printf("Vez de %c. Digite a posicao de 1 a 9: ", simbolo(jogador->tipo));

        if (scanf("%d", &posicao) != 1) {
            printf("Entrada invalida! Digite um numero de 1 a 9.\n");
            buffer();
            continue;
        }
        if (posicao < 1 || posicao > 9) {
            printf("Posicao invalida! Escolha de 1 a 9.\n");
            continue;
        }

        // converte linha e coluna
        int contador = 1;                  
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {    
                if (contador == posicao) {
                    linha = i;
                    coluna = j;
                }
                contador++;
            }
        }
       
        if (tab->M[linha][coluna] != 0) {
            printf("Essa casa ja esta ocupada!\n");
            continue;
        }

        // marca a jogada usando a função criada em tabuleiro.h
        marcaJogada(tab, linha, coluna, jogador->tipo);
        break;
    }
}

#endif