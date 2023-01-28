#include <stdio.h>

/*
Note:
- Precompilazione: gcc -E hello.c > hello.i
    Vengono eseguite le istruzioni per il Precompilatore (# ...). 
    In pratica viene sostituita l'istruzione #include <stdio.h> con
    l'effettivo contenuto del file.
    Il file contiene il prototipo di printf() ma non la sua implementazione
- Compilazione:
    gcc -S hello.c > hello.s
        Il codice C viene convertito in Assembly.
    gcc -o hello.o -C hello.c
        Il codice Assembly viene convertito in linguaggio macchina (binario).
- Linking:
    gcc -o hello hello.c
    Il Linker aggiunge l'implementazione delle funzioni importate al 
    codice in linguaggio macchina.
    In questa fase viene quindi aggiunto il codice di cui è fatta la funzione
    print().
*/

int main() {
    printf("Hello, World!");
}