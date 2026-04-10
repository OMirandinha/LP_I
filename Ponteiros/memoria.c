#include <stdio.h>

int main(){
	int x = 2, *px=&x, y = 3, *py=&y;
	
	printf("\n%i", *px);
	printf("\n%i", *py);
	
	printf("\n %d %d", x, y);
	printf("\n %d %d", *px, *py);
	printf("\n %d %d", &px, &py);
	
	// Alterando alvos
	px = py;
	printf("\n %d %d", *px, *py);
	printf("\n %d %d", &px, &py);
	
}