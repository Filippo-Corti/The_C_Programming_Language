#include <stdio.h>
#include <stdlib.h>

int main() {
    int x = 0, y = 0, z = 0;
    //This
    x = (y++) * (--z * 6) - (x = 7); 
    /*Is the same as:
    x = y * (z * 6) - 7; ! THIS IS THE FIRST ONE BEING EXECUTED
    y++;
    --z;
    */
    //Which is the reason why this prints x = -7
    printf("%d\t%d\t%d\n", x, y, z);
}