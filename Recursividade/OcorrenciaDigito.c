#include <stdio.h>
#include <string.h>

int Encontrar(char d, char *s) {
    if (*s == '\0') {
        return 0;
    }

    int encontrado = (*s == d) ? 1 : 0;

    return encontrado + Encontrar(d, s + 1);
}

int main() {
    char digito;
    char num[15];
    int total;

    printf("Digite uma serie de numeros: ");
    scanf("%14s", num);

    printf("Qual digito deseja encontrar? ");
    scanf(" %c", &digito);

    total = Encontrar(digito, num);

    if (total == 0) {
        printf("\nDigito '%c' nao encontrado.\n", digito);
    } else {
        printf("\nO digito '%c' ocorreu %d vezes na serie.\n", digito, total);
    }

    return 0;
}