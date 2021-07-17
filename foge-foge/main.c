#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"
#include "mapa.h"

Mapa m;
Posicao heroi;
int tem_pilula = 0;

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

    if (eh_personagem(&m, PILULA, proximo_x, proximo_y)) {
        tem_pilula = 1;
    }
    
    // atualiza a posição do heroi no tabuleiro
    atualiza_posicao_mapa(&m, heroi.x, heroi.y, proximo_x, proximo_y);
    heroi.x = proximo_x;
    heroi.y = proximo_y;
}

void explodir_pilula() {
    // early return, não tem pilula para explodir os fantasmas
    if (!tem_pilula) {
        return;
    }

    explodir_pilula2(heroi.x, heroi.y, 0, 1, 3);
    explodir_pilula2(heroi.x, heroi.y, 0, -1, 3);
    explodir_pilula2(heroi.x, heroi.y, 1, 0, 3);
    explodir_pilula2(heroi.x, heroi.y, -1, 0, 3);

    tem_pilula = 0;
}

void explodir_pilula2(int x, int y, int soma_x, int soma_y, int qtd) {
    // condição de parada da chamada recursiva
    if (qtd == 0) {
        return;
    }
    
    if (!eh_valida(&m, x, y + 1)) {
        return;
    }

    if (eh_parede(&m, x, y + 1)) {
        return;
    }

    int nova_x = x + soma_x;
    int nova_y = y + soma_y;

    m.matriz[nova_x][nova_y] = VAZIO;
    explodir_pilula(nova_x, nova_y, soma_x, soma_y, qtd - 1);
}

int main() {
    ler_mapa(&m);
    encontrar_mapa(&m, &heroi, HEROI);

    do {
        imprimir_mapa(&m);

        char comando;
        scanf(" %c", &comando);
        move(comando);

        if (comando == BOMBA) {
            explodir_pilula(heroi.x, heroi.y, 3);
        }

        fantasmas();
    } while (!acabou());

    liberar_mapa(&m);

    return 0;
}
