#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned int x = 0;
    while (1) {
        printf("%u\n",  x); // ! Importante usare %u e non %d
        x--;
    }
}