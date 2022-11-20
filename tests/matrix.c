#include "../src/adt/matrix/matrix.h"
#include <stdio.h>

// gcc -std=c17 -I. src/adt/matrix/*.c -o bin/matrix tests/matrix.c
int main() {
    Matrix p;
    int a, b;
    printf("Ukuran matriks: ");
    scanf("%d%d", &a, &b);
    createMatrix(a, b, &p);
    readMatrix(&p, a, b);

    printf("A:\n");
    displayMatrix(p);
    printf("Banyak elemen: %d\n", countElmt(p));

    if(isSquare(p)){
        printf("Matriks persegi\n");
        Matrix ps = multiplyMatrix(p, p);
        printf("A^2:\n");
        displayMatrix(ps);    
    }
    else printf("Bukan matriks persegi\n");

    printf("Determinan: %f\n", determinant(p));

    printf("AT:\n");
    displayMatrix(transpose(p));

}