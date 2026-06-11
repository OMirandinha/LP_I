#include <stdio.h>
#include <string.h>

typedef struct{
	char titulo[31];
	char autor[16];
	int ano;
} livro;

int Procurar(livro l[], char p[]){
	for(int i = 0; i < 5; i++){
		if(strcmp(l[i].titulo, p) == 0)
			return i;
	}
	return -1;
	
}

int main(){
	livro l[5];
	char pesquisa[31];
	
	for(int i = 0; i < 5; i++){
		printf("\nDigite o título do livro %d:", i+1);
		scanf(" %[^\n]", l[i].titulo);
		
		printf("\nDigite o autor do livro %d: ", i+1);
		scanf(" %[^\n]", l[i].autor);
		
		printf("\nDigite o ano do livro %d: ", i+1);
		scanf("%d", &l[i].ano);
	}
	
	printf("\nPor qual título deseja pesquisar?");
	scanf(" %[^\n]", pesquisa);
	
	int resultado = Procurar(l, pesquisa);
	
	if(resultado != - 1){
		printf("\nLivro encontrado na poisão %d", resultado + 1);
	} else{
		printf("\nObra não encontrada.");
	}
	
	return 0;
	
}

