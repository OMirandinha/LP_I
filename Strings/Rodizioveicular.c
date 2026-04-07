#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Função para validar se a placa segue o padrão AAA-9999
int validar_placa(char *placa) {
    if (strlen(placa) != 8) return 0; // Tamanho deve ser exatamente 8

    // Verifica se os 3 primeiros são letras maiúsculas
    for (int i = 0; i < 3; i++) {
        if (placa[i] < 'A' || placa[i] > 'Z') return 0;
    }

    // Verifica o hífen
    if (placa[3] != '-') return 0;

    // Verifica se os 4 últimos são dígitos
    for (int i = 4; i < 8; i++) {
        if (!isdigit(placa[i])) return 0;
    }

    return 1; // Placa válida
}

int main() {
    int casos;
    char placa[101];

    if (scanf("%d", &casos) == EOF) return 0;

    while (casos--) {
        scanf("%s", placa);

        if (!validar_placa(placa)) {
            printf("FAILURE\n");
        } else {
            // O último caractere da placa está na posição 7
            char ultimo = placa[7];

            switch (ultimo) {
                case '1':
                case '2':
                    printf("MONDAY\n");
                    break;
                case '3':
                case '4':
                    printf("TUESDAY\n");
                    break;
                case '5':
                case '6':
                    printf("WEDNESDAY\n");
                    break;
                case '7':
                case '8':
                    printf("THURSDAY\n");
                    break;
                case '9':
                case '0':
                    printf("FRIDAY\n");
                    break;
            }
        }
    }

    return 0;
}