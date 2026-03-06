#include <stdio.h>
#include <Ctype.h>

int main(){
	char palavra[100], substito;
	int totVogal = 0;
	
	printf("Digite uma palavra: \n");
	scanf("%s", palavra);
	
	for(int i = 0; i < strlen(palavra); i++){
		char c = tolower(palavra[i]);
		if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
			totVogal++;
		}
	}
	
	printf("Há um total de %d vogais na palavra \n", totVogal);
	printf("Digite um caracter: \n");
	scanf(" %c", &substito);
	
	for(int i = 0; i < strlen(palavra); i++){
		char c = tolower(palavra[i]);
		if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
			palavra[i] = substito;
		}
	}
	
	printf("\n %s", palavra);
	
	return 0;
}