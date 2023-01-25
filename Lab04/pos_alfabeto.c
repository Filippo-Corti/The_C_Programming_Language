#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isLetteraMinuscola(char c) {
    return (c >= 'a') && (c <= 'z');
}

int main() {
    char stringa[100];
    scanf("%s", &stringa);
    for (int i = 0; i < strlen(stringa); i++) {
        if (isLetteraMinuscola(stringa[i])) //Lettera 
            printf("%c\t%d-esima lettera \n", stringa[i], stringa[i] - 'a' + 1);
        else  //Altro
            printf("%c\tnon una lettera minuscola\n", stringa[i]);
    }
}