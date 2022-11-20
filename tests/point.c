#include "../src/adt/point/point.h"
#include <stdio.h>

// gcc -std=c17 -I. src/adt/charmachine/*.c src/adt/kulkas/*.c src/adt/listlinier/*.c src/adt/liststatik/*.c src/adt/makanan/*.c src/adt/matrix/*.c src/adt/peta/*.c src/adt/point/*.c src/adt/prioqueuedinamik/*.c src/adt/set/*.c src/adt/stack/*.c src/adt/time/*.c src/adt/tree/*.c src/adt/word/*.c src/adt/wordmachine/*.c src/helper/command/*.c src/helper/configparser/*.c src/helper/simulator/*.c -o bin/point tests/point.c
int main() {
    POINT p;
    CreatePoint(&p, 1.2, 2.2);
    TulisPOINT(p);

    if(IsOrigin(p)) printf("Origin\n");
    else printf("Not origin\n");

    printf("\n");
    Geser(&p, 1.5, 0.2);
    TulisPOINT(p);

    printf("Jarak p dari o: %d\n", Jarak0(p));
    return 0;
}