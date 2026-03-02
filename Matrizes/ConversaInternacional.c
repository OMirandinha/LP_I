#include <stdio.h>
#include <string.h>

int main(){
    int N, K;
    char S[100][20];
    
    scanf("%d", &N);
    
    // Leitura de todos os casos
    for(int i = 0; i < N; i++){
        scanf("%d", &K);
        for(int j = 0; j < K; j++){ 
            scanf("%s", S[j]);       
        }
        
        // Verifica se todos os K idiomas são iguais
        int todosIguais = 1;
        for(int j = 1; j < K; j++){
            if(strcmp(S[j], S[0]) != 0){  // strcmp compara strings
                todosIguais = 0;
                break;
            }
        }
        
        // Imprime o resultado para este caso
        if(todosIguais){
            printf("%s\n", S[0]);
        } else {
            printf("ingles\n");
        }
    }
    
    return 0;
}