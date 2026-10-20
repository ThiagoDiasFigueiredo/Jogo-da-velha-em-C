#include <stdio.h>
#include <stdlib.h>
#include "tabuleiro.h"

int jogador_X_IA(){
    int sorteio = rand() % 2, tabuleiro[3][3],jogada_usuario, cont = 0;
    Criartabuleiro(tabuleiro);
    imprimirTabuleiro(tabuleiro);

    if (sorteio == 0){
        puts("O jogador vai começar");
        printf("Digite a posição que deseja jogar: ");
        scanf("%d", &jogada_usuario);
        tabuleiro[(jogada_usuario-1)/3][(jogada_usuario-1)%3] = 'X';
        imprimirTabuleiro(tabuleiro);
    }
    else{
        puts("A IA vai começar");
        tabuleiro[1][1] = 'O';
        imprimirTabuleiro(tabuleiro);
    }
    while (cont < 1){
        printf("Digite a posição que deseja jogar: ");
        scanf("%d", &jogada_usuario);
        tabuleiro[(jogada_usuario-1)/3][(jogada_usuario-1)%3] = 'X';
        
        if (tabuleiro[1][1] == '0'){
            tabuleiro[1][1] = 'O';
        }
        else if (jogada_usuario == 1 && tabuleiro[2][2] == '0'){
            tabuleiro[2][2] = 'O';
        }
        else if(jogada_usuario == 2 && tabuleiro [2][1] == '0'){
            tabuleiro[2][1] = 'O';
        }
        else if(jogada_usuario == 3 && tabuleiro [2][0] == '0'){
            tabuleiro[2][0] = 'O';
        }
        else if(jogada_usuario == 4 && tabuleiro [1][2] == '0'){
            tabuleiro[1][2] = 'O';
        }        
        else if(jogada_usuario == 6 && tabuleiro [1][0] == '0'){
            tabuleiro[2][1] = 'O';
        }        
        else if(jogada_usuario == 7 && tabuleiro [0][2] == '0'){
            tabuleiro[0][2] = 'O';
        }        
        else if(jogada_usuario == 8 && tabuleiro [0][1] == '0'){
            tabuleiro[0][1] = 'O';
        }
        else if(jogada_usuario == 9 && tabuleiro [0][0] == '0'){
            tabuleiro[0][0] = 'O';
        } 

        cont = 0;
        for (int i = 0; i<3;i++){
            for (int j = 0; j<3;j++){
                if (tabuleiro[i][j] == '0'){
                    cont++;
                }
            }
        }
    }
}