#include <stdio.h>

int isValidHour(int h) {
    return (h >= 0) && (h <= 23);
}

int isValidMinute(int min) {
    return (min >= 0) && (min <= 59);
}

int isValidTime(int h, int min) {
    return isValidHour(h) && isValidMinute(min);
} 

int main() {
    int h, min;
    do {
        scanf("%d %d", &h, &min);
        if (isValidTime(h, min)) {
            break;
        }
    } while (1); //while true
    printf("Valori validi\n");
}