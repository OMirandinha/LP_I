#include <stdio.h>

void ImprimeSerie(int i, int j, int k) {
    if (k == 0) {
        printf("\nErro: Incremento não pode ser zero.");
        return;
    }

    if ((k > 0 && i > j) || (k < 0 && i < j)) {
        return;
    }

    printf("%d ", i);

    ImprimeSerie(i + k, j, k);
}

int main() {
    int inicio, fim, incremento;

    printf("Digite o inicio da sequencia: ");
    scanf("%d", &inicio);

    printf("Digite o fim da sequencia: ");
    scanf("%d", &fim);

    printf("Digite o incremento: ");
    scanf("%d", &incremento);

    printf("\nSerie: ");
    ImprimeSerie(inicio, fim, incremento);
    printf("\n");

    return 0;
}