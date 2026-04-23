#include <stdio.h> 
void subschar(char *texto, char char1, char char2) 
{ 
  while (*texto != '\0') 
  { 
    if (*texto == char1) 
    *texto=char2; 
    texto++;    
  } 
} 
int main() 
{ 
  char c1[2], c2[2], texto[10]; 
  printf("Informe um texto: "); 
  scanf("%s",texto); 
  printf("Informe o caracter a ser excluido: "); 
  scanf("%s",c1); 
  printf("Informe o novo caracter: "); 
  scanf("%s",c2); 
  subschar(texto,*c1,*c2); 
  printf("Nova string: %s", texto);   
  return 0; 
} 
