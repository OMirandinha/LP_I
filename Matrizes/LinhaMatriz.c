#include <stdio.h>

int main(){
    float M[12][12], somatoria, media;
    int S;
    char T;
    somatoria = 0;
    
    // REMOVA estes prints - o Beecrowd não espera textos
    // printf("Qual linha deseja considerar para a operação? \n");
    scanf("%d", &S);
    
    // printf("Qual operação deseja realizar (S - Soma / M - Média)");
    scanf(" %c", &T);
    
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12; j++){
            scanf("%f", &M[i][j]);  // CORRIGIDO: %f para float
            if (i == S){
                somatoria += M[i][j];
            }
        }
    }
    
    media = somatoria / 12;
    
    if(T == 'S' || T == 's'){           // CORRIGIDO: aspas simples
        printf("%.1f\n", somatoria);     // CORRIGIDO: formato e quebra de linha
    } else if (T == 'M' || T == 'm'){    // CORRIGIDO: == e aspas simples
        printf("%.1f\n", media);          // CORRIGIDO: formato e quebra de linha
    }
    
    return 0;  // Boa prática adicionar return 0
}