// Dado um vetor A contendo 10 elementos inteiros, gerar e exibir um vetor B cujos
// elementos estão na ordem inversa de A.

#include <stdio.h>

int main(){
	
	int A[10], B[10];
	
	for(int i = 0; i < 10; i++){
		printf("Digite um valor inteiro para o vetor A\n");
		scanf("%d", &A[i]);				
	}
	
	
	
	for(int i = 0; i < 10; i++){
		B[i] = A[9 - i];
		printf("%d\n", B[i]);
	}
	
	return 0;
}