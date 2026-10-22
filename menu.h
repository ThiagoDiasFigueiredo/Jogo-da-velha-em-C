#ifndef MENU_H
#define MENU_H
#include <stdio.h>

int menu(){
    int opcoes;
    while(1){
        printf("[1] para jogar local: \n");
        printf("[2] para jogar com a IA: \n");
        printf("[3] para jogar online: \n");
        
        if(scanf("%d", &opcoes) != 1){          // digitou letra
        printf("Escolha invalida!\n");
        buffer();
        continue;
        
        }
        if(opcoes < 1 || opcoes > 3){           // número fora do menu
            printf("Escolha invalida! Digite 1, 2 ou 3.\n");
            buffer();
            continue;
        }

        else if(opcoes == 1){
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