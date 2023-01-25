#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int TARGET = 50;

int main() {
    srand(time(NULL));
    int sum = 0;
    while (sum < TARGET) {
        int random = rand() % 10 + 1;
        printf("%d\t", random);
        sum += random;
    }
    printf("\n%d\n", sum);
}