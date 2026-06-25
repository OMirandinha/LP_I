#include <stdio.h>

int SomaDigitos(int n){
	if(n / 10 == 0)
		return n;
		
	return (n % 10) + SomaDigitos(n / 10);
}

int main(){
	int num;
	printf("\nDigite um número: ");
	scanf("%d", &num);
	
	printf("\nA soma dos digitos de %d é %d", num, SomaDigitos(num));
	return 0;
}