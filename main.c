// adição de biblioteca de I/O
#include <stdio.h>

/*
    @Autor: Pedro Junior
    @Instrucoes: como compilar no terminal: gcc -o main main.c
*/

// função principal, ponto de entrada do programa
int main(int argc, char *argv[]) {
    // imprime o cabeçalho do programa
    printf("***********************************************\n");
    printf("* Seja bem-vindo ao nosso Jogo de Adivinhação *\n");
    printf("***********************************************\n");

    // declaração e inicialização de variável do tipo inteiro
    int numero_secreto = 42;

    printf("O número %d é o numero secreto. Não conta para ninguém!\n", numero_secreto);

    // instrução de retorno de valores ao chamadar da função main, que é
    //o sistema operacional. nesse caso o código de sáida é conclusão normal
    return 0;
}
