#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/*
    @Autor: Pedro Junior
    @Instrucoes: como compilar no terminal: gcc -o main main.c -lpthread
*/

pthread_cond_t condition = PTHREAD_COND_INITIALIZER;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

int done = 1;

void *execute() {
    printf("Thread adquirindo o lock.\n");
    pthread_mutex_lock(&lock);

    if (done == 1) {
        done = 2;
        printf("A primeira thread está aguardando na variável 'condition'.\n");
        pthread_cond_wait(&condition, &lock);
    }
    else {
        printf("A segunda thead está sinalizando na variável 'condition'.\n");
        pthread_cond_signal(&condition);
    }

    pthread_mutex_unlock(&lock);
    printf("Retornando da função invocada.\n");

    return NULL;
}

// função principal, ponto de entrada do programa
int main(int argc, const char *argv[]) {
    printf("Criando primeira thread.\n");
    pthread_t tids[2];
    pthread_create(&tids[0], NULL, execute, NULL);

    printf("Aguardando 5s antes de criar a segunda thread.\n");
    sleep(10);

    printf("Segunda thread criada.\n");
    pthread_create(&tids[1], NULL, execute, NULL);

    pthread_join(tids[0], NULL);
    pthread_join(tids[1], NULL);

    printf("As threads finalizaram.\n");

    return 0;
}
