#include <stdio.h>

int ConverteBinario(int n){
	if(n == 0)
		return 0;
	else if(n == 1)
		return 1;
	
	 return (n % 2) + 10 * ConverteBinario(n / 2);
}

int main(){
	int num, bin;
	
	printf("\nDigite um número inteiro: ");
	scanf("%d", &num);
	
	printf("\nO número %d convertido para binário é %d", num, ConverteBinario(num));
	
	return 0;
}