#include <stdio.h>
#include <stdlib.h>
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

void encontrar_mapa(Mapa *m, Posicao *p, char c) {
	for(int i = 0; i < m->linhas; i++) {
		for(int j = 0; j < m->colunas; j++) {
			if(m->matriz[i][j] == c) {
				p->x = i;
				p->y = j;
				return;
			}
		}
	}
}