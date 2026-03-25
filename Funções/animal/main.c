#include <stdio.h>
#include <stdio.h>
#include "Animal.c"

int main(){
	char p1[20], p2[20], p3[20];
	
	scanf("%s", p1);
	scanf("%s", p2);
	scanf("%s", p3);
	
	Animal(p1, p2, p3);
	
	return 0;

}