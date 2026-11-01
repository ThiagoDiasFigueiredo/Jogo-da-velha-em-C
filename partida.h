// arquivo: partida.h
#ifndef PARTIDA_H
#define PARTIDA_H

#include <stdio.h>
#include "tabuleiro.h"
#include "menu.h"
#include "jogador_teclado.h"
#include "jogadorIA.h"

typedef struct {
    Tabuleiro tab;
    JogadorTeclado jog1;
    JogadorTeclado jog2;
    JogadorIA ia;
    int modo; // 1 = Local, 2 = IA, 3 = Online
} Partida;

void configuraJogadores(Partida *p) {
    p->modo = menu();
    int escolha;

    while (1) {
        printf("Digite 1 para " VERMELHO "X" RESET " e 2 para " VERDE "O" RESET ": ");
        int lido = scanf("%d", &escolha);
        
        if (lido != 1) {
            buffer();
            printf("Escolha invalida!\n");
            continue;
        }
        if (escolha == 1) {
            p->jog1.tipo = VALOR_X;
            p->jog2.tipo = VALOR_O;
            p->ia.tipo   = VALOR_O;
            break;
        }
        if (escolha == 2) {
            p->jog1.tipo = VALOR_O;
            p->jog2.tipo = VALOR_X;
            p->ia.tipo   = VALOR_X;
            break;
        }
        printf("Escolha invalida!\n");
    }
}

void inicia(Partida *p) {
    int rodada = 0;
    int vencedor = -1;

    inicializarTabuleiro(&p->tab);
    desenha(&p->tab);

    while (rodada != 9 && vencedor == -1) {
        printf("Rodada %d\n", rodada + 1);

        if (rodada % 2 == 0) {
            jogaTeclado(&p->jog1, &p->tab);

        } else {
            if (p->modo == 1) {
                jogaTeclado(&p->jog2, &p->tab);
            } else if (p->modo == 2) {
                jogaIA(&p->ia, &p->tab);
            }
        }

        rodada++;
        desenha(&p->tab);
        vencedor = temVencedor(&p->tab);
    }

    if (vencedor == 1) {
        printf(" " VERMELHO "JOGADOR X VENCEU!\n" RESET " ");
    } else if (vencedor == 2) {
        printf(" " VERDE "JOGADOR O VENCEU!\n" RESET " ");
    } else {
        printf(" " AMARELO "EMPATE!\n" RESET " ");
    }
}

#endif