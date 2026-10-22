#include <stdio.h>
#include "tabuleiro.h"
#include "configurajogadores.h"
#include "jogo.h"
#include "menu.h"

int main(){
    int escolha = menu();
    if(escolha == 1){
        int tabuleiro[3][3];
        Criartabuleiro(tabuleiro);
    
        int primeiro = configuraJogadores();
        jogo(tabuleiro,primeiro);
    } else if (escolha == 2)
    {
        
        jogador_X_IA();
    }
    
}
