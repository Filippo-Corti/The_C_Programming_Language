#include <stdio.h>
#include <stdlib.h>

// Due parametri da riga di comando
int main(int argc, char **argv) {
    int ora = atoi(argv[1]);
    int min = atoi(argv[2]);
    float orario = ora * 1 + (float)min / 60;
    if ((orario >= 5.50) && (orario <= 12.50)) {
        printf("Mattino!\n");
    }
    return 0;
}