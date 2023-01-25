#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isUpper(char c) {
    return (c >= 'A') && (c <= 'Z');
}

int isLower(char c) {
    return (c >= 'a') && (c <= 'z');
}

int isLetter(char c) {
    return isUpper(c) || isLower(c);
}

int isDigit(char c) {
    return (c >= '0') && (c <= '9');
}

int hasUpper(char* str) {
    for (int i = 0; i < strlen(str); i++)
        if (isUpper(str[i]))
            return 1;
    return 0;
}

int firstUpper(char* str) {
    for (int i = 0; i < strlen(str); i++)
        if (isUpper(str[i]))
            return i;
    return -1;
}

int lastUpper(char* str) {
    for (int i = strlen(str) - 1; i >= 0; i--) {
        if (isUpper(str[i]))
            return i;
    }
    return -1;
}

void countDigitsLettersOthers(char* str, int* digits, int* letters, int* others) {
    for (int i = 0; i < strlen(str); i++) {
        if (isDigit(str[i]))
            (*digits)++;
        else if (isLetter(str[i]))
            (*letters)++;
        else    
            (*others)++;
    }
}

int isPalindrome(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) 
            return 0;
    }
    return 1;
}

//Un parametro da riga di comando
int main(int argc, char **argv) {
    if (hasUpper(argv[1]))
        printf("Ha almeno una lettera maiuscola\n");
    else 
        printf("Non ha lettere maiuscole\n");
    printf("Prima lettera maiuscola in posizione %d\n", firstUpper(argv[1]) + 1);
    printf("Ultima lettera maiuscola in posizione %d\n", lastUpper(argv[1]) + 1);
    int digits = 0, letters = 0, others = 0;
    countDigitsLettersOthers(argv[1], &digits, &letters, &others);
    printf("Cifre: %d\tLettere: %d\tAltro: %d\n", digits, letters, others);
    if (isPalindrome(argv[1]))
        printf("Palindroma\n");
    else 
        printf("Non palindroma\n");
}