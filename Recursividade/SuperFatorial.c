#include <stdio.h>

unsigned long long fatorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * fatorial(n - 1);
}

unsigned long long superfatorial(int n) {
    if (n <= 1) {
        return fatorial(1); 
    }

    return fatorial(n) * superfatorial(n - 1);
}

int main() {
    int n;

    printf("Digite um numero inteiro positivo: ");
    if (scanf("%d", &n) != 1) {
        printf("Entrada invalida.\n");
        return 1;
    }

    if (n < 0) {
        printf("Erro: O numero deve ser positivo.\n");
    } else {
        unsigned long long resultado = superfatorial(n);
        printf("O superfatorial de %d e: %llu\n", n, resultado);
    }

    return 0;
}
