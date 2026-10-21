#include <stdio.h>
#include <stdlib.h>
#include "tabuleiro.h"

void jogabilidade_IA(int tabuleiro[3][3],int jogada_usuario){
    
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == 'O' && tabuleiro[i][1] == 'O' && tabuleiro[i][2] == '0'){
            tabuleiro[i][2] = 'O';
            return;
        }
        else if (tabuleiro[i][0] == 'O' && tabuleiro[i][2] == 'O' && tabuleiro[i][1] == '0'){
            tabuleiro[i][1] = 'O';
            return;
        }
        else if (tabuleiro[i][1] == 'O' && tabuleiro[i][2] == 'O' && tabuleiro[i][0] == '0'){
            tabuleiro[i][0] = 'O';
            return;
        }
    }
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[0][i] == 'O' && tabuleiro[1][i] == 'O' && tabuleiro[2][i] == '0'){
            tabuleiro[2][i] = 'O';
            return;
        }
        else if (tabuleiro[0][i] == 'O' && tabuleiro[2][i] == 'O' && tabuleiro[1][i] == '0'){
            tabuleiro[1][i] = 'O';
            return;
        }
        else if (tabuleiro[1][i] == 'O' && tabuleiro[2][i] == 'O' && tabuleiro[0][i] == '0'){
            tabuleiro[0][i] = 'O';
            return;
        }
    }
    if (tabuleiro[0][0] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[2][2] == '0'){
        tabuleiro[2][2] = 'O';
            return;
    }
    else if (tabuleiro[0][0] == 'O' && tabuleiro[2][2] == 'O' && tabuleiro[1][1] == '0'){
        tabuleiro[1][1] = 'O';
            return;
    }
    else if (tabuleiro[1][1] == 'O' && tabuleiro[2][2] == 'O' && tabuleiro[0][0] == '0'){
        tabuleiro[0][0] = 'O';
            return;
    }
    
    else if (tabuleiro[0][2] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[2][0] == '0'){
        tabuleiro[2][0] = 'O';
            return;
    }
    else if (tabuleiro[0][2] == 'O' && tabuleiro[2][0] == 'O' && tabuleiro[1][1] == '0'){
        tabuleiro[1][1] = 'O';
            return;
    }
    else if (tabuleiro[1][1] == 'O' && tabuleiro[2][0] == 'O' && tabuleiro[0][2] == '0'){
        tabuleiro[0][2] = 'O';
            return;
    }



    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == 'X' && tabuleiro[i][1] == 'X' && tabuleiro[i][2] == '0'){
            tabuleiro[i][2] = 'O';
            return;
        }
        else if (tabuleiro[i][0] == 'X' && tabuleiro[i][2] == 'X' && tabuleiro[i][1] == '0'){
            tabuleiro[i][1] = 'O';
            return;
        }
        else if (tabuleiro[i][1] == 'X' && tabuleiro[i][2] == 'X' && tabuleiro[i][0] == '0'){
            tabuleiro[i][0] = 'O';
            return;
        }
    }
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[0][i] == 'X' && tabuleiro[1][i] == 'X' && tabuleiro[2][i] == '0'){
            tabuleiro[2][i] = 'O';
            return;
        }
        else if (tabuleiro[0][i] == 'X' && tabuleiro[2][i] == 'X' && tabuleiro[1][i] == '0'){
            tabuleiro[1][i] = 'O';
            return;
        }
        else if (tabuleiro[1][i] == 'X' && tabuleiro[2][i] == 'X' && tabuleiro[0][i] == '0'){
            tabuleiro[0][i] = 'O';
            return;
        }
    }
    if (tabuleiro[0][0] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[2][2] == '0'){
        tabuleiro[2][2] = 'O';
            return;
    }
    else if (tabuleiro[0][0] == 'X' && tabuleiro[2][2] == 'X' && tabuleiro[1][1] == '0'){
        tabuleiro[1][1] = 'O';
            return;
    }
    else if (tabuleiro[1][1] == 'X' && tabuleiro[2][2] == 'X' && tabuleiro[0][0] == '0'){
        tabuleiro[0][0] = 'O';
            return;
    }
    
    else if (tabuleiro[0][2] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[2][0] == '0'){
        tabuleiro[2][0] = 'O';
            return;
    }
    else if (tabuleiro[0][2] == 'X' && tabuleiro[2][0] == 'X' && tabuleiro[1][1] == '0'){
        tabuleiro[1][1] = 'O';
            return;
    }
    else if (tabuleiro[1][1] == 'X' && tabuleiro[2][0] == 'X' && tabuleiro[0][2] == '0'){
        tabuleiro[0][2] = 'O';
            return;
    
    }



    else if (tabuleiro[1][1] == '0'){
        tabuleiro[1][1] = 'O';
            return;
    }



    else if (jogada_usuario == 1 && tabuleiro[2][2] == '0'){
        tabuleiro[2][2] = 'O';
            return;
    }
    else if(jogada_usuario == 2 && tabuleiro [2][1] == '0'){
        tabuleiro[2][1] = 'O';
            return;
    }
    else if(jogada_usuario == 3 && tabuleiro [2][0] == '0'){
        tabuleiro[2][0] = 'O';
            return;
    }
    else if(jogada_usuario == 4 && tabuleiro [1][2] == '0'){
        tabuleiro[1][2] = 'O';
            return;
    }        
    else if(jogada_usuario == 6 && tabuleiro [1][0] == '0'){
        tabuleiro[2][1] = 'O';
            return;
    }        
    else if(jogada_usuario == 7 && tabuleiro [0][2] == '0'){
        tabuleiro[0][2] = 'O';
            return;
    }        
    else if(jogada_usuario == 8 && tabuleiro [0][1] == '0'){
        tabuleiro[0][1] = 'O';
            return;
    }
    else if(jogada_usuario == 9 && tabuleiro [0][0] == '0'){
        tabuleiro[0][0] = 'O';
            return;
    } 



    else if(tabuleiro [0][0] == '0'){
        tabuleiro [0][0] = 'O';
            return;
    }
    else if(tabuleiro [0][2] == '0'){
        tabuleiro [0][2] = 'O';
            return;
    }
    else if(tabuleiro [2][0] == '0'){
        tabuleiro [2][0] = 'O';
            return;
    }
    else if(tabuleiro [2][2] == '0'){
        tabuleiro [2][2] = 'O';
            return;
    }    


    
    for (int i = 0; i<3;i++){
        for (int j = 0; j<3; j++){
            if (tabuleiro[i][j] == '0'){
                tabuleiro[i][j] = 'O';
                return;
            }
        }
    }
    
}
int jogador_X_IA(){
    int sorteio = rand() % 2, tabuleiro[3][3],jogada_usuario, cont = 9;
    Criartabuleiro(tabuleiro);
    imprimirTabuleiro(tabuleiro);

    if (sorteio == 0){
        puts("O jogador vai começar");
        printf("Digite a posição que deseja jogar: ");
        scanf("%d", &jogada_usuario);
        tabuleiro[(jogada_usuario-1)/3][(jogada_usuario-1)%3] = 'X';
        
        jogabilidade_IA(tabuleiro, jogada_usuario);

        imprimirTabuleiro(tabuleiro);
    }
    else{
        puts("A IA vai começar");
        tabuleiro[1][1] = 'O';
        imprimirTabuleiro(tabuleiro);
    }
    while (cont > 0){
        printf("Digite a posição que deseja jogar: ");
        scanf("%d", &jogada_usuario);
        tabuleiro[(jogada_usuario-1)/3][(jogada_usuario-1)%3] = 'X';

        jogabilidade_IA(tabuleiro, jogada_usuario);
        
        imprimirTabuleiro(tabuleiro);

        cont = 0;
        for (int i = 0; i<3;i++){
            for (int j = 0; j<3;j++){
                if (tabuleiro[i][j] == '0'){
                    cont++;
                }
            }
        }
    }
    return 0;
}