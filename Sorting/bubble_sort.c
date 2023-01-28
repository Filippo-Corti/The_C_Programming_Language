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

void bubblesort(int *a, int n) {
    int anyChange = 1;
    for (int i = 0; i < n && anyChange; i++) {
        anyChange = 0;
        for (int j = i; j < n; j++) { 
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                anyChange = 1;
            }
        }
    }
}

int main(int argc, char **argv) {
    srand(time(NULL));
    int n = atoi(argv[1]);
    int* array = creaRandomArray(n);
    printArray(array, n);
    bubblesort(array, n);
    printArray(array, n);
}