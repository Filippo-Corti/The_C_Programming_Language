#include <stdio.h>
#include <stdlib.h>

//Un parametro da riga di comando
int main(int argc, char **argv) {
    int num = atoi(argv[1]);
    if (num > 0) {
        printf("Positivo!\n");
    } else if (num < 0) {
        printf("Negativo!\n");
    } else {
        printf("Zero!\n");
    }
}