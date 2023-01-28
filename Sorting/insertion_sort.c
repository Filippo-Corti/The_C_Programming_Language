#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int MAX = 100;

int* creaRandomArray(int n) {
    int* a = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100;
    }
    return a;
}

void printArray(int* a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void insertionsort(int *a, int n) {
   for (int i = 1; i < n; i++) {
        for(int j = i; j >= 0 && a[j - 1] > a[j]; j--) {
            int temp = a[j - 1];
            a[j - 1] = a[j];
            a[j] = temp;
        }
   }
}

int main(int argc, char **argv) {
    srand(time(NULL));
    int n = atoi(argv[1]);
    int* array = creaRandomArray(n);
    printArray(array, n);
    insertionsort(array, n);
    printArray(array, n);
}