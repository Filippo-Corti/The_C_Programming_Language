// Int to Ascii (Apparently it doesn't exist in strings.h)
#include <stdio.h>
#include <stdlib.h>

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

int main() {
    int nInt = 139453511;
    char* nString = itoa(nInt);
    printf("%d = %s\n", nInt, nString);
}
