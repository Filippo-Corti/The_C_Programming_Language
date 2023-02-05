// Find the largest palindrome number made from the product of two 3-digit numbers:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sizeOfNumber(int n) {
    int size;
    for (size = 0; n > 0; size++, n /= 10);
    return size;
}

char* itoa(int n) {
    int sizeOfN = sizeOfNumber(n);
    char* nStr = malloc(sizeof(char) * sizeOfN + 1);
    for (int i = 0; i < sizeOfN; i++, n /= 10) {
        int digit = n % 10;
        nStr[sizeOfN - i - 1] = digit + '0';
    }
    return nStr;
}

int isPalindrome(const char* str) {
    for (int i = 0; i < strlen(str); i++)
        if (str[i] != str[strlen(str) - i - 1])
            return 0;
    return 1;
}

int isPalindromeNumber(int n) {
    return isPalindrome(itoa(n));
}

int main() {
    int max = 0, maxI = 0, maxJ = 0;
    for (int i = 100; i < 1000; i++) 
        for (int j = i; j < 1000; j++) 
            if (isPalindromeNumber(i * j) && max < i * j) {
                max = i * j;
                maxI = i;
                maxJ = j;
            }
    printf("%d * %d = %d\n", maxI, maxJ, max);
}