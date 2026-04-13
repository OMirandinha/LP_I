/*  Fac¸a um programa que leia dois valores inteiros e chame uma func¸˜ ao que receba estes
2 valores de entrada e retorne o maior valor na primeira vari´ avel e o menor valor na
segunda vari´ avel. Escreva o conte´udo das 2 vari´ aveis na tela */

#include <stdio.h>

void troca(int *val1, int *val2) {
    int temp;

    if (*val2 > *val1) {
        temp = *val1;
        *val1 = *val2;
        *val2 = temp;
    }
}

int main() {
    int n1, n2;

    printf("Digite dois valores: ");
    scanf("%i %i", &n1, &n2);

    troca(&n1, &n2);

    printf("\nMaior: %i", n1);
    printf("\nMenor: %i\n", n2);

    return 0;
}