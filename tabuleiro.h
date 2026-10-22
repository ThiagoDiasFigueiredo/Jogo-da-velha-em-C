#ifndef TABULEIRO_H
#define TABULEIRO_H
#include <stdio.h>
#define VALOR_X 4
#define VALOR_O 1
#define RESET    "\033[0m"
#define VERMELHO "\033[31m"
#define VERDE    "\033[32m"
#define AMARELO  "\033[33m"

void buffer(){
    while(getchar() != '\n') { 
        
    }
}

void Criartabuleiro(int tabuleiro[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3;j++){
            tabuleiro[i][j] = 0;
        }
    }
}
int limparTela() {
 printf("\033[2J\033[H");
 return 0;
 
}
char simbolo(int valor){
    if(valor == VALOR_O){
        return 'O';
    }
    if(valor == VALOR_X){
        return 'X';
    }
    return ' ';
}

void imprimirTabuleiro(int tabuleiro[3][3]){
    
    int contador = 1;
    printf("\n");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(tabuleiro[i][j] == 0){
                printf(" %d ", contador);
            } else if(tabuleiro[i][j] == VALOR_X){
            printf(" " VERMELHO "X" RESET " ");
            } else {
            printf(" " VERDE "O" RESET " ");
            }
            if(j < 2){
                printf("|");
            }
            contador++;
        }
        printf("\n");
        if(i < 2){
            printf("-----------\n");
        }
    }
    printf("\n");
}

#endif