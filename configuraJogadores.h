#ifndef CONFIGURAJOGADORES_H
#define CONFIGURAJOGADORES_H

#include <stdio.h>
#include <stdlib.h>
#include "tabuleiro.h"

int configuraJogadores(){
    int escolha;
    
    while(1){
        printf("Digite 1 para X e 2 para O: ");
        int lido = scanf("%d", &escolha);
        
        if(lido != 1){ //1 é True e 0 é false (binário)
            buffer();
            printf("Escolha invalida!\n"); //isso significa que o usuário não digitou um número
            continue;
        }
        if(escolha == 1){
            return VALOR_X;
        }
        if(escolha == 2){
            return VALOR_O;
        }
        printf("Escolha inválida!\n");
    }
}

#endif