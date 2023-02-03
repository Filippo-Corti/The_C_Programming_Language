#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Split function: */

int indexOf(const char* str, char c) {
    char* firstInstance = strchr(str, c);
    if (firstInstance == NULL) {
        return -1;
    }
    return firstInstance - str;
}

char** Split(const char* string, char separator) {
    int stringLength = strlen(string);
    char** tokens = (char**)malloc(sizeof(char*) * stringLength);
    char* token;
    for(int i = 0; string; i++) {
        int firstIndex = indexOf(string, separator);
        switch(firstIndex) {
            case -1: //No more tokens
                if (strlen(string) > 0) { //This prevents an extra empty token in case the string ends with a separator
                    token = (char*)malloc(sizeof(char) * strlen(string) + 1);
                    strcpy(token, string);
                    tokens[i] = token;
                }
                return tokens;
            case 0: //There's a multiple separator character in the string
                string += firstIndex + 1;
                i--;
                break;
            default:
                token = (char*)malloc(sizeof(char) * firstIndex + 1);
                strncpy(token, string, firstIndex);
                tokens[i] = token;
                string += firstIndex + 1;
                break;
        }
    }
}

char** Fields(const char* string) {
    return Split(string, ' ');
}



int main() {
    char* stringa = "Questo pomeriggio non ha nevicato";
    char** parole = Fields(stringa);
    int n;
    for (n = 0; parole[n]; n++);
    for (int i = n - 1; i >= 0; i--) {
        printf("%s ", parole[i]);
    }
    printf("\n");
}