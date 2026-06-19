#include <stdio.h>

int Multiplic_recur(int n1, int n2) {
    if (n2 == 0) {
        return 0;
    }

    if (n2 < 0) {
        return -Multiplic_recur(n1, -n2);
    }

    return n1 + Multiplic_recur(n1, n2 - 1);
}

int main() {
    int n1, n2, resultado;

    printf("Digite um numero: ");
    scanf("%d", &n1);

    printf("Digite o multiplicador: ");
    scanf("%d", &n2);

    resultado = Multiplic_recur(n1, n2);

    printf("O resultado de %d x %d foi %d\n", n1, n2, resultado);

    return 0;
}