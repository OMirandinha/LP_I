#include <stdio.h>
#include <string.h>

void separar(char *nome) {
    int i = 0;
	int j =0;
	char primeiroNome[50];
	char sobrenome[50];

    while (nome[i] != ' ' && nome[i] != '\0') {
        primeiroNome[i] = nome[i];
        i++;
    }
	
    primeiroNome[i] = '\0'; 
	
	strrev(nome);
	
	while(nome[j] != ' ' && nome[j] != '\0'){
		sobrenome[j] = nome[j];
		j++;
	}
	
	sobrenome[j] = '\0';
	
	strrev(sobrenome);
	printf("%s, %s", primeiroNome, sobrenome);
}

int main(){
	char nome[101];
	
	printf("\n Digite seu nome completo:");
	scanf("\n%[^\n]", nome);
	
	separar(nome);
	
	
}