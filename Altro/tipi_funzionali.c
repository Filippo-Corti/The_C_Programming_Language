#include <stdio.h>
#include <stdlib.h>

//Not exactly what I wanted :(

static inline int doSomething(int x) {
    return x * 3;
}

int main() {
    int func;
    func = doSomething(5);
    printf("%d\n", func);
}