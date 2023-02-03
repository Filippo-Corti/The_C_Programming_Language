#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Programma che date due stringhe trovi la sottostringa comune più lunga */

int contains(char *haystack, char *needle);
char* findLongestSubstring(char *s1, char *s2);

int main() {
    printf("%s\n", findLongestSubstring("supercalifragilistichespiralidoso", "materie_plastiche"));
}

/* Genero tutte le sottostringhe di una e controllo che siano presenti nell'altra*/

char* findLongestSubstring(char *s1, char *s2) {
    char* longestSubstring = malloc(sizeof(char) * strlen(s1));
    for (int i = 0; i < strlen(s1); i++) {
        for (int j = i; j < strlen(s1); j++) {
            char* dest = malloc(sizeof(char) * (j - i + 2));
            strncpy(dest, &s1[i], j - i + 1);
            if (contains(s2, dest) && strlen(dest) > strlen(longestSubstring)) {
                strcpy(longestSubstring, dest);
            }
        }
    }
    return longestSubstring;
}

int contains(char *haystack, char *needle) {
    for (int i = 0; i < strlen(haystack); i++) {
        if (strncmp(&haystack[i], needle, strlen(needle)) == 0) {
            return 1;
        }
    }
    return 0;
}