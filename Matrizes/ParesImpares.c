#include <stdio.h>
#include <stdlib.h>

int compararCrescente(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int compararDecrescente(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int N, i;
    
    scanf("%d", &N);
    
    int pares[N], impares[N];
    int contPar = 0, contImpar = 0;
    int numero;
    
    // Separando pares e ímpares diretamente
    for(i = 0; i < N; i++) {
        scanf("%d", &numero);
        
        if(numero % 2 == 0) {
            pares[contPar] = numero;
            contPar++;
        } else {
            impares[contImpar] = numero;
            contImpar++;
        }
    }
    
    // Ordenar pares em ordem crescente
    qsort(pares, contPar, sizeof(int), compararCrescente);
    
    // Ordenar ímpares em ordem decrescente
    qsort(impares, contImpar, sizeof(int), compararDecrescente);
    
    // Saída: primeiro os pares ordenados
    for(i = 0; i < contPar; i++) {
        printf("%d\n", pares[i]);
    }
    
    // Depois os ímpares ordenados
    for(i = 0; i < contImpar; i++) {
        printf("%d\n", impares[i]);
    }
    
    return 0;
}