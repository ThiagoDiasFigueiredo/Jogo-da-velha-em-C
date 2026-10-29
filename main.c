#include <stdio.h>
#include "tabuleiro.h"
#include "configurajogadores.h"
#include "jogo.h"
#include "menu.h"
#include "jogo_IA.h"

int main(){
    int escolha = menu();
     int tabuleiro[3][3];
    if(escolha == 1){
        
        Criartabuleiro(tabuleiro);
    
        int primeiro = configuraJogadores();
        jogo(tabuleiro,primeiro);

    } 
    else if (escolha == 2){

        int jogador =configuraJogadores();
        jogador_X_IA(jogador);
    }
    
}
