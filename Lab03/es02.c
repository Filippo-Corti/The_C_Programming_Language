#include <stdio.h>

const int K = 5;

int main() {
    int letto;
    for (int i = 0; i < K; i++) {
        scanf("%d", &letto);
        printf("%d\n", letto * 2);
    }
}