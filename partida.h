// arquivo: partida.h
#ifndef PARTIDA_H
#define PARTIDA_H

#include <stdio.h>
#include "tabuleiro.h"
#include "menu.h"
#include "jogador_teclado.h"
#include "jogadorIA.h"
#include "online.h" // Importa todas as funções e estruturas de rede que criamos anteriormente

typedef struct {
    Tabuleiro tab;
    JogadorTeclado jog1;
    JogadorTeclado jog2;
    JogadorIA ia;
    int modo;       // 1 = Local, 2 = IA, 3 = Online
    int ehServidor; // 1 = Servidor (X), 0 = Cliente (O)
} Partida;

void configuraJogadores(Partida *p) {
    p->modo = menu();

    // Se escolheu o modo Online (3), pergunta se quer ser Servidor ou Cliente
    if (p->modo == 3) {
        int opcao_rede;
        printf("\n[1] Criar Servidor (Voce e o X)\n");
        printf("[2] Conectar a um Servidor (Voce e o O)\n");
        printf("Escolha: ");
        scanf("%d", &opcao_rede);
        
        if (opcao_rede == 1) {
            p->ehServidor = 1;
        } else {
            p->ehServidor = 0;
        }
        return; 
    }

    // Escolha de símbolos para o modo Local ou IA
    int escolha;
    while (1) {
        printf("Digite 1 para " VERMELHO "X" RESET " e 2 para " VERDE "O" RESET ": ");
        int lido = scanf("%d", &escolha);
        
        if (lido != 1) {
            buffer();
            printf("Escolha invalida!\n");
            continue;
        }
        if (escolha == 1) {
            p->jog1.tipo = VALOR_X;
            p->jog2.tipo = VALOR_O;
            p->ia.tipo   = VALOR_O;
            break;
        }
        if (escolha == 2) {
            p->jog1.tipo = VALOR_O;
            p->jog2.tipo = VALOR_X;
            p->ia.tipo   = VALOR_X;
            break;
        }
        printf("Escolha invalida!\n");
    }
}

void inicia(Partida *p) {
    //modo online
    if (p->modo == 3) {
        JogadorRemoto remoto;
        inicializarTabuleiro(&p->tab);

        // Se for servidor, aceita a conexão. Se for cliente, pede o IP e conecta.
        if (p->ehServidor) {
            remoto.tipo = VALOR_O; 
            aceitaConexao(&remoto, 8888);
        } else {
            char ip[50];
            printf("Digite o IP do Servidor (ex: 127.0.0.1): ");
            scanf("%s", ip);
            remoto.tipo = VALOR_X; // O adversário remoto é o X
            conecta(&remoto, ip, 8888);
        }

        int rodada = 0;
        int vencedor = -1;
        desenha(&p->tab);

        while (rodada < 9 && vencedor == -1) {
            // Servidor joga nas pares (0, 2, 4...), Cliente nas ímpares (1, 3, 5...)
            int minhaVez = (p->ehServidor && rodada % 2 == 0) || (!p->ehServidor && rodada % 2 != 0);

            if (minhaVez) {
                int tipoLocal;
                char *simboloStr;

                if (p->ehServidor) {
                    tipoLocal = VALOR_X;
                    simboloStr = "X";
                } else {
                    tipoLocal = VALOR_O;
                    simboloStr = "O";
                }
                int posicao;

                while (1) {
                    printf("Sua vez (%s). Digite a posicao de 1 a 9: ", simboloStr);
                    if (scanf("%d", &posicao) != 1) {
                        printf("Entrada invalida!\n");
                        buffer();
                        continue;
                    }
                    if (posicao < 1 || posicao > 9) {
                        printf("Posicao invalida! Escolha de 1 a 9.\n");
                        continue;
                    }

                    int linha = (posicao - 1) / 3;
                    int coluna = (posicao - 1) % 3;

                    if (p->tab.M[linha][coluna] != 0) {
                        printf("Essa casa ja esta ocupada!\n");
                        continue;
                    }

                    marcaJogada(&p->tab, linha, coluna, tipoLocal);
                    enviaJogada(&remoto, posicao); // Função importada do online.h
                    break;
                }
            } else {
                // Aguarda a jogada do adversário via rede
                printf("Aguardando a jogada do adversario...\n");
                jogaRemoto(&remoto, &p->tab); // Função importada do online.h
            }

            rodada++;
            desenha(&p->tab);
            vencedor = temVencedor(&p->tab);
        }

        // Resultado Final Online
        if (vencedor == 1) {
            printf(" " VERMELHO "JOGADOR X VENCEU!\n" RESET " ");
        } else if (vencedor == 2) {
            printf(" " VERDE "JOGADOR O VENCEU!\n" RESET " ");
        } else {
            printf(" " AMARELO "EMPATE!\n" RESET " ");
        }

        fechaConexao(&remoto); // Função importada do online.h
        return;
    }

    //Modo local e IA
    int rodada = 0;
    int vencedor = -1;

    inicializarTabuleiro(&p->tab);
    desenha(&p->tab);

    while (rodada != 9 && vencedor == -1) {
        printf("Rodada %d\n", rodada + 1);

        if (rodada % 2 == 0) {
            jogaTeclado(&p->jog1, &p->tab);
        } else {
            if (p->modo == 1) {
                jogaTeclado(&p->jog2, &p->tab);
            } else if (p->modo == 2) {
                jogaIA(&p->ia, &p->tab);
            }
        }

        rodada++;
        desenha(&p->tab);
        vencedor = temVencedor(&p->tab);
    }

    if (vencedor == 1) {
        printf(" " VERMELHO "JOGADOR X VENCEU!\n" RESET " ");
    } else if (vencedor == 2) {
        printf(" " VERDE "JOGADOR O VENCEU!\n" RESET " ");
    } else {
        printf(" " AMARELO "EMPATE!\n" RESET " ");
    }
}

#endif