#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char linha[10000];

    // Lê cada linha da entrada até o fim do arquivo (EOF)
    while (fgets(linha, sizeof(linha), stdin)) {
        
        // Remove caracteres de nova linha (\n ou \r) que o fgets pode capturar
        linha[strcspn(linha, "\n\r")] = 0;

        // Se a linha estiver vazia, pula para a próxima
        if (strlen(linha) == 0) continue;

        // Divide a linha em tokens (cada número octal separado por espaço)
        char *token = strtok(linha, " ");
        while (token != NULL) {
            // Converte a string octal para um inteiro (base 8)
            int val = (int)strtol(token, NULL, 8);
            char c = '\0';

            // Lógica de conversão EBCDIC para ASCII incorporada
            if (val == 0100) { // Espaço (Octal 100)
                c = ' ';
            } 
            else if (val >= 0201 && val <= 0211) { // a-i
                c = 'a' + (val - 0201);
            } 
            else if (val >= 0221 && val <= 0231) { // j-r
                c = 'j' + (val - 0221);
            } 
            else if (val >= 0242 && val <= 0251) { // s-z
                c = 's' + (val - 0242);
            } 
            else if (val >= 0301 && val <= 0311) { // A-I
                c = 'A' + (val - 0301);
            } 
            else if (val >= 0321 && val <= 0331) { // J-R
                c = 'J' + (val - 0321);
            } 
            else if (val >= 0342 && val <= 0351) { // S-Z
                c = 'S' + (val - 0342);
            } 
            else if (val >= 0360 && val <= 0371) { // 0-9
                c = '0' + (val - 0360);
            }

            // Se o caractere foi identificado, imprime-o sem pular linha
            if (c != '\0') {
                putchar(c);
            }

            // Pega o próximo token (próximo número da linha)
            token = strtok(NULL, " ");
        }

        // Ao final de cada linha de entrada, imprime uma quebra de linha
        putchar('\n');
    }

    return 0;
}