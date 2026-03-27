/*Primeiro e Último Nome

Em muitos sistemas, nomes completos são armazenados em uma única string e precisam ser separados para exibição ou cadastro.

Escreva um programa em C que leia o nome completo de uma pessoa (com até 100 caracteres) e exiba, através de uma FUNÇÃO,
apenas o último e o primeiro nome separado por vírgula.
Exemplo de entrada:
Maria Clara Souza Oliveira
Exemplo de saída:
Oliveira, Maria

função strrev*/

#include <stdio.h>
#include <string.h>

void Separar(char nomeCompleto[101]){
    char primeiroNome[21], ultimoNome[21];
    int i = 0;

    for(i = 0; i < strlen(nomeCompleto); i++){
        if(nomeCompleto[i] != ' '){
            primeiroNome[i] = nomeCompleto[i];
        } else{
            break;
        }
    }
    primeiroNome[i] = '\0';

    int j = 0;
    for(i = strlen(nomeCompleto) - 1, j = 0; i > 0; i++){
        if(nomeCompleto[i] != ' '){
            ultimoNome[j] = nomeCompleto[i];
            j++;
        } else{
            break;
        }
}

    ultimoNome[j] = '\0';
    strrev(ultimoNome);

    printf("%s , %s \n", primeiroNome, ultimoNome);

}

int main(){
    char nomeCompleto[101];
    printf("Digite seu nome completo: \n");
    scanf("%[^\n]", nomeCompleto);

    Separar(nomeCompleto);

}

