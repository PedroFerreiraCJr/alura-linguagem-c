#include <stdio.h>
#include <string.h>

int main() {
    char palavra_secreta[20];
    sprintf(palavra_secreta, "Melancia");

    int acertou = 0;
    int enforcou = 0;

    char chutes[26];
    int tentativas = 0;

    do {
        for(int i=0; i<strlen(palavra_secreta); i++) {

            int achou = 0;
            for(int j=0; j<tentativas; j++) {
                if (chutes[j] == palavra_secreta[i]) {
                    achou = 1;
                    break;
                }
            }

            if (achou) {
                printf("%c ", palavra_secreta[i]);
            }
            else {
                printf("_ ");
            }
        }
        printf("\n");

        char chute = 0;
        scanf(" %c", &chute);

        chutes[tentativas] = chute;
        tentativas++;
    } while(!acertou && !enforcou);

    return 0;
}
