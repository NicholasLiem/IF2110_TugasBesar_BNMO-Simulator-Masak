#include "../src/ADT/word/word.h"

// gcc -std=c17 -I. src/adt/charmachine/*.c src/adt/kulkas/*.c src/adt/listlinier/*.c src/adt/liststatik/*.c src/adt/makanan/*.c src/adt/matrix/*.c src/adt/peta/*.c src/adt/point/*.c src/adt/prioqueuedinamik/*.c src/adt/set/*.c src/adt/stack/*.c src/adt/time/*.c src/adt/tree/*.c src/adt/word/*.c src/adt/wordmachine/*.c src/helper/command/*.c src/helper/configparser/*.c src/helper/simulator/*.c -o bin/word tests/word.c

int main() {
    Word temp;
    Word baru;
    Word time = intToWord(192);
    printf("ok");
    printWord(time);
    setWord(&temp, "oke123");
    printWord(temp);
    appendWord(&temp, temp);
    printWord(temp);
    isEqualWord(baru, temp);
    toUpper(&temp);
    printWord(temp);
}