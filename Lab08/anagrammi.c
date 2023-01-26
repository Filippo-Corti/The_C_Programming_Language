#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Mappa del tipo <rune, int>
typedef struct {
    char key;
    int value;
} MapItem;

typedef struct {
    MapItem items[100];
    int size;
} Map; 


/* Funzioni per gestione della Mappa (Prototipi)*/
Map newMap();
int mapIndexOf(Map m, char key);
void mapInsert(Map *m, char key, int value);
void mapIncrement(Map *m, char key); //Works just like map[key]++;
int mapContains(Map m, char key);
void mapRemove(Map *m, char key);
int mapGet(Map m, char key);
void printMap(Map m);


Map mappaCaratteri(char* str) {
    Map m = newMap();
    for (int i = 0; i < strlen(str); i++) 
        mapIncrement(&m, str[i]);
    return m;
}

int areMapsEqual(Map m1, Map m2) {
    if (m1.size != m2.size) {
        return 0;
    }
    for (int i = 0; i < m1.size; i++) {
        if (m1.items[i].value != mapGet(m2, m1.items[i].key)) 
            return 0;
    }
    return 1;
}

//Due parametri da riga di comando
int main(int argc, char **argv) {
    Map mappa1 = mappaCaratteri(argv[1]);
    Map mappa2 = mappaCaratteri(argv[2]);
    if (areMapsEqual(mappa1, mappa2)) 
        printf("Anagrammi\n");
    else 
        printf("Non anagrammi\n");
}


/* Implementazione Funzioni sulle Mappe*/

Map newMap() {
    Map m;
    m.size = 0;
    return m;
}

int mapIndexOf(Map m, char key) {
    for (int i = 0; i < m.size; i++)
        if (m.items[i].key == key) 
            return i;
    return -1;
}

void mapInsert(Map *m, char key, int value) {
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

void mapIncrement(Map *m, char key) {
    int indexOfKey = mapIndexOf(*m, key);
    if (indexOfKey != -1) {
        //Update item
        m->items[indexOfKey].value++;
    } else {
        //Add item
        m->items[m->size] = (MapItem) {key, 1};
        m->size++;
    }
}

int mapContains(Map m, char key) {
    for (int i = 0; i < m.size; i++)
        if (m.items[i].key == key) 
            return 1;
    return 0;
}

void mapRemove(Map *m, char key) {
    for (int i = 0; i < m->size; i++) {
        if (m->items[i].key == key) {
            //We need to shift every item after m[key] to the left 
            for (int j = i + 1; j < m->size; j++) {
                m->items[j - 1] = m->items[j]; 
            }
            m->size--;
            return;
        }
    }
}

int mapGet(Map m, char key) {
    for(int i = 0; i < m.size; i++) {
        if (m.items[i].key == key) 
            return m.items[i].value; 
    }
    return -1;
}

void printMap(Map m) {
    for (int i = 0; i < m.size; i++)
        printf("Key: %c,\tValue: %d\n", m.items[i].key, m.items[i].value);
}
