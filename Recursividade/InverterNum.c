#include <stdio.h>

int inverter(int n, int invertido) {
    if (n == 0) {
        return invertido;
    } else {
        int ultimoDigito = n % 10;
        invertido = (invertido * 10) + ultimoDigito;

        return inverter(n / 10, invertido);
    }
}

int main() {
    int num;
    printf("Digite um numero inteiro: ");
    scanf("%d", &num);

    int resultado = inverter(num, 0);

    printf("O numero %d invertido e: %d\n", num, resultado);

    return 0;
}