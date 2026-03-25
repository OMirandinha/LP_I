#include <stdio.h>

void Cripto(char *origem, char *destino) {
    // Strings de controle (mesmo tamanho e sem repetições)
    char *ctrl1 = "aeiouAEIOU12345!@#";
    char *ctrl2 = "rtsnmRTSNM67890%&*";
    
    // Ponteiros auxiliares para busca
    char *p1, *p2;
    int achou;

    // Percorre a string de origem até o final ('\0')
    while (*origem != '\0') {
        achou = 0;
        p1 = ctrl1;
        p2 = ctrl2;

        // Tenta encontrar o caractere na primeira string de controle
        while (*p1 != '\0') {
            if (*origem == *p1) {
                // Calcula a distância do ponteiro para achar a posição equivalente
                *destino = *(ctrl2 + (p1 - ctrl1));
                achou = 1;
                break;
            }
            p1++;
        }

        // Se não achou na primeira, tenta na segunda
        if (!achou) {
            while (*p2 != '\0') {
                if (*origem == *p2) {
                    *destino = *(ctrl1 + (p2 - ctrl2));
                    achou = 1;
                    break;
                }
                p2++;
            }
        }

        // Se não achou em nenhuma, mantém o caractere original
        if (!achou) {
            *destino = *origem;
        }

        // Incrementa os ponteiros das strings de entrada e saída
        origem++;
        destino++;
    }

    // Adiciona o terminador nulo na string de destino
    *destino = '\0';
}