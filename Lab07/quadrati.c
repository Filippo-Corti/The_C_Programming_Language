#include <stdlib.h>
#include <stdio.h>
#include <math.h> //Build with gcc -o quadrati quadrati.c -lm

int isSquare(int n) {
    int squareRoot = (int)sqrt((double)n);
    return squareRoot * squareRoot == n;
}
 
//N parametri da riga di comando
int main(int argc, char** argv) {
    for (int i = 1; i < argc; i++) {
        int intValue = atoi(argv[i]);
        if (intValue != 0 && isSquare(intValue)) {
            printf("%d is a perfect square\n", intValue);
        }
    }
}