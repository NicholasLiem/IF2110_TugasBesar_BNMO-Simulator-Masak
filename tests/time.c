#include "src/adt/time/time.h"
#include "stdio.h"

// gcc -std=c17 -I. src/adt/charmachine/*.c src/adt/kulkas/*.c src/adt/listlinier/*.c src/adt/liststatik/*.c src/adt/makanan/*.c src/adt/matrix/*.c src/adt/peta/*.c src/adt/point/*.c src/adt/prioqueuedinamik/*.c src/adt/set/*.c src/adt/stack/*.c src/adt/time/*.c src/adt/tree/*.c src/adt/word/*.c src/adt/wordmachine/*.c src/helper/command/*.c src/helper/configparser/*.c src/helper/simulator/*.c -o bin/time tests/time.c

int main() {
    TIME t1;
    TIME t2;
    BacaTIME(&t1);
    BacaTIME(&t2);

    // Tulis Time
    printf("t1: ");
    TulisTIME(t1);
    printf("\n");

    // Time to Menit
    printf("time to menit %d\n", TIMEToMenit(t1));

    long t = 1440;
    TIME t3 = MenitToTIME(t);
    printf("menit to time: ");
    TulisTIME(t3);
}
