// Considere as matrizes A e B contendo 25 elementos inteiros cada, gerar e exibir uma
//matriz C de 50 elementos, cujos elementos sejam a intercalação dos elementos de A e B.

#include <stdio.h>

int main(){
	int A[25], B[25], C[50];
	
	printf("Digite os elemntos do vetor A");
	for(int i = 0; i <25; i++){
		scanf("%d", &A[i]);
	}
	
	printf("Digite os elemntos do vetor B");
	for(int i = 0; i <25; i++){
		scanf("%d", &B[i]);
	}
	
	 for(int i = 0; i < 50; i++) {
        if(i % 2 == 0) {           
            C[i] = A[i / 2];       
        } else {                    
            C[i] = B[i / 2];        
        }
		printf("%d\n", C[i]);
    }
	
	return 0;
}

