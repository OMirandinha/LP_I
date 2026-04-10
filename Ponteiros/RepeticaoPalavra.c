#include <stdio.h>
#include <string.h>

void ProcuraPalavra(char *frase, char *palavra) {
    char *ptr = frase;
    int totRepeticoes = 0;
    size_t tamPalavra = strlen(palavra);

    // O strstr busca a primeira ocorrência.
    // O loop continua enquanto ele encontrar a palavra.
    while ((ptr = strstr(ptr, palavra)) != NULL) {
        totRepeticoes++;
        // Move o ponteiro para frente para não encontrar a mesma palavra no mesmo lugar
        ptr += tamPalavra;
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
    // %[^\n] faz o scanf ler a linha toda, incluindo espaços, ate o Enter
    scanf(" %[^\n]", frase);

    printf("Digite a palavra a ser procurada: ");
    scanf("%s", palavra);

    ProcuraPalavra(frase, palavra);

    return 0;
}
