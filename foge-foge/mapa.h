#ifndef MAPA_H_INCLUDED
#define MAPA_H_INCLUDED

struct mapa {
    char **matriz;
    int linhas;
    int colunas;
};

typedef struct mapa Mapa;

void liberar_mapa(Mapa *m);
void ler_mapa(Mapa *m);
void alocar_mapa(Mapa *m);
void imprimir_mapa(Mapa *m);

struct posicao {
	int x;
	int y;
};

typedef struct posicao Posicao;

void encontrar_mapa(Mapa *m, Posicao *p, char c);

#endif // MAPA_H_INCLUDED
