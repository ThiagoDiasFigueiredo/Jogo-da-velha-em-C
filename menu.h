#ifndef MENU_H
#define MENU_H
#include <stdio.h>

int menu(){
    int opcoes;
    while(1){
        printf("[1] para jogar local: \n");
        printf("[2] para jogar com a IA: \n");
        printf("[3] para jogar online: \n");
        scanf("%d",&opcoes);
        if(opcoes != 1 && opcoes!=2 && opcoes != 3){
            printf("Escolha invalida!\n");
        }
        if(opcoes == 1){
            return 1;
            break;
        } else if (opcoes == 2)
        {
            return 2;
            break;
        } else if (opcoes == 3)
        {
            return 3;
            break;
        }
        
    }
}
#endif