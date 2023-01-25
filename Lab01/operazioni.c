#include <stdio.h>

int main() {
    float n1, n2;
    scanf("%f %f", &n1, &n2);
    printf("Somma: %.2f\n", n1 + n2);
    printf("Differenza: %.2f\n", n1 - n2);
    printf("Prodotto: %.2f\n", n1 * n2);
    printf("Quoziente: %.2f\n", n1 / n2);
    printf("Resto: %d\n", (int)n1 % (int)n2);
    return 0;
}