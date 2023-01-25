#include <stdio.h>

//Vuole due parametri da riga di comando
int main(int argc, char **argv) {
    char* temp;
    printf("%s %s\n", argv[1], argv[2]);
    temp = argv[1];
    argv[1] = argv[2];
    argv[2] = temp;
    printf("%s %s\n", argv[1], argv[2]);
    return 0;
}