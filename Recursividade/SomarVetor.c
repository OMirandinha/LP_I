#include <stdio.h>

int SomarElementos(int vet[], int n) {
    if (n <= 0) {
        return 0;
    } else {
        return vet[n - 1] + SomarElementos(vet, n - 1);
    }
}

int main() {
    int iteracoes;
    
    printf("Quantos elementos deseja adicionar ao vetor? ");
    scanf("%d", &iteracoes);

    int vetor[iteracoes]; 
    
    for(int i = 0; i < iteracoes; i++) {
        printf("Digite o %d° elemento: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    int resultado = SomarElementos(vetor, iteracoes);
    
    printf("\nO valor da soma de todos os elementos e: %d\n", resultado);
    
    return 0;
}