#include <stdio.h>
#include <string.h>  
#include <ctype.h>    

void Verificador(char *s, int *s1, int *s2) {
    int SeqNum[10];   
    int pos = 0;    

    // Percorre a string de entrada (até 12 caracteres, incluindo '\0')
    for (int i = 0; s[i] != '\0' && pos < 10; i++) {
        if (s[i] != '-') {
            if (s[i] == 'X') {
                SeqNum[pos] = 10;
            } else if (s[i] >= '0' && s[i] <= '9') {
                SeqNum[pos] = s[i] - '0';
            } else {
                // Caractere inválido
                printf("\nISBN Inválido (caractere não permitido)\n");
                return;
            }
            pos++;
        }
    }

    if (pos != 10) {
        printf("\nISBN Inválido (número de dígitos incorreto)\n");
        return;
    }

    // Calcula soma ponderada: soma = Σ (posição * dígito)   (posição de 1 a 10)
    int soma = 0;
    for (int i = 0; i < 10; i++) {
        soma += (i + 1) * SeqNum[i];
    }

    if (soma % 11 == 0) {
        printf("\nISBN Válido\n");
    } else {
        printf("\nISBN Inválido\n");
    }
}

int main() {
    char ISBN[12];     // comporta 10 dígitos + hífens + '\0'
    // Os arrays s1 e s2 não são mais necessários, mas mantemos a assinatura da função
    int s1[11], s2[11];   // (não usados, apenas para compatibilidade)

    while (1) {
        printf("Digite o ISBN da obra (ou FIM para encerrar): ");
        scanf("%11s", ISBN);   // lê no máximo 11 caracteres + '\0'

        // Converte a string para maiúsculas para comparar com "FIM"
        for (int i = 0; ISBN[i]; i++) {
            ISBN[i] = toupper(ISBN[i]);
        }

        if (strcmp(ISBN, "FIM") == 0) {
            break;
        }

        Verificador(ISBN, s1, s2);
    }

    printf("\nPrograma finalizado\n");
    return 0;
}