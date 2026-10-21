#include <stdio.h>
#include "tabuleiro.h"
#include "configurajogadores.h"
#include "jogo.h"
#include "menu.h"
int main(){
    int tabuleiro[3][3];
    Criartabuleiro(tabuleiro);
    int escolha = menu();
    int primeiro = configuraJogadores();
    jogo(tabuleiro,primeiro,escolha);
}