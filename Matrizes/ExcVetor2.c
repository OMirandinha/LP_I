// Dados dois vetores A e B contendo 20 elementos inteiros cada, gerar e exibir um vetor
// C do mesmo tamanho cujos elementos sejam a soma dos respectivos elementos de A e B.

#include <stdio.h>

int main(){
	int A[20], B[20], C[20];
	
	for(int i = 0; i < 20; i++){
		printf("Digite um valor inteiro para o vetor A\n");
		scanf("%d", &A[i]);
	}
	
	for(int i = 0; i < 20; i++){
		printf("Digite um valor inteiro para o vetor B\n");
		scanf("%d", &B[i]);
	}
	
	for(int i = 0; i < 20; i++){
		C[i] = A[i] + B[i];
		printf("%d\n", C[i]);
		
	}
	
	return 0;
	
}


