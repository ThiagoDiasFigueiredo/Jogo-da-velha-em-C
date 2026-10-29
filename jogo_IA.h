#include <stdio.h>
#include <stdlib.h>
#include "tabuleiro.h"
#include <time.h>

void jogabilidade_IA(int tabuleiro[3][3],int jogada_usuario, int jogador, int ia){
    int ameaca;

    //Marcação no quadrado faltando para gerar uma linha para ganhar 
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == ia && tabuleiro[i][1] == ia && tabuleiro[i][2] == 0){
            tabuleiro[i][2] = ia;
            return;
        }
        else if (tabuleiro[i][0] == ia && tabuleiro[i][2] == ia && tabuleiro[i][1] == 0){
            tabuleiro[i][1] = ia;
            return;
        }
        else if (tabuleiro[i][1] == ia && tabuleiro[i][2] == ia && tabuleiro[i][0] == 0){
            tabuleiro[i][0] = ia;
            return;
        }
    }
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[0][i] == ia && tabuleiro[1][i] == ia && tabuleiro[2][i] == 0){
            tabuleiro[2][i] = ia;
            return;
        }
        else if (tabuleiro[0][i] == ia && tabuleiro[2][i] == ia && tabuleiro[1][i] == 0){
            tabuleiro[1][i] = ia;
            return;
        }
        else if (tabuleiro[1][i] == ia && tabuleiro[2][i] == ia && tabuleiro[0][i] == 0){
            tabuleiro[0][i] = ia;
            return;
        }
    }
    if (tabuleiro[0][0] == ia && tabuleiro[1][1] == ia && tabuleiro[2][2] == 0){
        tabuleiro[2][2] = ia;
            return;
    }
    else if (tabuleiro[0][0] == ia && tabuleiro[2][2] == ia && tabuleiro[1][1] == 0){
        tabuleiro[1][1] = ia;
            return;
    }
    else if (tabuleiro[1][1] == ia && tabuleiro[2][2] == ia && tabuleiro[0][0] == 0){
        tabuleiro[0][0] = ia;
            return;
    }
    
    else if (tabuleiro[0][2] == ia && tabuleiro[1][1] == ia && tabuleiro[2][0] == 0){
        tabuleiro[2][0] = ia;
            return;
    }
    else if (tabuleiro[0][2] == ia && tabuleiro[2][0] == ia && tabuleiro[1][1] == 0){
        tabuleiro[1][1] = ia;
            return;
    }
    else if (tabuleiro[1][1] == ia && tabuleiro[2][0] == ia && tabuleiro[0][2] == 0){
        tabuleiro[0][2] = ia;
            return;
    }


    //marcação de um quadrado para tentar impedir com que meu adversário ganhe
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == 0){
            tabuleiro[i][2] = ia;
            return;
        }
        else if (tabuleiro[i][0] == jogador && tabuleiro[i][2] == jogador && tabuleiro[i][1] == 0){
            tabuleiro[i][1] = ia;
            return;
        }
        else if (tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador && tabuleiro[i][0] == 0){
            tabuleiro[i][0] = ia;
            return;
        }
    }
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[0][i] == jogador && tabuleiro[1][i] == jogador && tabuleiro[2][i] == 0){
            tabuleiro[2][i] = ia;
            return;
        }
        else if (tabuleiro[0][i] == jogador && tabuleiro[2][i] == jogador && tabuleiro[1][i] == 0){
            tabuleiro[1][i] = ia;
            return;
        }
        else if (tabuleiro[1][i] == jogador && tabuleiro[2][i] == jogador && tabuleiro[0][i] == 0){
            tabuleiro[0][i] = ia;
            return;
        }
    }
    if (tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == 0){
        tabuleiro[2][2] = ia;
            return;
    }
    else if (tabuleiro[0][0] == jogador && tabuleiro[2][2] == jogador && tabuleiro[1][1] == 0){
        tabuleiro[1][1] = ia;
            return;
    }
    else if (tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador && tabuleiro[0][0] == 0){
        tabuleiro[0][0] = ia;
            return;
    }
    
    else if (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == 0){
        tabuleiro[2][0] = ia;
            return;
    }
    else if (tabuleiro[0][2] == jogador && tabuleiro[2][0] == jogador && tabuleiro[1][1] == 0){
        tabuleiro[1][1] = ia;
            return;
    }
    else if (tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador && tabuleiro[0][2] == 0){
        tabuleiro[0][2] = ia;
            return;
    
    }


    //Marca uma opção para que a IA possa gerar 2 ameaças de matar o jogo, deixando o jogador em uma enrascada
    for (int i = 0; i<3; i++){
        for (int j = 0; j<3; j++){
            if (tabuleiro[i][j] == 0){
                tabuleiro[i][j] = ia;
                ameaca = 0;
                for(int k=0; k<3; k++) {
                    if((tabuleiro[k][0]==ia && tabuleiro[k][1]==ia && tabuleiro[k][2]==0) ||
                       (tabuleiro[k][0]==ia && tabuleiro[k][2]==ia && tabuleiro[k][1]==0) ||
                       (tabuleiro[k][1]==ia && tabuleiro[k][2]==ia && tabuleiro[k][0]==0)){
                        ameaca++;
                       }
                }
                for(int k=0; k<3; k++) {
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
                if(ameaca >=2){
                    return;
                }
                else{
                    tabuleiro[i][j] = 0;
                }
            }
        }
    }


    //Marca o centro
    if (tabuleiro[1][1] == 0){
        tabuleiro[1][1] = ia;
            return;
    }


    //Marca o lado oposto ao que o adversário marcou
    else if (jogada_usuario == 1 && tabuleiro[2][2] == 0){
        tabuleiro[2][2] = ia;
            return;
    }
    else if(jogada_usuario == 2 && tabuleiro [2][1] == 0){
        tabuleiro[2][1] = ia;
            return;
    }
    else if(jogada_usuario == 3 && tabuleiro [2][0] == 0){
        tabuleiro[2][0] = ia;
            return;
    }
    else if(jogada_usuario == 4 && tabuleiro [1][2] == 0){
        tabuleiro[1][2] = ia;
            return;
    }        
    else if(jogada_usuario == 6 && tabuleiro [1][0] == 0){
        tabuleiro[1][0] = ia;
            return;
    }        
    else if(jogada_usuario == 7 && tabuleiro [0][2] == 0){
        tabuleiro[0][2] = ia;
            return;
    }        
    else if(jogada_usuario == 8 && tabuleiro [0][1] == 0){
        tabuleiro[0][1] = ia;
            return;
    }
    else if(jogada_usuario == 9 && tabuleiro [0][0] == 0){
        tabuleiro[0][0] = ia;
            return;
    } 


    //marca as pontas
    else if(tabuleiro [0][0] == 0){
        tabuleiro [0][0] = ia;
            return;
    }
    else if(tabuleiro [0][2] == 0){
        tabuleiro [0][2] = ia;
            return;
    }
    else if(tabuleiro [2][0] == 0){
        tabuleiro [2][0] = ia;
            return;
    }
    else if(tabuleiro [2][2] == 0){
        tabuleiro [2][2] = ia;
            return;
    }    


    //marca oque está faltando
    for (int i = 0; i<3;i++){
        for (int j = 0; j<3; j++){
            if (tabuleiro[i][j] == 0){
                tabuleiro[i][j] = ia;
                return;
            }
        }
    }
    
}

