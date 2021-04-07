// adição de biblioteca de I/O
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

    int segundos = time(0);
    srand(segundos);

    int numero_grande = rand();

    // declaração e inicialização de variável do tipo inteiro
    int numero_secreto = numero_grande % 100;

    // declaração e inicialização da variável que armazenará o
    //o valor do chute o jogador
    int chute = 0;
    int acertou = 0;
    int tentativas = 1;
    double pontos = 1000;

    int nivel;
    printf("Qual o nível de dificuldade?\n");
    printf("(1) Fácil, (2) Médio, (3) Difícil\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    int numero_tentativas;
    switch (nivel) {
        case 1: {
            numero_tentativas = 20;
            break;
        }
        case 2: {
            numero_tentativas = 15;
            break;
        }
        default: {
            numero_tentativas = 6;
        }
    }

    for (int i=1; i<=numero_tentativas; i++) {
        printf("Tentativa %d\n", tentativas);
        // imprime na tela a pergunta sobre qual valor o jogador quer fornecer
        printf("Qual é o seu chute?: ");
        // lê do teclado o valor digitado pelo jogador
        scanf("%d", &chute);

        // imprime o valor fornecido pelo jogador
        printf("Seu chute foi %d.\n", chute);

        if (chute < 0) {
            printf("Você não pode chutar números negativos...\n");
            continue;
        }

        acertou = chute == numero_secreto;
        int maior = chute > numero_secreto;

        // implementação de verificação condicional, com ramificação, caso
        //verdadeiro e caso falso.
        if (acertou) {
            break;
        }
        else if (maior) {
            // verifica se o valor do chute é maior que o numero_secreto
            //então mostra a mensagem do bloco
            printf("Seu chute foi maior que o número secreto.\n");
        }
        else {
            printf("Seu chute foi menor que o número secreto.\n");
        }

        tentativas++;
        double pontosperdidos = abs(chute - numero_secreto) / 2.0;
        pontos = pontos - pontosperdidos;

        printf("\n");

    }

    printf("Fim de jogo.\n");
    if (acertou) {
        printf("Parabéns! Você acertou!\n");
        printf("Jogue de novo, você é um bom jogador.\n");
        printf("Você acertou em %d tentativas.\n", tentativas);
        printf("Total de pontos %.1f.\n", pontos);
    }
    else {
        printf("Você perdeu!\n");
        printf("Tente novamente.\n");
    }

    // instrução de retorno de valores ao chamadar da função main, que é
    //o sistema operacional. nesse caso o código de sáida é conclusão normal
    return 0;
}
