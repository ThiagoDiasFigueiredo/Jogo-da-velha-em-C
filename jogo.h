#ifndef JOGO_H
#define JOGO_H

#include <stdio.h>
#include "tabuleiro.h"

int verificarVencedor(int tabuleiro[3][3]){
    int combinacoes[8][3] = {
        {1, 2, 3}, {4, 5, 6}, {7, 8, 9},   /* linhas */
        {1, 4, 7}, {2, 5, 8}, {3, 6, 9},   /* colunas */
        {1, 5, 9}, {3, 5, 7}               /* diagonais */
    };

    for(int i = 0; i < 8; i++){
        int soma = 0;
        for(int j = 0; j < 3; j++){
            int p = combinacoes[i][j] - 1;
            soma += tabuleiro[p / 3][p % 3];
        }
        if(soma == 12){
            return 1; // X
        } else if(soma == 3){
            return 2; // O
        }
    }
    return -1;
}

void jogo(int tabuleiro[3][3], int jogador){
    int rodada = 0;
    int vencedor = -1; // -1 = ninguém ganhou ainda, 1 = X, 2 = O
    int posicao;
    int linha = 0, coluna = 0;

    imprimirTabuleiro(tabuleiro);

    while(rodada != 9 && vencedor == -1){
        printf("Rodada %d, vez de %c\n", rodada + 1, simbolo(jogador));
        printf("Digite a posicao de 1 a 9: ");

        int lido = scanf("%d", &posicao);
        if(lido == EOF){
            return;
        }
        if(lido != 1){
            printf("Entrada invalida! Digite um numero de 1 a 9.\n");
            limparBuffer();
            continue;
        }
        if(posicao < 1 || posicao > 9){
            printf("Posicao invalida! Escolha de 1 a 9.\n");
            continue;
        }

        int contador = 1;                  /* zera a cada jogada */
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){    /* era i < 3 e i++ */
                if(contador == posicao){
                    linha = i;
                    coluna = j;
                }
                contador++;
            }
        }

        if(tabuleiro[linha][coluna] != 0){
            printf("Essa casa ja esta ocupada!\n");
            continue;
        }

        tabuleiro[linha][coluna] = jogador;
        rodada++;
        imprimirTabuleiro(tabuleiro);
        vencedor = verificarVencedor(tabuleiro);

        if(jogador == VALOR_X){
            jogador = VALOR_O;
        } else {
            jogador = VALOR_X;
        }
    }

    /* resultado só depois que o loop termina */
    if(vencedor == 1){
        printf("Jogador X venceu!\n");
    } else if(vencedor == 2){
        printf("Jogador O venceu!\n");
    } else {
        printf("Deu empate!\n");
    }
}

#endif