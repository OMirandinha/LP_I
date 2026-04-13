/* . Crie um programa que contenha um array de float contendo 10 elementos. Imprima o
enderec¸o de cada posic¸˜ ao desse array. */

#include <stdio.h>

int main() {
    float vet[10]; 

    printf("Digite os 10 elementos do vetor:\n");
    for(int i = 0; i < 10; i++) {
        scanf("%f", &vet[i]);
    }

    printf("\nEnderecos de cada posicao:\n");
    for(int j = 0; j < 10; j++) {
        printf("Posicao [%d] - Endereco: %p\n", j, (void*)&vet[j]);
    }

    return 0;
}