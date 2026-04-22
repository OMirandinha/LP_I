#include <stdio.h>

int main() {
    int i = 7;
    int *pti;
    pti = &i; 
    
    printf("\n%p", (void*)pti);   // endereço de i
    printf("\n%d", *pti);         // valor de i (7)
    printf("\n%p", (void*)&pti);  // endereço do ponteiro pti
    
    return 0;
}