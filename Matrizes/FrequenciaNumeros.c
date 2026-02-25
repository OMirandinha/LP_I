#include <stdio.h>

int main(){
	int N, valor;
	int freq[2001] = {0};  // Array para contar frequência de 1 a 2000
	
	// Leitura do N
	scanf("%d", &N);
	
	// Leitura dos valores e contagem
	for(int i = 0; i < N; i++){
		scanf("%d", &valor);
		freq[valor]++;
	}
	
	// Percorre do 1 ao 2000 em ordem crescente
	for(int i = 1; i <= 2000; i++){
		if(freq[i] > 0){
			printf("%d aparece %d vez(es)\n", i, freq[i]);
		}
	}
	
	return 0;
}