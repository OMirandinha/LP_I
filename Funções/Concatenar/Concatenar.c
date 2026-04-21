#include <stdio.h>
#include <string.h>

void Concatenar(char *s1, char *s2) {
    int tamanho = strlen(s1) / 2;          
    char temp[100];                        

    // 1. Copia a primeira metade de s1 para temp
    strncpy(temp, s1, tamanho);
    temp[tamanho] = '\0';      
	
    // 2. Concatena s2 no final de temp
    strcat(temp, s2);

    // 3. Concatena o restante de s1 (segunda metade) no final de temp
    strcat(temp, s1 + tamanho);

    // 4. Copia o resultado de volta para s1
    strcpy(s1, temp);
}

int main() {
    char s1[100], s2[100]; 

    printf("Digite uma string: ");
    scanf("%s", s1);
    printf("Digite outra string: ");
    scanf("%s", s2);

    Concatenar(s1, s2);

    printf("Resultado: %s\n", s1);
    return 0;
}