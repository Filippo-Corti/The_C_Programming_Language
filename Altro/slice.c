#include <stdio.h>
#include <stdlib.h>

// ----------- Tentativo di replicare le slice di Go in linguaggio C -----------

typedef struct {
    int length;
    int capacity;
    int* data;
} Slice;

Slice newSlice(int capacity) {
    Slice slice;
    slice.data = (int*)malloc(sizeof(int) * capacity);
    slice.length = 0;
    slice.capacity = capacity;
    return slice;
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
        s->data = realloc(s->data, s->capacity);
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

int main() {
    Slice slice = newSlice(2); //Initialize slice of 0 elements with max capacity of 10
    insert(&slice, 5);
    insert(&slice, 10);
    insert(&slice, 15);
    insert(&slice, 20);
    insert(&slice, 25);
    printf("La slice ha lunghezza %d e capacità %d\n", slice.length, slice.capacity);
    printSlice(slice);
    removeLast(&slice);
    printf("La slice ha lunghezza %d e capacità %d\n", slice.length, slice.capacity);
    printSlice(slice);
    freeSlice(&slice);
}