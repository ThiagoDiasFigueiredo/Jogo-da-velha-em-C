#include <stdio.h>
#include "tabuleiro.h"
#include "configurajogadores.h"
#include "jogo.h"

int main(){
    int tabuleiro[3][3];
    Criartabuleiro(tabuleiro);
    int primeiro = configuraJogadores();
    jogo(tabuleiro,primeiro);
}