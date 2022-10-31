#include "src/ADT/headers/time.h"
#include "stdio.h"

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
