#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int DIM = 10;

//Prototypes
void printArray(int *a, int n);
int contaCifre(char* str, int *contatoreCifre);
int isDigit(char c);

int main() {
    int contaStringheConCifre = 0;
    int contatoreCifre[10] = {0}; //sets everything to zero
    char input[100];
    do {
        scanf("%s", &input);
        if (!strcmp(input, "stop")) {
            printf("esce qua\n");
            break;
        }
        if (contaCifre(input, contatoreCifre)) 
            contaStringheConCifre++;
    } while (1);
    printf("%d stringhe con cifre\n", contaStringheConCifre);
    printf("0 1 2 3 4 5 6 7 8 9\n");
    printArray(contatoreCifre, DIM);
}

void printArray(int *a, int n) {
    for (int i = 0; i < n; i++) 
        printf("%d ", a[i]);
    printf("\n");
}

int contaCifre(char* str, int *contatoreCifre) {
    int hasCifre = 0; //false
    for (int i = 0; i < strlen(str); i++) {
        if (isDigit(str[i])) {
            contatoreCifre[str[i] - '0']++;
            hasCifre = 1; //true
        }
    }
    return hasCifre;
}

int isDigit(char c) {
    return c >= '0' && c <= '9';
}