int jogador_X_IA(int jogador){
    srand(time(NULL));
    int sorteio = rand() % 2, tabuleiro[3][3],jogada_usuario, cont = 9,ia;
    if (jogador ==4){
        ia = 1;
    }
    else{
        ia = 4;
    }

    Criartabuleiro(tabuleiro);
    imprimirTabuleiro(tabuleiro);
    
    if (sorteio == 0){
        puts("O jogador vai comecar\n");
        while(1){
            printf("Digite a posicao que deseja jogar: ");
            if (scanf("%d", &jogada_usuario)!=1){
                puts("\nEssa jogada foi invalida\n");
                buffer();
                continue;
            }
            if ((jogada_usuario<1)||
                (jogada_usuario>9)){
                    puts("Essa jogada foi invalida\n");
                    continue;
                }
            else{
                tabuleiro[(jogada_usuario-1)/3][(jogada_usuario-1)%3] = jogador;
                break;
            }
        }
        jogabilidade_IA(tabuleiro, jogada_usuario, jogador, ia);

        imprimirTabuleiro(tabuleiro);
    }
    else{
        puts("A IA vai comecar\n");
        tabuleiro[1][1] = ia;
        imprimirTabuleiro(tabuleiro);
    }
    while (cont > 0){
            printf("Digite a posicao que deseja jogar: ");
            if (scanf("%d", &jogada_usuario)!=1){
                puts("\nEssa jogada foi invalida\n");
                buffer();
                continue;
            }
            if((jogada_usuario<1)||
                (jogada_usuario>9)){
                    puts("Essa jogada nao foi valida\n");
                    continue;
                }
            else if (tabuleiro[(jogada_usuario-1)/3][(jogada_usuario-1)%3] == 0){
                tabuleiro[(jogada_usuario-1)/3][(jogada_usuario-1)%3] = jogador;
            }
            else{
                puts("Essa jogada nao foi valida\n");
                continue;
            }

        //verifica se o usuario venceu  de a ia jogar
        if ((tabuleiro[0][0] == jogador && tabuleiro[0][1] == jogador && tabuleiro[0][2] == jogador)||
            (tabuleiro[1][0] == jogador && tabuleiro[1][1] ==jogador && tabuleiro[1][2] == jogador)||
            (tabuleiro[2][0] ==jogador && tabuleiro[2][1] ==jogador && tabuleiro[2][2] == jogador)||
            (tabuleiro[0][0] ==jogador && tabuleiro[1][0] ==jogador && tabuleiro[2][0] == jogador)||
            (tabuleiro[0][1] ==jogador && tabuleiro[1][1] ==jogador && tabuleiro[2][1] == jogador)||
            (tabuleiro[0][2] ==jogador && tabuleiro[1][2] ==jogador && tabuleiro[2][2] == jogador)||
            (tabuleiro[0][0] ==jogador && tabuleiro[1][1] ==jogador && tabuleiro[2][2] == jogador)||
            (tabuleiro[0][2] ==jogador && tabuleiro[1][1] ==jogador && tabuleiro[2][0] == jogador)){
                imprimirTabuleiro(tabuleiro);   // mostra a sua jogada vencedora
                if(jogador == VALOR_O){
                    puts(" " VERDE "VOCE VENCEU!\n" RESET " ");
                break;
                } else {
                    puts(" " VERMELHO "VOCE VENCEU!\n" RESET " ");
                break;
                }
                
            }

        jogabilidade_IA(tabuleiro, jogada_usuario, jogador,ia);
        
        imprimirTabuleiro(tabuleiro);

        if ((tabuleiro[0][0] ==ia && tabuleiro[0][1] ==ia && tabuleiro[0][2] == ia)||
            (tabuleiro[1][0] ==ia && tabuleiro[1][1] ==ia && tabuleiro[1][2] == ia)||
            (tabuleiro[2][0] ==ia &&  tabuleiro[2][1] ==ia &&  tabuleiro[2][2] == ia)||
            (tabuleiro[0][0] ==ia &&  tabuleiro[1][0] ==ia &&  tabuleiro[2][0] == ia)||
            (tabuleiro[0][1] ==ia &&  tabuleiro[1][1] ==ia &&  tabuleiro[2][1] == ia)||
            (tabuleiro[0][2] ==ia &&  tabuleiro[1][2] ==ia &&  tabuleiro[2][2] == ia)||
            (tabuleiro[0][0] ==ia &&  tabuleiro[1][1] ==ia &&  tabuleiro[2][2] == ia)||
            (tabuleiro[0][2] ==ia &&  tabuleiro[1][1] ==ia &&  tabuleiro[2][0] == ia)){
                if(ia == VALOR_O){
                    puts(" " VERDE "A IA GANHOU!\n" RESET " ");
                    break;
                } else {
                    puts(" " VERMELHO "A IA GANHOU!\n" RESET " ");
                    break;
                }
                
            }        

        cont = 0;
        for (int i = 0; i<3;i++){
            for (int j = 0; j<3;j++){
                if (tabuleiro[i][j] == 0){
                    cont++;
                }
            }  
        }
        if (cont == 0){
            puts(" " AMARELO "EMPATE!\n" RESET " ");
            break;
        }  
    }
    return 0;
}