#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	int num[6], resto;
	char letras[6];
	
	resto = 0;
	
	printf("Digite os valores do vetor de inteiros: \n");
	for(int i = 0; i < 6; i++){
		scanf("%d", &num[i]);
	}
	
	printf("Digite os caracteres do vetor: \n");
	for(int i = 0; i < 6; i++){
		scanf(" %c", &letras[i]);
	}
	
	for(int i = 0; i < 6; i++){
		resto = num[i] % 10;
		
		if(resto == 0){
			printf("%c", letras[i]);
		} else {
			for(int j = 0; j < resto; j++){
				printf("%c", letras[i]);
			}
		}
	}
	
	return 0;
}