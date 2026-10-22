#include <stdio.h>
#include <stdlib.h>
#include "tabuleiro.h"
#include <time.h>

void jogabilidade_IA(int tabuleiro[3][3],int jogada_usuario){
    int ameaca;

    //Marcação no quadrado faltando para gerar uma linha para ganhar 
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == 1 && tabuleiro[i][1] == 1 && tabuleiro[i][2] == 0){
            tabuleiro[i][2] = 1;
            return;
        }
        else if (tabuleiro[i][0] == 1 && tabuleiro[i][2] == 1 && tabuleiro[i][1] == 0){
            tabuleiro[i][1] = 1;
            return;
        }
        else if (tabuleiro[i][1] == 1 && tabuleiro[i][2] == 1 && tabuleiro[i][0] == 0){
            tabuleiro[i][0] = 1;
            return;
        }
    }
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[0][i] == 1 && tabuleiro[1][i] == 1 && tabuleiro[2][i] == 0){
            tabuleiro[2][i] = 1;
            return;
        }
        else if (tabuleiro[0][i] == 1 && tabuleiro[2][i] == 1 && tabuleiro[1][i] == 0){
            tabuleiro[1][i] = 1;
            return;
        }
        else if (tabuleiro[1][i] == 1 && tabuleiro[2][i] == 1 && tabuleiro[0][i] == 0){
            tabuleiro[0][i] = 1;
            return;
        }
    }
    if (tabuleiro[0][0] == 1 && tabuleiro[1][1] == 1 && tabuleiro[2][2] == 0){
        tabuleiro[2][2] = 1;
            return;
    }
    else if (tabuleiro[0][0] == 1 && tabuleiro[2][2] == 1 && tabuleiro[1][1] == 0){
        tabuleiro[1][1] = 1;
            return;
    }
    else if (tabuleiro[1][1] == 1 && tabuleiro[2][2] == 1 && tabuleiro[0][0] == 0){
        tabuleiro[0][0] = 1;
            return;
    }
    
    else if (tabuleiro[0][2] == 1 && tabuleiro[1][1] == 1 && tabuleiro[2][0] == 0){
        tabuleiro[2][0] = 1;
            return;
    }
    else if (tabuleiro[0][2] == 1 && tabuleiro[2][0] == 1 && tabuleiro[1][1] == 0){
        tabuleiro[1][1] = 1;
            return;
    }
    else if (tabuleiro[1][1] == 1 && tabuleiro[2][0] == 1 && tabuleiro[0][2] == 0){
        tabuleiro[0][2] = 1;
            return;
    }


    //marcação de um quadrado para tentar impedir com que meu adversário ganhe
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == 4 && tabuleiro[i][1] == 4 && tabuleiro[i][2] == 0){
            tabuleiro[i][2] = 1;
            return;
        }
        else if (tabuleiro[i][0] == 4 && tabuleiro[i][2] == 4 && tabuleiro[i][1] == 0){
            tabuleiro[i][1] = 1;
            return;
        }
        else if (tabuleiro[i][1] == 4 && tabuleiro[i][2] == 4 && tabuleiro[i][0] == 0){
            tabuleiro[i][0] = 1;
            return;
        }
    }
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[0][i] == 4 && tabuleiro[1][i] == 4 && tabuleiro[2][i] == 0){
            tabuleiro[2][i] = 1;
            return;
        }
        else if (tabuleiro[0][i] == 4 && tabuleiro[2][i] == 4 && tabuleiro[1][i] == 0){
            tabuleiro[1][i] = 1;
            return;
        }
        else if (tabuleiro[1][i] == 4 && tabuleiro[2][i] == 4 && tabuleiro[0][i] == 0){
            tabuleiro[0][i] = 1;
            return;
        }
    }
    if (tabuleiro[0][0] == 4 && tabuleiro[1][1] == 4 && tabuleiro[2][2] == 0){
        tabuleiro[2][2] = 1;
            return;
    }
    else if (tabuleiro[0][0] == 4 && tabuleiro[2][2] == 4 && tabuleiro[1][1] == 0){
        tabuleiro[1][1] = 1;
            return;
    }
    else if (tabuleiro[1][1] == 4 && tabuleiro[2][2] == 4 && tabuleiro[0][0] == 0){
        tabuleiro[0][0] = 1;
            return;
    }
    
    else if (tabuleiro[0][2] == 4 && tabuleiro[1][1] == 4 && tabuleiro[2][0] == 0){
        tabuleiro[2][0] = 1;
            return;
    }
    else if (tabuleiro[0][2] == 4 && tabuleiro[2][0] == 4 && tabuleiro[1][1] == 0){
        tabuleiro[1][1] = 1;
            return;
    }
    else if (tabuleiro[1][1] == 4 && tabuleiro[2][0] == 4 && tabuleiro[0][2] == 0){
        tabuleiro[0][2] = 1;
            return;
    
    }


    //Marca uma opção para que a IA possa gerar 2 ameaças de matar o jogo, deixando o jogador em uma enrascada
    for (int i = 0; i<3; i++){
        for (int j = 0; j<3; j++){
            if (tabuleiro[i][j] == 0){
                tabuleiro[i][j] = 1;
                ameaca = 0;
                for(int k=0; k<3; k++) {
                    if((tabuleiro[k][0]==1 && tabuleiro[k][1]==1 && tabuleiro[k][2]==0) ||
                       (tabuleiro[k][0]==1 && tabuleiro[k][2]==1 && tabuleiro[k][1]==0) ||
                       (tabuleiro[k][1]==1 && tabuleiro[k][2]==1 && tabuleiro[k][0]==0)){
                        ameaca++;
                       }
                }
                for(int k=0; k<3; k++) {
                    if((tabuleiro[0][k]==1 && tabuleiro[1][k]==1 && tabuleiro[2][k]==0) ||
                       (tabuleiro[0][k]==1 && tabuleiro[2][k]==1 && tabuleiro[1][k]==0) ||
                       (tabuleiro[1][k]==1 && tabuleiro[2][k]==1 && tabuleiro[0][k]==0)){
                        ameaca++;
                       }
                }
                if((tabuleiro[0][0]==1 && tabuleiro[1][1]==1 && tabuleiro[2][2]==0) ||
                   (tabuleiro[0][0]==1 && tabuleiro[2][2]==1 && tabuleiro[1][1]==0) ||
                   (tabuleiro[1][1]==1 && tabuleiro[2][2]==1 && tabuleiro[0][0]==0)){
                    ameaca++;
                   }
                if((tabuleiro[0][2]==1 && tabuleiro[1][1]==1 && tabuleiro[2][0]==0) ||
                   (tabuleiro[0][2]==1 && tabuleiro[2][0]==1 && tabuleiro[1][1]==0) ||
                   (tabuleiro[1][1]==1 && tabuleiro[2][0]==1 && tabuleiro[0][2]==0)){ 
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
        tabuleiro[1][1] = 1;
            return;
    }


    //Marca o lado oposto ao que o adversário marcou
    else if (jogada_usuario == 1 && tabuleiro[2][2] == 0){
        tabuleiro[2][2] = 1;
            return;
    }
    else if(jogada_usuario == 2 && tabuleiro [2][1] == 0){
        tabuleiro[2][1] = 1;
            return;
    }
    else if(jogada_usuario == 3 && tabuleiro [2][0] == 0){
        tabuleiro[2][0] = 1;
            return;
    }
    else if(jogada_usuario == 4 && tabuleiro [1][2] == 0){
        tabuleiro[1][2] = 1;
            return;
    }        
    else if(jogada_usuario == 6 && tabuleiro [1][0] == 0){
        tabuleiro[1][0] = 1;
            return;
    }        
    else if(jogada_usuario == 7 && tabuleiro [0][2] == 0){
        tabuleiro[0][2] = 1;
            return;
    }        
    else if(jogada_usuario == 8 && tabuleiro [0][1] == 0){
        tabuleiro[0][1] = 1;
            return;
    }
    else if(jogada_usuario == 9 && tabuleiro [0][0] == 0){
        tabuleiro[0][0] = 1;
            return;
    } 


    //marca as pontas
    else if(tabuleiro [0][0] == 0){
        tabuleiro [0][0] = 1;
            return;
    }
    else if(tabuleiro [0][2] == 0){
        tabuleiro [0][2] = 1;
            return;
    }
    else if(tabuleiro [2][0] == 0){
        tabuleiro [2][0] = 1;
            return;
    }
    else if(tabuleiro [2][2] == 0){
        tabuleiro [2][2] = 1;
            return;
    }    


    //marca oque está faltando
    for (int i = 0; i<3;i++){
        for (int j = 0; j<3; j++){
            if (tabuleiro[i][j] == 0){
                tabuleiro[i][j] = 1;
                return;
            }
        }
    }
    
}

int jogador_X_IA(){
    srand(time(NULL));
    int sorteio = rand() % 2, tabuleiro[3][3],jogada_usuario, cont = 9;
    Criartabuleiro(tabuleiro);
    imprimirTabuleiro(tabuleiro);
    
    if (sorteio == 0){
        puts("O jogador vai comecar\n");
        while(1){
            printf("Digite a posicao que deseja jogar: ");
            if (scanf("%d", &jogada_usuario)!=1){
                puts("\nEssa jogada foi invalida\n");
                int c;
                while((c = getchar()) != '\n' && c!= EOF);
                continue;
            }
            if ((jogada_usuario<1)||
                (jogada_usuario>9)){
                    puts("Essa jogada foi invalida\n");
                    continue;
                }
            else{
                tabuleiro[(jogada_usuario-1)/3][(jogada_usuario-1)%3] = 4;
                break;
            }
        }
        jogabilidade_IA(tabuleiro, jogada_usuario);

        imprimirTabuleiro(tabuleiro);
    }
    else{
        puts("A IA vai comecar\n");
        tabuleiro[1][1] = 1;
        imprimirTabuleiro(tabuleiro);
    }
    while (cont > 0){
            printf("Digite a posicao que deseja jogar: ");
            if (scanf("%d", &jogada_usuario)!=1){
                puts("\nEssa jogada foi invalida\n");
                int c;
                while((c = getchar()) != '\n' && c!= EOF);
                continue;
            }
            if((jogada_usuario<1)||
                (jogada_usuario>9)){
                    puts("Essa jogada nao foi valida\n");
                    continue;
                }
            else if (tabuleiro[(jogada_usuario-1)/3][(jogada_usuario-1)%3] == 0){
                tabuleiro[(jogada_usuario-1)/3][(jogada_usuario-1)%3] = 4;
            }
            else{
                puts("Essa jogada nao foi valida\n");
                continue;
            }

        //verifica se o usuario venceu  de a ia jogar
        if ((tabuleiro[0][0] == 4 && tabuleiro[0][1] == 4 && tabuleiro[0][2] == 4)||
            (tabuleiro[1][0] == 4 && tabuleiro[1][1] ==4 && tabuleiro[1][2] == 4)||
            (tabuleiro[2][0] ==4 && tabuleiro[2][1] ==4 && tabuleiro[2][2] == 4)||
            (tabuleiro[0][0] ==4 && tabuleiro[1][0] ==4 && tabuleiro[2][0] == 4)||
            (tabuleiro[0][1] ==4 && tabuleiro[1][1] ==4 && tabuleiro[2][1] == 4)||
            (tabuleiro[0][2] ==4 && tabuleiro[1][2] ==4 && tabuleiro[2][2] == 4)||
            (tabuleiro[0][0] ==4 && tabuleiro[1][1] ==4 && tabuleiro[2][2] == 4)||
            (tabuleiro[0][2] ==4 && tabuleiro[1][1] ==4 && tabuleiro[2][0] == 4)){
                imprimirTabuleiro(tabuleiro);   // mostra a sua jogada vencedora
                puts("Voce ganhou!\n");
                break;
            }

        jogabilidade_IA(tabuleiro, jogada_usuario);
        
        imprimirTabuleiro(tabuleiro);

        if ((tabuleiro[0][0] ==1 && tabuleiro[0][1] ==1 && tabuleiro[0][2] == 1)||
            (tabuleiro[1][0] ==1 && tabuleiro[1][1] ==1 && tabuleiro[1][2] == 1)||
            (tabuleiro[2][0] ==1 &&  tabuleiro[2][1] ==1 &&  tabuleiro[2][2] == 1)||
            (tabuleiro[0][0] ==1 &&  tabuleiro[1][0] ==1 &&  tabuleiro[2][0] == 1)||
            (tabuleiro[0][1] ==1 &&  tabuleiro[1][1] ==1 &&  tabuleiro[2][1] == 1)||
            (tabuleiro[0][2] ==1 &&  tabuleiro[1][2] ==1 &&  tabuleiro[2][2] == 1)||
            (tabuleiro[0][0] ==1 &&  tabuleiro[1][1] ==1 &&  tabuleiro[2][2] == 1)||
            (tabuleiro[0][2] ==1 &&  tabuleiro[1][1] ==1 &&  tabuleiro[2][0] == 1)){
                puts("A IA ganhou!\n");
                break;
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
            puts("O jogo foi empatado\n");
            break;
        }  
    } 
    return 0;
}