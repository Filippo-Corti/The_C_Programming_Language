#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Per qualche strano motivo la math.h viene compilata correttamente solo se si aggiunge "-lm" alla fine del comando gcc ...

const char* VOCALI = "aeiouAEIOU";
const char* CIFRE = "0123456789";

//Without "const" I can't pass VOCALI to the function.
//Apparently this is used quite a lot in C whenever the function receives a pointer but doesn't modify the data pointed to.
int strContainsAny(const char* str1, const char* str2) {
    for (int i = 0; i < strlen(str1); i++) {
        if (strchr(str2, str1[i])) 
            return 1;
    }
    return 0;
}

int strCount(const char* str, char c) {
    int count;
    for (count = 0; str[count]; str[count] == c ? count++ : *str++) {} //L'ho trovata su internet e mi faceva ridere quindi l'ho copiata perché era geniale, si può fare anche in maniera più "normale"
    return count;
}

//Returns index of the last instance of any char of str2 found in str1
int reverseStrcspn(const char* str1, const char* str2) {
    for (int i = strlen(str1) - 1; i >= 0; i--) {
        if (strchr(str2, str1[i]))
            return i;
    }
    return -1;
}

char* strRepeat(const char* str, int n) {
    char* newStr = malloc(sizeof(char) * strlen(str) * n);
    for (int i = 0; i < strlen(str) * n; newStr[i] = str[i % strlen(str)], i++);
    return newStr;
}

char* strRepeatChr(const char c, int n) {
    char* newStr = malloc(sizeof(char) * n);
    for (int i = 0; i < n; newStr[i] = c, i++);
    return newStr;
}

char* extractDigits(const char* str) {
    char* intStr = malloc(sizeof(char) * strlen(str));
    for (int i = 0; i < strlen(str); i++) {
        if (strchr(CIFRE, str[i])) {
            intStr[strlen(intStr)] = str[i];
        }
    }
    return intStr;
} 

//Un parametro da riga di comando
int main(int argc, char **argv) {
    char s1 = 'c';
    char s2[10] = "sc";
    
    if (strstr(argv[1], s2)) 
        printf("%s contiene %s\n", argv[1], s2);
    if (strContainsAny(argv[1], VOCALI)) 
        printf("%s contiene almeno una vocale\n", argv[1]);
    printf("%s contiene %d %c\n", argv[1], strCount(argv[1], s1), s1);
    int firstVowel = strcspn(argv[1], VOCALI);
    if (firstVowel != strlen(argv[1]))
        printf("Prima vocale di %s in posizione %d\n", argv[1], firstVowel + 1);
    int lastVowel = reverseStrcspn(argv[1], VOCALI);
    if (lastVowel != -1)
        printf("Ultima vocale di %s in posizione %d\n", argv[1], lastVowel + 1);
    printf("%s\n", strRepeat(s2, 3));
    printf("%s\n", strRepeatChr(s1, 5));
    char* extracted = extractDigits(argv[1]); //Apparently atoi() does extracts the numbers even if the string has other symbols in it
    printf("%d\n", atoi(extracted)); 
    printf("%f\n", (float)atoi(extracted) / pow(10.0, (double)strlen(extracted)));
}