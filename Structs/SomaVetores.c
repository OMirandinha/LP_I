#include <stdio.h>

typedef struct {
    float x; // Corrigido: era 'flota'
    float y;
    float z;
} vetor;

void Soma(vetor v1, vetor v2) {
	 vetor res; // Cria um vetor temporário para o resultado

    res.x = v1.x + v2.x;
    res.y = v1.y + v2.y;
    res.z = v1.z + v2.z;

    printf("\nSoma: x=%.2f, y=%.2f, z=%.2f\n", res.x, res.y, res.z);
}

int main() {
    vetor v1;
    vetor v2;


    printf("\nDigite os elementos do vetor 1: ");
    scanf("%f %f %f", &v1.x, &v1.y, &v1.z);
    

    printf("\nDigite o elemento %d do vetor 2: ");
    scanf("%f %f %f", &v2.x, &v2.y, &v2.z);
    

    printf("\nSomando os vetores temos: ");
    Soma(v1, v2);

    return 0;
}