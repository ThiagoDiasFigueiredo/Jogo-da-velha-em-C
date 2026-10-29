#ifndef JOGO_H
#define JOGO_H

#include <stdio.h>
#include "tabuleiro.h"
#include "menu.h"

int verificarVencedor(int tabuleiro[3][3]){
    int combinacoes[8][3] = {
        {1, 2, 3}, {4, 5, 6}, {7, 8, 9},   // linhas 
        {1, 4, 7}, {2, 5, 8}, {3, 6, 9},   // colunas 
        {1, 5, 9}, {3, 5, 7}               // diagonais 
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

        if(scanf("%d", &posicao) != 1){
            printf("Entrada invalida! Digite um numero de 1 a 9.\n");
            buffer();
            continue;
        }
        if(posicao < 1 || posicao > 9){
            printf("Posicao invalida! Escolha de 1 a 9.\n");
            continue;
        }
        //Verificação da posição digitada
        int contador = 1;                  
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){    
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
        limparTela();
        imprimirTabuleiro(tabuleiro);
        vencedor = verificarVencedor(tabuleiro);

        if(jogador == VALOR_X){
            jogador = VALOR_O;
        } else {
            jogador = VALOR_X;
        }
    }

    if(vencedor == 1){
        printf(" " VERMELHO "JOGADOR X VENCEU!\n" RESET " ");
    } else if(vencedor == 2){
        printf(" " VERDE "JOGADOR O VENCEU!\n" RESET " ");
    } else {
        printf(" " AMARELO "EMPATE!\n" RESET " ");
    }

}
    
#endif