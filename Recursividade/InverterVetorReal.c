#include <stdio.h>


void inverterVetor(float vet[], int inicio, int fim) {
    if (inicio >= fim) {
        return;
    } else {
        float temp = vet[inicio];
        vet[inicio] = vet[fim];
        vet[fim] = temp;

        inverterVetor(vet, inicio + 1, fim - 1);
    }
}

int main() {
    float vetor[20];
    int i;
    const int TAM = 20;

    printf("Digite %d numeros reais:\n", TAM);

    for (i = 0; i < TAM; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%f", &vetor[i]);
    }

    inverterVetor(vetor, 0, TAM - 1);

    printf("\nVetor Invertido:\n");
    for (i = 0; i < TAM; i++) {
        printf("%.2f  ", vetor[i]);
    }
    printf("\n");

    return 0;
}