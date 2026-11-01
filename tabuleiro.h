// arquivo: tabuleiro.h
#ifndef TABULEIRO_H
#define TABULEIRO_H

#include <stdio.h>
#include <stdlib.h>

//valores definidos para marcar
#define VALOR_VAZIO 0
#define VALOR_O 1
#define VALOR_X 4

// Cores
#define VERMELHO "\033[1;31m"
#define VERDE    "\033[1;32m"
#define AMARELO  "\033[1;33m"
#define RESET    "\033[0m"

typedef struct {
    int M[3][3];
} Tabuleiro;

void buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void limparTela() {
    printf("\033[2J\033[H");
}

char simbolo(int valor) {
    if (valor == VALOR_X) return 'X';
    if (valor == VALOR_O) return 'O';
    return ' ';
}


void inicializarTabuleiro(Tabuleiro *tab) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tab->M[i][j] = 0;
        }
    }
}

// desenha o tabuleiro
void desenha(Tabuleiro *tab) {
    limparTela();
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tab->M[i][j] == VALOR_X) {
                printf(" " VERMELHO "X" RESET " ");
            } else if (tab->M[i][j] == VALOR_O) {
                printf(" " VERDE "O" RESET " ");
            } else {
                printf(" %d ", i * 3 + j + 1);
            }
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("-----------\n");
    }
    printf("\n");
}

// + marcaJogada(x: int, y: int, tipo: int): void
void marcaJogada(Tabuleiro *tab, int x, int y, int tipo) {
    tab->M[x][y] = tipo;
}

int temVencedor(Tabuleiro *tab) {
    int combinacoes[8][3] = {
        {1, 2, 3}, {4, 5, 6}, {7, 8, 9},   // linhas 
        {1, 4, 7}, {2, 5, 8}, {3, 6, 9},   // colunas 
        {1, 5, 9}, {3, 5, 7}               // diagonais 
    };

    for (int i = 0; i < 8; i++) {
        int soma = 0;
        for (int j = 0; j < 3; j++) {
            int p = combinacoes[i][j] - 1;
            soma += tab->M[p / 3][p % 3];
        }
        if (soma == 12) {
            return 1; // X venceu
        } else if (soma == 3) {
            return 2; // O venceu
        }
    }
    return -1; // Ninguém ganhou ainda
}

#endif