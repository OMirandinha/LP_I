#include <stdio.h>
#include <string.h>

void ProcuraPalavra(char *frase, char *palavra) {
    int totRepeticoes = 0;

    // Pega a primeira palavra da frase
    char *token = strtok(frase, " ");

    // Enquanto existirem palavras na frase
    while (token != NULL) {
        // Compara se a palavra atual (token) é igual à procurada
        if (strcmp(token, palavra) == 0) {
            totRepeticoes++;
        }
        // Pega a próxima palavra
        token = strtok(NULL, " ");
    }

    if (totRepeticoes > 0) {
        printf("A palavra '%s' foi encontrada %i vezes.\n", palavra, totRepeticoes);
    } else {
        printf("A palavra '%s' nao foi encontrada.\n", palavra);
    }
}

int main() {
    char frase[100], palavra[30];

    printf("Digite uma frase: ");
    scanf(" %[^\n]", frase);

    printf("Digite a palavra: ");
    scanf("%s", palavra);

    ProcuraPalavra(frase, palavra);

    return 0;
}
