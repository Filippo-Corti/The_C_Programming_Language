#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int key;
    int value;
} MapItem;

typedef struct {
    MapItem items[100];
    int size;
} Map; 

/* Funzioni per gestione della Mappa (Prototipi)*/
Map newMap();
int mapIndexOf(Map m, int key);
void mapInsert(Map *m, int key, int value);
void mapIncrement(Map *m, int key); //Works just like map[key]++;
int mapContains(Map m, int key);
void mapRemove(Map *m, int key);
void printMap(Map m);

void aggiornaConteggio(Map *m, char* text) {
    char *token;
    token = strtok(text, " "); //Works kind of like a "split and get first" (So I have to call it more times)
    while (token != NULL) {
        mapIncrement(m, strlen(token)); //m[strlen(token)]++
        token = strtok(NULL, " ");
    }
}

int main() {
    char text[1000]; //Oversized 
    Map contaLunghezze = newMap();
    while (scanf("%[^\n]%*c", &text) != EOF) { // %[^\n]%*c -> Sta roba strana permette di leggere stringhe con spazi
        aggiornaConteggio(&contaLunghezze, text);
    }
    printMap(contaLunghezze);
}

/* Implementazione Funzioni sulle Mappe*/

Map newMap() {
    Map m;
    m.size = 0;
    return m;
}

int mapIndexOf(Map m, int key) {
    for (int i = 0; i < m.size; i++)
        if (m.items[i].key == key) 
            return i;
    return -1;
}

void mapInsert(Map *m, int key, int value) {
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


void mapIncrement(Map *m, int key) {
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

int mapContains(Map m, int key) {
    for (int i = 0; i < m.size; i++)
        if (m.items[i].key == key) 
            return 1;
    return 0;
}

void mapRemove(Map *m, int key) {
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

void printMap(Map m) {
    for (int i = 0; i < m.size; i++)
        printf("Key: %d,\tValue: %d\n", m.items[i].key, m.items[i].value);
}
