#include <stdio.h>

int main(){
	char str[10];
	printf("Digite uma string de até 10 caracteres: \n");
	scanf("%s", str);
	
	for(int i = 0; i < 10; i++){
		printf("\n %c, %p", str[i]);
	}
	
	return 0;
}