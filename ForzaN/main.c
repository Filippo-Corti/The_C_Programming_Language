#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getMossaUtente();
int getMossaComputer();
int isValidMossa(int n);
void gioca();
int leggi_mossa();
int scrivi(int gioc, int j);
void show();
int game_over();

int** G;
int n, r, c;

int main(int argc, char** argv) {
    srand(time(NULL));

    n = atoi(argv[1]);
    r = atoi(argv[2]);
    c = atoi(argv[3]);

    G = (int**)malloc(r * sizeof(int));
    for(int i = 0; i < r; i++) {
        G[i] = (int*)malloc(c * sizeof(int));
        for(int j = 0; j < c; j++) {
            G[i][j] = 0;
        }
    }

    gioca();
}

void gioca() {
    int esito, mossa, giocatore = 1;
    while(1) {
        show();

        if (giocatore == 2) {
            printf("Mossa del computer:\n");
        }
        do {
            mossa = (giocatore == 1) ? getMossaUtente() : getMossaComputer();
        } while(!scrivi(giocatore, mossa));

        esito = game_over(); 
        if (esito != -1) {
            show();
            printf("Gioco finito %d\n", esito);
            return;
        }

        giocatore = (giocatore == 1) ? 2 : 1;
    }
}

int getMossaUtente() {
    int mossa;
    do {
        mossa = leggi_mossa();
    } while(!isValidMossa(mossa));  
    return mossa;
}


int getMossaComputer() {
    srand(time(NULL)); //inizializzo un seed
    int x=rand()%c; // genero il numero casuale x
    return x;
}

int isValidMossa(int n) {
    return (n >= 0 && n < c);
}

int leggi_mossa() {
    int mossa;
    printf("Utente, qual e' la tua mossa (j=1...%d) ? ", c);
    scanf("%d", &mossa);
    return mossa - 1;
}


int scrivi(int gioc, int j) {
    for (int i = r - 1; i >= 0; i--) {
        if (G[i][j] == 0) {
            G[i][j] = gioc;
            return 1;
        }
    }
    return 0;
}

void show() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("|%c", G[i][j] == 0 ? ' ' : G[i][j] == 1 ? '+' : '*');
        }
        printf("|\n");
    }
}

int game_over() {
    int current = G[0][0];
    int count;
    // Controllo Righe
    for (int i = 0; i < r; i++) {
        count = 0;
        for (int j = 0; j < c; j++) {
            if (G[i][j] == current) {
                count++;
                if (count == n && current != 0) {
                    return current; 
                }
            } else {
                current = G[i][j];
                count = 1;
            }
        }
    }
    //Controllo Colonne
    current = G[0][0];
    for (int i = 0; i < c; i++) {
        count = 0;
        for (int j = 0; j < r; j++) {
            if (G[j][i] == current) {
                count++;
                if (count == n && current != 0) {
                    return current; 
                }
            } else {
                current = G[j][i];
                count = 1;
            }
        }
    }

    //Controllo Patta
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (G[i][j] == 0) {
                return -1;
            }
        }
    }
    return 0;
} 