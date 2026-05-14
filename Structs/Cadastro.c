#include <stdio.h>

typedef struct{
    char nome[256];
    char endereco[256];
    int idade;
} dadosPessoa;

int main(){
    dadosPessoa dd;
    
    printf("\nDigite seu nome: ");
    fgets(dd.nome, 256, stdin);
    // Remove o \n do final
    dd.nome[strcspn(dd.nome, "\n")] = 0;
    
    printf("\nDigite sua idade: ");
    scanf("%d", &dd.idade);
    while(getchar() != '\n');  // Limpa buffer
    
    printf("\nDigite seu endereco: ");
    fgets(dd.endereco, 256, stdin);
    dd.endereco[strcspn(dd.endereco, "\n")] = 0;
    
    printf("\n%s, %d, %s", dd.nome, dd.idade, dd.endereco);
    printf("\nCadastro realizado com sucesso\n");
    
    return 0;
}