#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
Se da riga di comando passo una stringa con caratteri non-ASCII
la lunghezza della stringa è maggiore di quella che ci aspettiamo.
In sostanza C considera UNICODE (nel senso che di fatto la stampa funziona)
ma ci impedisce di lavorare sui caratteri di una stringa a meno che questi
siano lunghi un byte.
*/

int main(int argc, char **argv) {
    printf("%s\t%d\n", argv[1], strlen(argv[1]));
    for (int i = 0; i < strlen(argv[1]); i++) {
        printf("%c\t", argv[1][i]);
    }
}