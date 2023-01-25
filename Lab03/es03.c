#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int K = 10;

int main() {
    srand(time(NULL));
    for (int i = 0; i < K; i++) {
        int random = rand() % (K + 1);
        printf("%d\t", random);
    }
    printf("\n");
}