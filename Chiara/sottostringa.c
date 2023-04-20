#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Returns 0 if s2 is substring of s1.
// Returns 1 otherwise
int isSubstring(char* s1, char* s2) {
    int mainstrLen = strlen(s1);
    int substrLen = strlen(s2);
    for (int i = 0; i < mainstrLen - substrLen + 1; i++) {
        if (strncmp(&s1[i], s2, substrLen) == 0) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char** argv) {
    char* s1 = argv[1];
    char* s2 = argv[2];
    printf("%d\n", isSubstring(s1, s2));
}