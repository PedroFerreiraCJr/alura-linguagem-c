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

    // loop for para perguntar ao jogador, com três tentativas
    //três repetições no máximo
    for (int i=1; i<=3; i++) {
        printf("Tentativa %d de 3\n", i);
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

            // caso o jogador acerte, independente da tentativa
            //o for deve ser terminado imediatamente
            break;
        }
        else {
            // faz a verificação utilizando operadores relacionais para
            //dizer ao jogador quão perto o valor está do numero secreto
            int maior = chute > numero_secreto;
            if (maior) {
                printf("Seu chute foi maior que o número secreto.\n");
            }
            else {
                printf("Seu chute foi menor que o número secreto.\n");
            }
        }

        printf("\n");
    }

    printf("Fim de jogo.\n");

    // instrução de retorno de valores ao chamadar da função main, que é
    //o sistema operacional. nesse caso o código de sáida é conclusão normal
    return 0;
}
