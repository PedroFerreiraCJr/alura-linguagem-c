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

    // declaração e inicialização da variável que armazenará o
    //o valor do chute o jogador
    int chute = 0;
    // imprime na tela a pergunta sobre qual valor o jogador quer fornecer
    printf("Qual é o seu chute?: ");
    // lê do teclado o valor digitado pelo jogador
    scanf("%d", &chute);

    // imprime o valor fornecido pelo jogador
    printf("Seu chute foi %d.\n", chute);

    // implementação de verificação condicional, com ramificação, caso
    //verdadeiro e caso falso.
    if (chute == numero_secreto) {
        // caso os números forem iguais, o jogador acertou
        printf("Parabéns! Você acertou!\n");
        printf("Jogue de novo, você é um bom jogador.\n");
    }
    else {
        // faz a verificação utilizando operadores relacionais para
        //dizer ao jogador quão perto o valor está do numero secreto
        if (chute > numero_secreto) {
            printf("Seu chute foi maior que o número secreto.\n");
        }

        // faz a verificação utilizando operadores relacionais para
        //dizer ao jogador quão perto o valor está do numero secreto
        if (chute < numero_secreto) {
            printf("Seu chute foi menor que o número secreto.\n");
        }
    }

    // instrução de retorno de valores ao chamadar da função main, que é
    //o sistema operacional. nesse caso o código de sáida é conclusão normal
    return 0;
}
