#include "../src/ADT/wordmachine/wordmachine.h"
#include "stdio.h"

//  gcc -std=c17 -I. src/adt/charmachine/*.c src/adt/kulkas/*.c src/adt/listlinier/*.c src/adt/liststatik/*.c src/adt/makanan/*.c src/adt/matrix/*.c src/adt/peta/*.c src/adt/point/*.c src/adt/prioqueuedinamik/*.c src/adt/set/*.c src/adt/stack/*.c src/adt/time/*.c src/adt/tree/*.c src/adt/word/*.c src/adt/wordmachine/*.c src/helper/command/*.c src/helper/configparser/*.c src/helper/simulator/*.c -o bin/wordmachine tests/wordmachine.c

int main() {
    while (true) {
        STARTCOMMAND();
        while(!endWord) {
            printWord(currentWord);
            printf(" ");
            ADVCOMMAND();
        }
        printf("\n");
        RESETCOMMAND();
    }
}