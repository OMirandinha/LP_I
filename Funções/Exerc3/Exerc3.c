#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

int abreviar_frase(char *frase, char *palavra){
    int i, j, tamanho = 0;

    for(i = 0; i <= strlen(frase); i++){

        if(frase[i] != ' ' && frase[i] != '\0'){
            palavra[tamanho] = frase[i];
            tamanho++;


        }

        else{
            palavra[tamanho] = '\0';


            if(tamanho > 4){
                char inicio = palavra[0];
                char finalizador = palavra[tamanho-1];
                //char totChar = tamanho + '0';

                printf("\n %c %i %c", inicio, tamanho - 2, finalizador);
                tamanho = 0;

                palavra[0] = '\0';

            } else{
                 printf("\n %s", palavra);
            }


            }
    }




}

int main(){
    char frase[100], fraseFinal[100];

    printf("Digite uma frase:");
    scanf("\n %[^\n]", frase);

    abreviar_frase(frase, fraseFinal);

    //printf("%s", frase);

}
