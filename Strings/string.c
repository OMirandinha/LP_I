#include <stdio.h>
#include <string.h>
#include <Ctype.h>

int main(){
    char letra = 'A';
    char string[20] = {"oi alunos"};

   // printf("Informe uma letra: \n");
    //scanf(" %c", &letra);

    printf("Informe um nome:");
    scanf("%s", string);

    printf("Letra : %c \n Nome: %s", letra, string);
    printf("\n %p Endereço de memória do índice zero", string);

    printf("Tamanho da String: %i \n", strlen(string));

    for(int i = 0; i <strlen(string); i++){
        printf("\n %c %p", string[i], &string[i]);
    }

    strcpy(string, "Matheus");
    printf("\n Depois do strcpy: %s", string);

    //if (string == "Matheus"){
    if (strcmpi(string, "Matheus") == 0){
        printf("\n São iguais");
    } else{
        printf("\n São diferentes");
    }

    printf("\n Maiúsculo: %s", strupr(string));
    printf("\n Minúsculo: %s", strlwr(string));

    printf("\n Caracter Minúsculo: %c", tolower(string[0]));
    printf("\n Caracter Maiúsculo: %c", toupper(string[0]));

    return 0;

}
