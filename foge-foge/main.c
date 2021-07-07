#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "mapa.h"

Mapa m;
Posicao heroi;

int acabou() {
    return 0;
}

void move(char direcao) {
    m.matriz[heroi.x][heroi.y] = '.';

    switch (direcao) {
        case 'a': {
            m.matriz[heroi.x][heroi.y-1] = '@';
            heroi.y--;
            break;
        }
        case 'w': {
            m.matriz[heroi.x-1][heroi.y] = '@';
            heroi.x--;
            break;
        }
        case 's': {
            m.matriz[heroi.x+1][heroi.y] = '@';
            heroi.x++;
            break;
        }
        case 'd': {
            m.matriz[heroi.x][heroi.y+1] = '@';
            heroi.y++;
            break;
        }
    }
}

int main() {
    ler_mapa(&m);
    encontrar_mapa(&m, &heroi, '@');

    do {
        imprimir_mapa(&m);

        char comando;
        scanf(" %c", &comando);

        move(comando);
    } while (!acabou());

    liberar_mapa(&m);

    return 0;
}
