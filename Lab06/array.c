#include <stdio.h>
#include <stdlib.h>

const int DIM = 5;

void printArray(int *a, int n) {
    for (int i = 0; i < n; i++) 
        printf("%d\t", a[i]);
    printf("\n");
}

void reverse(int *a, int n) {
    for (int i = 0; i < n / 2; i++) {
        int temp = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1] = temp;
    }
}

void switchFirstLast(int *a, int n) {
    int temp = a[0];
    a[0] = a[n - 1];
    a[n - 1] = temp;
} 

int main() {
    int array[] = {0, 1, 2, 3, 4}; //Compiler doesn't allow me to use [DIM] idk why
    printArray(array, DIM);
    reverse(array, DIM);
    printArray(array, DIM);
    switchFirstLast(array, DIM);
    printArray(array, DIM);
}