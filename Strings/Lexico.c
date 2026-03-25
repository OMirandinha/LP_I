#include <stdio.h>
#include <string.h>
#include <ctype.h>

void to_lower(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    char palavra1[21], palavra2[21];

    scanf("%20s", palavra1);
    scanf("%20s", palavra2);

    to_lower(palavra1);
    to_lower(palavra2);

    if (strcmp(palavra1, palavra2) <= 0) {
        printf("%s\n", palavra1);
        printf("%s\n", palavra2);
    } else {
        printf("%s\n", palavra2);
        printf("%s\n", palavra1);
    }

    return 0;
}