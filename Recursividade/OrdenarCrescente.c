#include <stdio.h>

void Ordenar(int n) {
    if (n < 0) {
        return;
    }

    Ordenar(n - 1);

    printf("%d ", n);
}

int main() {
    int num;

    printf("Digite um numero: ");
    if (scanf("%d", &num) != 1) {
        printf("Entrada invalida.");
        return 1;
    }

    printf("Sequencia de 0 até %d: ", num);
    Ordenar(num);
    printf("\n");

    return 0;
}