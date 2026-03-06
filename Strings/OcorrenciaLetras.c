#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	char letra, palavra[100];
	int totOcorrencias = 0;
	
	printf("Digite uma palavra: \n");
	scanf("%s", palavra);
	
	printf("Digite uma letra: \n");
	scanf(" %c", &letra);
	
	for (int i = 0; i < strlen(palavra); i++){
		char c = tolower(palavra[i]);
		if(c == letra){
			totOcorrencias++;
		}
	}
	
	printf("\n A letra %c apareceu %d vez(es). ", letra, totOcorrencias);
	
	return 0;
	
}