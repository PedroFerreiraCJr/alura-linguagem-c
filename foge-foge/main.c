#include <stdio.h>
#include <stdlib.h>

// declara um ponteiro para ponteiro que representa o mapa do jogo
char **mapa;
// variavel que armazena a quantidade de linhas que foram lidos do arquivo de mapa e é usada
//na alocação do mapa.
int linhas;
// variavel que armazena a quantidade de colunas que foram lidos do arquivo de mapa e é usada
//na alocação do mapa.
int colunas;

int main() {
    FILE *f = NULL;
    f = fopen("mapa.txt", "r");
    if (!f) {
        printf("Erro na leitura do mapa\n");
        exit(1);
    }

    // alocação de memória dinâmica
    /* exemplo de alocação de memória para um int
    int *v = malloc(sizeof(int));
    *v = 10;
    printf("%d\n", *v);
    free(v);
    */
    // final da alocação dinâmica

    // lê do arquivo a quantidade de linhas e colunas a serem alocadas
    fscanf(f, "%d %d", &linhas, &colunas);

    // aloca a memória para armazenar o mapa do jogo
    mapa = malloc(sizeof(char *) * linhas);
    for (int i=0; i<linhas; i++) {
        mapa[i] = malloc(sizeof(char) * (colunas + 1));
    }

    for (int i=0; i<5; i++) {
        fscanf(f, "%s", mapa[i]);
    }

    for (int i=0; i<5; i++) {
        printf("%s\n", mapa[i]);
    }

    fclose(f);

    for (int i=0; i<linhas; i++) {
        free(mapa[i]);
    }
    free(mapa);

    return 0;
}
