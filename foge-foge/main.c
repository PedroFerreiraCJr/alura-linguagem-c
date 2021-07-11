#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"
#include "mapa.h"

Mapa m;
Posicao heroi;

void fantasmas() {
    Mapa copia;
    copiar_mapa(&copia, &m);

    for (int i=0; i<m.linhas; i++) {
        for (int j=0; j<m.colunas; j++) {
            if (copia.matriz[i][j] == FANTASMA) {
                int xdestino;
                int ydestino;

                int encontrou = movimenta_fantasma_aleatoriamente(i, j, &xdestino, &ydestino);
                if (encontrou) {
                    atualiza_posicao_mapa(&m, i, j, xdestino, ydestino);
                }

                if (pode_movimentar(&m, i, j + 1)) {
                    atualiza_posicao_mapa(&m, i, j, i, j + 1);
                }
            }
        }
    }

    liberar_mapa(&copia);
}

int movimenta_fantasma_aleatoriamente(int xatual, int yatual, int *xdestino, int *ydestino) {
    int opcoes[4][2] = {
        { xatual, yatual + 1},
        { xatual + 1, yatual},
        { xatual, yatual - 1},
        { xatual - 1, yatual},
    };

    srand(time(0));
    for (int i=0; i<10; i++) {
        int posicao = rand() % 4;
        if (pode_movimentar(&m, FANTASMA, opcoes[posicao][0], opcoes[posicao][1])) {
            *xdestino = opcoes[posicao][0];
            *ydestino = opcoes[posicao][1];
            return 1;
        }
    }

    return 0;
}

int acabou() {
    Posicao pos;
    int encontrou = encontrar_mapa(&m, &pos, HEROI);
    return !encontrou;
}

int eh_direcao(char direcao) {
    // valida o input do usuário para a direção de movimento
    return direcao == ESQUERDA
        && direcao == CIMA
        && direcao == BAIXO
        && direcao == DIREITA;
}

void move(char direcao) {
    if (!eh_direcao(direcao)) {
        return;
    }

    int proximo_x = heroi.x;
    int proximo_y = heroi.y;
    switch (direcao) {
        case ESQUERDA: {
            proximo_y--;
            break;
        }
        case CIMA: {
            proximo_x--;
            break;
        }
        case BAIXO: {
            proximo_x++;
            break;
        }
        case DIREITA: {
            proximo_y++;
            break;
        }
    }

    // valida se a posição é está nos limites do mapa
    if (!pode_movimentar(&m, HEROI, proximo_x, proximo_y)) {
        return;
    }
    
    // atualiza as posições no tabuleiro
    atualiza_posicao_mapa(&m, heroi.x, heroi.y, proximo_x, proximo_y);
    heroi.x = proximo_x;
    heroi.y = proximo_y;
}

int main() {
    ler_mapa(&m);
    encontrar_mapa(&m, &heroi, HEROI);

    do {
        imprimir_mapa(&m);

        char comando;
        scanf(" %c", &comando);

        move(comando);
        fantasmas();
    } while (!acabou());

    liberar_mapa(&m);

    return 0;
}
