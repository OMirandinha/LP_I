#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	char frase[100], caracter;
	
	printf("Digite uma String: \n");
	scanf("%[^\n]", frase);  // Lê até a quebra de linha (permite espaços)
			
	printf("Digite um caracter: \n");
	scanf(" %c", &caracter);
	
	caracter = tolower(caracter);  // Converte o caracter para minúscula
	
	printf("Indices onde ocorrem o caractere %c: ", caracter);
	
	for(int i = 0; i < strlen(frase); i++){
		char c = tolower(frase[i]);
		if(c == caracter){
			printf("%d ", i);  // Imprime o índice com espaço
		}
	}
	
	printf("\n");
	
	return 0;
}