#include <stdio.h>

int main(){
	int N, L, trocas, permutacao[50];
	
	printf("Digite o número de casos de teste: \n");
	scanf("%d", &N);
	
	for(int k = 0; k<N; k++){
		printf("Digite o comprimento do vagão: \n");
		scanf("%d", &L);
		
		printf("Digite a ordem atual dos vagões: \n");
		for(int i = 0; i < L; i++){
			scanf("%d", &permutacao[i]);
		}
		
		trocas = 0;
		
		 for(int i = 0; i < L; i++) {
            for(int j = i + 1; j < L; j++) {
                if(permutacao[i] > permutacao[j]) {
                    trocas += 1;
                }
            }
        }
		
		printf("Optimal train swapping takes %d swaps.", trocas);
	}
	
	return 0;
	
}