#define TABULEIRO_H
#include <stdio.h>

void Criartabuleiro(int tabuleiro[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3;j++){
            tabuleiro[i][j] = 0;
        }
    }
}

char simbolo(int valor){
    int valor_O = 1;
    int valor_x = 4;
    if(valor == valor_O){
        return 'O';
    }
    if(valor == valor_x){
        return 'X';
    }
}

void imprimirTabuleiro(int tabuleiro[3][3]){
    int contador = 1;
    for(int i = 0; i < 3; i++){
       printf("\n");
       if(i > 0){
        printf("------------");
        printf("\n");
       }
        for(int j = 0;j < 3; j++){
            if(j > 0){
                printf("|");
            }
            printf(" %d ",contador);
            
            contador++;
        }
    }
}
