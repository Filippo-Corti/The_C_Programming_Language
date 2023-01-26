#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* ----------- SLICE -------- */

typedef struct {
    int length;
    int capacity;
    int* data;
} Slice;

Slice newSlice(int capacity) {
    Slice s;
    s.data = (int*)malloc(sizeof(int) * capacity);
    s.length = 0;
    s.capacity = capacity;
    return s;
}

void printSlice(Slice s) {
    for (int i = 0; i < s.length; i++)
        printf("%d ", s.data[i]);
    printf("\n");        
}

void insert(Slice *s, int n) {
    if (s->capacity == s->length ) {
        // ! We need to relocate the data
        s->capacity *= 2;
        s->data = realloc(s->data, sizeof(int) * s->capacity);
    }
    s->data[s->length] = n;
    s->length++;
}

void removeLast(Slice *s) {
    //You can't free the memory of the last element, so you'll just keep it there and replace whenever a new insert occurs
    s->length--;
}

void freeSlice(Slice *s) {
    free(s->data);
    s->data = NULL;
    s->length = s->capacity = 0;
}

/* -------- End of SLICE -------- */


int main() {
    Slice slice;
    initSlice(&slice, 5);
    insert(&slice, 20);
    insert(&slice, 20);
    insert(&slice, 20);
    insert(&slice, 20);
    insert(&slice, 20);
    insert(&slice, 20);
    insert(&slice, 20);
    insert(&slice, 20);
    insert(&slice, 20);
    insert(&slice, 20);
    // for (int i = 0; i < 10; i++) {
    //     insert(&slice, 20);
    // }
    printSlice(slice);
    freeSlice(&slice);
}