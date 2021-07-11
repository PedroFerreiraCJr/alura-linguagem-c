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

#endif // MAIN_H_INCLUDED
