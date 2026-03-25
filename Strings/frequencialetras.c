#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    int casos;
    if (scanf("%d", &casos) != 1) return 0;
    

    getchar(); 

    for (int i = 0; i < casos; i++) {
        char texto[205]; 

        if (fgets(texto, sizeof(texto), stdin) == NULL) break;

        int contagem[26] = {0};

        for (int j = 0; texto[j] != '\0'; j++) {
            if (isalpha((unsigned char)texto[j])) {
                char c = tolower((unsigned char)texto[j]);
                contagem[c - 'a']++;
            }
        }

        int max = 0;
        for (int j = 0; j < 26; j++) {
            if (contagem[j] > max) {
                max = contagem[j];
            }
        }

        for (int j = 0; j < 26; j++) {
            if (contagem[j] == max && max > 0) {
                putchar('a' + j);
            }
        }
        putchar('\n');
    }

    return 0;
}