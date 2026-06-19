#include <stdio.h>

void OrdenarDecrescente(int n) {
    if (n < 0) {
        return;
    }

    printf("%d ", n);

    OrdenarDecrescente(n - 1);
}

int main() {
    int num;

    printf("Digite um numero: ");
    scanf("%d", &num);

    printf("Sequencia de %d ate 0: ", num);
    OrdenarDecrescente(num);
    printf("\n");

    return 0;
}