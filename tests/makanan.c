#include "src/ADT/time/time.h"
#include "src/ADT/makanan/makanan.h"
#include "src/Helper/configparser/configparser.h"
#include "stdio.h"

// gcc -std=c17 -I. src/adt/charmachine/*.c src/adt/kulkas/*.c src/adt/listlinier/*.c src/adt/liststatik/*.c src/adt/makanan/*.c src/adt/matrix/*.c src/adt/peta/*.c src/adt/point/*.c src/adt/prioqueuedinamik/*.c src/adt/set/*.c src/adt/stack/*.c src/adt/time/*.c src/adt/tree/*.c src/adt/word/*.c src/adt/wordmachine/*.c src/helper/command/*.c src/helper/configparser/*.c src/helper/simulator/*.c -o bin/makanan tests/makanan.c

int main(){
    ListMakanan listMakanan;
    createListMakanan(&listMakanan);
    loadConfigMakanan(&listMakanan);
    displayListMakanan(listMakanan);
    printf("Length dari list makanan: %d", lengthListMakanan(listMakanan));
    int d;
    printf("\nSEARCH INPUT ID: ");
    scanf("%d", &d);
    printMakanan(searchMakanan(listMakanan, d));
}