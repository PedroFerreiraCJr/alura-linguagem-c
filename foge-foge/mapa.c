#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mapa.h"

void liberar_mapa(Mapa *m) {
    for (int i=0; i<(*m).linhas; i++) {
        free((*m).matriz[i]);
    }
    free((*m).matriz);
}

void ler_mapa(Mapa *m) {
    FILE *f = NULL;
    f = fopen("mapa.txt", "r");
    if (!f) {
        printf("Erro na leitura do mapa\n");
        exit(1);
    }

    // lê do arquivo a quantidade de linhas e colunas a serem alocadas
    fscanf(f, "%d %d", &(m->linhas), &(m->colunas));

    // aloca a memória para armazenar o mapa do jogo
    alocar_mapa(m);

    for (int i=0; i<5; i++) {
        fscanf(f, "%s", m->matriz[i]);
    }
    fclose(f);
}

void alocar_mapa(Mapa *m) {
    m->matriz = malloc(sizeof(char *) * m->linhas);
    for (int i=0; i<m->linhas; i++) {
        m->matriz[i] = malloc(sizeof(char) * (m->colunas + 1));
    }
}

void imprimir_mapa(Mapa *m) {
    for (int i=0; i<m->linhas; i++) {
        printf("%s\n", m->matriz[i]);
    }
}

int encontrar_mapa(Mapa *m, Posicao *p, char c) {
	for(int i = 0; i < m->linhas; i++) {
		for(int j = 0; j < m->colunas; j++) {
			if(m->matriz[i][j] == c) {
				p->x = i;
				p->y = j;
				return 1;
			}
		}
	}

    return 0;
}

int eh_valida(Mapa *m, int x, int y) {
    if (x >= m->linhas) {
        return 0;
    }
    
    if (y >= m->colunas) {
        return 0;
    }

    return 1;
}

int eh_vazia(Mapa *m, int x, int y) {
    return m->matriz[x][y] == VAZIO;
}

int eh_parede(Mapa *m, int x, int y) {
    return m->matriz[x][y] == PAREDE_VERTICAL || m->matriz[x][y] == PAREDE_HORIZONTAL;
}

int eh_personagem(Mapa *m, char personagem, int x, int y) {
    return m->matriz[x][y] == personagem;
}

int pode_movimentar(Mapa *m, char personagem, int x, int y) {
    return eh_valida(m, x, y) && !eh_parede(m, x, y) && !eh_personagem(m, personagem, x, y);
}

void atualiza_posicao_mapa(Mapa *m, int origem_x, int origem_y, int destino_x, int destino_y) {
    char personagem = m->matriz[origem_x][origem_y];
    m->matriz[destino_x][destino_y] = personagem;
    m->matriz[origem_x][origem_y] = VAZIO;
}

void copiar_mapa(Mapa *destino, Mapa *origem) {
    destino->linhas = origem->linhas;
    destino->colunas = origem->colunas;

    alocar_mapa(destino);

    for (int i=0; i<origem->linhas; i++) {
        strcpy(destino->matriz[i], origem->matriz[i]);
    }
}
