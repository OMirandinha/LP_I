#include <stdio.h>

int GerarFuncao(int index){
	if(index == 0)
		return 0;
	else if(index == 1)
		return 1;
	else
		return GerarFuncao(index - 1) + GerarFuncao(index - 2);
	
}
int main(){
	int f;
	
	printf("\nDigite a quantidade de iterações da função: ");
	scanf("%d", &f);
	
	int resultado = GerarFuncao(f);
	printf("\nO valor final da função foi: %d", resultado);
	
	return 0;
}