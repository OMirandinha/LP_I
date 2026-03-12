#include <stdio.h>
#include <string.h>

void substring(char strorigem[21],
               char strdestino[21],
               int inicio,
               int fim){
    int i, j;
    for(i = inicio, j = 0; i <= fim; i++, j++){
        strdestino[j] = strorigem[i];

    }
    strdestino[j] = '\0';

}
