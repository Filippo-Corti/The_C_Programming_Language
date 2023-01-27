#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Implementazione in linguaggio C della funzione strings.Split() di Go*/

// indexOf returns the index (starting from 0) of the first instance of the char c inside the string str
int indexOf(const char* str, char c) {
    char* firstInstance = strchr(str, c);
    if (firstInstance == NULL) {
        return -1;
    }
    return firstInstance - str;
}

char** Split(const char* string, char separator) {
    int stringLength = strlen(string);
    char** tokens = malloc(sizeof(char*) * stringLength);
    char* token;
    for(int i = 0; string; i++) {
        int firstIndex = indexOf(string, separator);
        switch(firstIndex) {
            case -1: //No more tokens
                if (strlen(string) > 0) { //This prevents an extra empty token in case the string ends with a separator
                    token = malloc(sizeof(char) * strlen(string) + 1);
                    strcpy(token, string);
                    tokens[i] = token;
                }
                return tokens;
            case 0: //There's a multiple separator character in the string
                string += firstIndex + 1;
                i--;
                break;
            default:
                token = malloc(sizeof(char) * firstIndex + 1);
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

int main(int argc, char **argv) {
    char** tokens = Split(argv[1], argv[2][0]);
    // char** tokens = Fields(argv[1]);
    for (int i = 0; tokens[i]; i++) {
        printf("%s\n", tokens[i]);
    }
}