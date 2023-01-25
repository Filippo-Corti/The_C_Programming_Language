#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX = 100;
const int LETTERE_ALFABETO = 26;

void cifraCesare(char* stringa, char* cifrata, int chiave) {
    chiave = chiave % LETTERE_ALFABETO;
    for (int i = 0; i < strlen(stringa); i++) {
        cifrata[i] = 'a' + (stringa[i] + chiave - 'a') % LETTERE_ALFABETO;
    }
}

char* cifraCesareConReturn(char* stringa, int chiave) {
    chiave = chiave % LETTERE_ALFABETO;
    //cifrata non può essere dichiarata come una normale char*, in quanto verrebbe "cancellata" al termine dell'esecuzione della funzione
    //per tale motivo la alloco nello heap, piuttosto che nello stack
    char* cifrata = malloc(sizeof(char) * MAX);
    for (int i = 0; i < strlen(stringa); i++) {
        cifrata[i] = 'a' + (stringa[i] + chiave - 'a') % LETTERE_ALFABETO;
    }
    return cifrata;
}

int main() {
    int key;
    char sequenza[MAX];
    char cifrata[MAX];
    scanf("%d", &key);
    scanf("%s", &sequenza);
    cifraCesare(sequenza, cifrata, key);
    printf("Cifratura di %s con chiave %d: %s\n", sequenza, key, cifrata);
    printf("Cifratura di %s con chiave %d: %s\n", sequenza, key, cifraCesareConReturn(sequenza, key));
}