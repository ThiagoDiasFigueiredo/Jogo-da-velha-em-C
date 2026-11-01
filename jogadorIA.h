// arquivo: jogo_IA.h
#ifndef JOGO_IA_H
#define JOGO_IA_H

#include <stdio.h>
#include <stdlib.h>
#include "tabuleiro.h"

typedef struct {
    int tipo; // VALOR_X (4) ou VALOR_O (1)
} JogadorIA;

void jogaIA(JogadorIA *ia_player, Tabuleiro *tab) {
    int (*tabuleiro)[3] = tab->M; // Aponta para a matriz M dentro de Tabuleiro
    int ia = ia_player->tipo;
    int jogador = (ia == VALOR_X) ? VALOR_O : VALOR_X;
    int ameaca;

    // Marca o quadrado faltando para a IA ganhar
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == ia && tabuleiro[i][1] == ia && tabuleiro[i][2] == 0){
            marcaJogada(tab, i, 2, ia); return;
        }
        else if (tabuleiro[i][0] == ia && tabuleiro[i][2] == ia && tabuleiro[i][1] == 0){
            marcaJogada(tab, i, 1, ia); return;
        }
        else if (tabuleiro[i][1] == ia && tabuleiro[i][2] == ia && tabuleiro[i][0] == 0){
            marcaJogada(tab, i, 0, ia); return;
        }
    }
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[0][i] == ia && tabuleiro[1][i] == ia && tabuleiro[2][i] == 0){
            marcaJogada(tab, 2, i, ia); return;
        }
        else if (tabuleiro[0][i] == ia && tabuleiro[2][i] == ia && tabuleiro[1][i] == 0){
            marcaJogada(tab, 1, i, ia); return;
        }
        else if (tabuleiro[1][i] == ia && tabuleiro[2][i] == ia && tabuleiro[0][i] == 0){
            marcaJogada(tab, 0, i, ia); return;
        }
    }
    if (tabuleiro[0][0] == ia && tabuleiro[1][1] == ia && tabuleiro[2][2] == 0){
        marcaJogada(tab, 2, 2, ia); return;
    }
    else if (tabuleiro[0][0] == ia && tabuleiro[2][2] == ia && tabuleiro[1][1] == 0){
        marcaJogada(tab, 1, 1, ia); return;
    }
    else if (tabuleiro[1][1] == ia && tabuleiro[2][2] == ia && tabuleiro[0][0] == 0){
        marcaJogada(tab, 0, 0, ia); return;
    }
    else if (tabuleiro[0][2] == ia && tabuleiro[1][1] == ia && tabuleiro[2][0] == 0){
        marcaJogada(tab, 2, 0, ia); return;
    }
    else if (tabuleiro[0][2] == ia && tabuleiro[2][0] == ia && tabuleiro[1][1] == 0){
        marcaJogada(tab, 1, 1, ia); return;
    }
    else if (tabuleiro[1][1] == ia && tabuleiro[2][0] == ia && tabuleiro[0][2] == 0){
        marcaJogada(tab, 0, 2, ia); return;
    }

    // R1 (Parte 2): Marcação para impedir que o adversário ganhe
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == 0){
            marcaJogada(tab, i, 2, ia); return;
        }
        else if (tabuleiro[i][0] == jogador && tabuleiro[i][2] == jogador && tabuleiro[i][1] == 0){
            marcaJogada(tab, i, 1, ia); return;
        }
        else if (tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador && tabuleiro[i][0] == 0){
            marcaJogada(tab, i, 0, ia); return;
        }
    }
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[0][i] == jogador && tabuleiro[1][i] == jogador && tabuleiro[2][i] == 0){
            marcaJogada(tab, 2, i, ia); return;
        }
        else if (tabuleiro[0][i] == jogador && tabuleiro[2][i] == jogador && tabuleiro[1][i] == 0){
            marcaJogada(tab, 1, i, ia); return;
        }
        else if (tabuleiro[1][i] == jogador && tabuleiro[2][i] == jogador && tabuleiro[0][i] == 0){
            marcaJogada(tab, 0, i, ia); return;
        }
    }
    if (tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == 0){
        marcaJogada(tab, 2, 2, ia); return;
    }
    else if (tabuleiro[0][0] == jogador && tabuleiro[2][2] == jogador && tabuleiro[1][1] == 0){
        marcaJogada(tab, 1, 1, ia); return;
    }
    else if (tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador && tabuleiro[0][0] == 0){
        marcaJogada(tab, 0, 0, ia); return;
    }
    else if (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == 0){
        marcaJogada(tab, 2, 0, ia); return;
    }
    else if (tabuleiro[0][2] == jogador && tabuleiro[2][0] == jogador && tabuleiro[1][1] == 0){
        marcaJogada(tab, 1, 1, ia); return;
    }
    else if (tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador && tabuleiro[0][2] == 0){
        marcaJogada(tab, 0, 2, ia); return;
    }

    // Cria uma jogada com 2 chances de vitoria
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (tabuleiro[i][j] == 0){
                tabuleiro[i][j] = ia;
                ameaca = 0;
                for(int k = 0; k < 3; k++) {
                    if((tabuleiro[k][0]==ia && tabuleiro[k][1]==ia && tabuleiro[k][2]==0) ||
                       (tabuleiro[k][0]==ia && tabuleiro[k][2]==ia && tabuleiro[k][1]==0) ||
                       (tabuleiro[k][1]==ia && tabuleiro[k][2]==ia && tabuleiro[k][0]==0)){
                        ameaca++;
                    }
                }
                for(int k = 0; k < 3; k++) {
                    if((tabuleiro[0][k]==ia && tabuleiro[1][k]==ia && tabuleiro[2][k]==0) ||
                       (tabuleiro[0][k]==ia && tabuleiro[2][k]==ia && tabuleiro[1][k]==0) ||
                       (tabuleiro[1][k]==ia && tabuleiro[2][k]==ia && tabuleiro[0][k]==0)){
                        ameaca++;
                    }
                }
                if((tabuleiro[0][0]==ia && tabuleiro[1][1]==ia && tabuleiro[2][2]==0) ||
                   (tabuleiro[0][0]==ia && tabuleiro[2][2]==ia && tabuleiro[1][1]==0) ||
                   (tabuleiro[1][1]==ia && tabuleiro[2][2]==ia && tabuleiro[0][0]==0)){
                    ameaca++;
                }
                if((tabuleiro[0][2]==ia && tabuleiro[1][1]==ia && tabuleiro[2][0]==0) ||
                   (tabuleiro[0][2]==ia && tabuleiro[2][0]==ia && tabuleiro[1][1]==0) ||
                   (tabuleiro[1][1]==ia && tabuleiro[2][0]==ia && tabuleiro[0][2]==0)){ 
                    ameaca++;
                }
                tabuleiro[i][j] = 0; // Desfaz a simulação antes de marcar oficial
                if(ameaca >= 2){
                    marcaJogada(tab, i, j, ia);
                    return;
                }
            }
        }
    }

    // Quando o quadrado ta sozinho ele marca
    if (tabuleiro[1][1] == 0){
        marcaJogada(tab, 1, 1, ia); return;
    }

    // Marca o oposto ao jogado pela pessoa
    if (tabuleiro[0][0] == jogador && tabuleiro[2][2] == 0){
        marcaJogada(tab, 2, 2, ia); return;
    }
    else if (tabuleiro[0][2] == jogador && tabuleiro[2][0] == 0){
        marcaJogada(tab, 2, 0, ia); return;
    }
    else if (tabuleiro[2][0] == jogador && tabuleiro[0][2] == 0){
        marcaJogada(tab, 0, 2, ia); return;
    }
    else if (tabuleiro[2][2] == jogador && tabuleiro[0][0] == 0){
        marcaJogada(tab, 0, 0, ia); return;
    }

    // R5: Se houver um canto vazio, marque-o
    if (tabuleiro[0][0] == 0){
        marcaJogada(tab, 0, 0, ia); return;
    }
    else if (tabuleiro[0][2] == 0){
        marcaJogada(tab, 0, 2, ia); return;
    }
    else if (tabuleiro[2][0] == 0){
        marcaJogada(tab, 2, 0, ia); return;
    }
    else if (tabuleiro[2][2] == 0){
        marcaJogada(tab, 2, 2, ia); return;
    }

    // Marca o quadrado vazio
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (tabuleiro[i][j] == 0){
                marcaJogada(tab, i, j, ia);
                return;
            }
        }
    }
}

#endif