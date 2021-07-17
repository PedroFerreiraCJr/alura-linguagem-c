#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#define CIMA 'w'
#define BAIXO 's'
#define DIREITA 'd'
#define ESQUERDA 'a'

int acabou();
void move(char direcao);
int eh_direcao(char direcao);
void fantasmas();
int movimenta_fantasma_aleatoriamente(int xatual, int yatual, int *xdestino, int *ydestino);
void explodir_pilula();
void explodir_pilula2(int x, int y, int soma_x, int soma_y, int qtd);

#endif // MAIN_H_INCLUDED
