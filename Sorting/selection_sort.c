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

void selectionsort(int *a, int n) {
   for (int i = 0; i < n; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        int temp = a[minIndex];
        a[minIndex] = a[i];
        a[i] = temp;
   }
}

int main(int argc, char **argv) {
    srand(time(NULL));
    int n = atoi(argv[1]);
    int* array = creaRandomArray(n);
    printArray(array, n);
    selectionsort(array, n);
    printArray(array, n);
}