// arquivo: main.c
#include <stdio.h>
#include "partida.h"

int main() {

    Partida partida;
      
    configuraJogadores(&partida);
    inicia(&partida);

    return 0;
}