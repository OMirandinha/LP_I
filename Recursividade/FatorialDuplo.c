#include <stdio.h>

long long fatorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * fatorial(n - 1);
}

long long fatorial_duplo(int n) {
    if (n == 1) {
        return fatorial(1);
    }

    return n * fatorial_duplo(n - 2);
}

int main() {
    int n;

    printf("Digite um numero inteiro positivo impar: ");
    if (scanf("%d", &n) != 1) {
        printf("Entrada invalida.\n");
        return 1;
    }

    if (n < 1 || n % 2 == 0) {
        printf("Erro: O numero deve ser um inteiro positivo impar.\n");
    } else {
        long long resultado = fatorial_duplo(n);
        printf("O fatorial duplo de %d (%d!!) e: %lld\n", n, n, resultado);
    }

    return 0;
}
