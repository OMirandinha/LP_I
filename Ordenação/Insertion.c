#include <stdio.h>

void Insertion_Sort(int a[], int length){
	
	for(int i = 1; i < length; i++){
		int key = a[i];
		int j = i - 1;
		
		while(j >= 0 && a[j] > key){
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;
	}
}
int main(){

	int a[] = {8,4,9,5,7,6,3,2};
	int length = 8;
	
	Insertion_Sort(a, length);
	
	for(int i = 0; i < length; i++){
		printf("a[%d] = %d\n", i, a[i]);
	}
	
	return 0;
}