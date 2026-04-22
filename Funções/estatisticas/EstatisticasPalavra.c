#include <stdio.h>
#include <string.h>

int Total(char *frase){
	int totPalavra =1;
	for(int i = 0; i < strlen(frase);i++){
		if(frase[i] == ' '){
			totPalavra++;
		}
	}
	
	printf("\nTotal de plavras: %i", totPalavra);
}

int MaisLonga(char *frase){
    char palavra[30], final[30];
    int maior = 0;          
    int j = 0;               

    for (int i = 0; i < strlen(frase); i++) {
        if (frase[i] != ' ' && frase[i] !='\0') {
            palavra[j++] = frase[i];   
        } else {
            palavra[j] = '\0';         
            if (strlen(palavra) > maior) {
                maior = strlen(palavra);
                strcpy(final, palavra); 
            }
            j = 0;                    
        }
    }

    if (j > 0) {
        palavra[j] = '\0';
        if (strlen(palavra) > maior) {
            maior = strlen(palavra);
            strcpy(final, palavra);
        }
    } 

    printf("\n A maior palavra é: %s com %i caracteres", final, maior);
	
}

int MaisCurta(char *frase){
	char palavra[30], final[30];
	int menor = 30;
	int j = 0;
	int i = 0;
	
	for(i = 0; i <strlen(frase); i++){
		if(frase[i] != ' ' && frase[i] != '\0'){
			palavra[j++] = frase[i];
		} else{
			palavra[j] = '\0';
			if(strlen(palavra) < menor){
				menor = strlen(palavra);
				strcpy(final, palavra);
			}
			j = 0;
		}
	}
	
	printf("\nA palavra mais curta é: %s com %i caracteres", final, menor);
}

int Media(char *frase){
	int totChar = 0;
	int totPalavra = 1;
	float media = 0;
	
	for(int i = 0; i < strlen(frase); i++){
		totChar++;
		if(frase[i] == ' '){
			totPalavra++;
		}
	}

	media = totChar/totPalavra;
	
	printf("\nA média de caracteres é: %.2f", media);
	
}

int main(){
	char frase[256];
	printf("Digite uma frase:");
	scanf("\n %[^\n]", frase);
	
	Total(frase);
	MaisLonga(frase);
	MaisCurta(frase);
	Media(frase);
	
	return 0;
}