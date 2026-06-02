#include <stdio.h>

void HelloWorld(char *print){
	printf("%s", print);
}

int main(){
	char print[] = "Hello, World!";
	HelloWorld(print);
}