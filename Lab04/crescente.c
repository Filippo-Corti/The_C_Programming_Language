#include <stdio.h>
#include <string.h>

//Un parametro da riga di comando
int main(int argc, char **argv) {
    char prev = argv[1][0], curr;
    printf("%c", prev);
    for (int i = 1; i < strlen(argv[1]); i++) {
        curr = argv[1][i];
        if (curr < prev) {
            printf("-");
        }
        printf("%c", curr);
        prev = curr;
    }
    printf("\n");
}