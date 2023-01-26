#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ----------- Tentativo di replicare le mappe (string-string) di Go in linguaggio C -----------

typedef struct {
    char* key;
    char* value;
} MapItem;

typedef struct {
    MapItem items[100]; //Volendo potrei combinare mappe e slice per avere una mappa di lunghezza variabile
    int size;
} Map; 

Map newMap() {
    Map m;
    m.size = 0;
    return m;
}

int mapIndexOf(Map m, char* key) {
    for (int i = 0; i < m.size; i++)
        if (strcmp(m.items[i].key, key) == 0) 
            return i;
    return -1;
}

void mapInsert(Map *m, char* key, char* value) {
    int indexOfKey = mapIndexOf(*m, key);
    if (indexOfKey != -1) {
        //Update item
        m->items[indexOfKey].value = value;
    } else {
        //Add item
        m->items[m->size] = (MapItem) {key, value};
        m->size++;
    }
}

int mapContains(Map m, char* key) {
    for (int i = 0; i < m.size; i++)
        if (strcmp(m.items[i].key, key) == 0) 
            return 1;
    return 0;
}

void mapRemove(Map *m, char* key) {
    for (int i = 0; i < m->size; i++) {
        if (strcmp(m->items[i].key, key) == 0) {
            //We need to shift every item after m[key] to the left 
            for (int j = i + 1; j < m->size; j++) {
                m->items[j - 1] = m->items[j]; 
            }
            m->size--;
            return;
        }
    }
}

void printMap(Map m) {
    for (int i = 0; i < m.size; i++)
        printf("Key: %s,\tValue: %s\n", m.items[i].key, m.items[i].value);
}

int main() {
    Map mappa = newMap();
    mapInsert(&mappa, "Chiave1", "Valore1");
    mapInsert(&mappa, "Chiave2", "Valore2");
    mapInsert(&mappa, "Chiave3", "Valore3");
    mapInsert(&mappa, "Chiave1", "ValoreCambiato");
    mapRemove(&mappa, "Chiave2");
    printMap(mappa);
}
