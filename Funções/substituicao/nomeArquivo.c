#include <stdio.h>
#include "substituir.c" 

int main() {
    char nome[50];
    
    printf("Digite o nome completo do arquivo (ex: imagem.bmp): \n");
    
    scanf("%49s", nome);
    
    substituir(nome);
    
    printf("Nome modificado: %s\n", nome);
    
    return 0;
}