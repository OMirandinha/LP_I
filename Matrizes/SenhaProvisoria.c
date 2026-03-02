#include <stdio.h>
#include <string.h>

int main(){
    int N;
    char ra[101];
    
    scanf("%d", &N);
    
    for(int i = 0; i < N; i++){
        scanf("%s", ra);
        
        if(strlen(ra) != 20 || ra[0] != 'R' || ra[1] != 'A'){
            printf("INVALID DATA\n");
            continue;
        }
        
        // Encontra o primeiro dígito não zero
        int inicio = -1;
        for(int k = 2; k < 20; k++){
            if(ra[k] < '0' || ra[k] > '9'){  // Se não for dígito
                inicio = -2;  // Marca como inválido
                break;
            }
            if(ra[k] != '0' && inicio == -1){
                inicio = k;
            }
        }
        
        if(inicio == -2){
            printf("INVALID DATA\n");
        }
        else if(inicio == -1){
            printf("0\n");
        }
        else {
            for(int k = inicio; k < 20; k++){
                printf("%c", ra[k]);
            }
            printf("\n");
        }
    }
    
    return 0;
}
