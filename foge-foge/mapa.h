#ifndef MAPA_H_INCLUDED
#define MAPA_H_INCLUDED

#define HEROI '@'
#define FANTASMA 'F'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'
#define PILULA 'P'
#define BOMBA 'b'

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

int encontrar_mapa(Mapa *m, Posicao *p, char c);
int eh_valida(Mapa *m, int x, int y);
int eh_vazia(Mapa *m, int x, int y);
void atualiza_posicao_mapa(Mapa *m, int origem_x, int origem_y, int destino_x, int destino_y);
void copiar_mapa(Mapa *destino, Mapa *origem);
int pode_movimentar(Mapa *m, char personagem, int x, int y);
int eh_parede(Mapa *m, int x, int y);
int eh_personagem(Mapa *m, char personagem, int x, int y)

#endif // MAPA_H_INCLUDED
