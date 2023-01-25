#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Vuole un parametro da riga di comando
int main(int argc, char **argv) {
    srand(time(NULL));
    int range = atoi(argv[1]);
    int random = rand() % range + 1;
    printf("%d\n", random);
    return 0;
}  