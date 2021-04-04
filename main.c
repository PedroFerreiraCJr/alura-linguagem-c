#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/*
    @Autor: Pedro Junior
    @Instrucoes: como compilar no terminal: gcc -o main main.c -lpthread
*/

void *print(void *value) {
    int *i = malloc(sizeof(int));
    *i = *(int *)value;
    printf("O valor passado como argumento para a tarefa foi: %d.\n", *i);
    (*i) *= 10;

    pthread_exit(i);
}

// função principal, ponto de entrada do programa
int main(int argc, const char *argv[]) {
    int valor = 100;
    pthread_t id;

    pthread_create(&id, NULL, print, &valor);

    int *p = NULL;

    pthread_join(id, (void**)&p);
    printf("Valor recebido do processo filho: %d.\n", *p);

    free(p);

    return 0;
}
