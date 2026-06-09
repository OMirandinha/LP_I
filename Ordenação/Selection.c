#include <stdio.h>

void Selection_Sort(int a[], int length) {
    for (int i = 0; i < length - 1; i++) {
        int min_pos = i;

        for (int j = i + 1; j < length; j++) {
            if (a[j] < a[min_pos]) {
                min_pos = j;
            }
        }

        if (min_pos != i) {
            int temp = a[i];
            a[i] = a[min_pos];
            a[min_pos] = temp;
        }
    }
}

int main() {
    int a[] = {5, 3, 7, 8, 0, 9, 6, 2, 4, 1};
    int length = 10;
 
    Selection_Sort(a, length);
    
    printf("Array ordenado pelo Selection Sort:\n");
    for (int i = 0; i < length; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }
    
    return 0;
}