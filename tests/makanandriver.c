#include "src/ADT/headers/time.h"
#include "src/Helper/headers/configParser.h"
#include "stdio.h"

// gcc -std=c17 -I. src/ADT/implementation/*.c src/helper/implementation/*.c -o bin/makanandriver tests/makanandriver.c

int main(){
    ListMakanan listMakanan;
    CreateListMakanan(&listMakanan);
    loadConfigMakanan(&listMakanan);
    displayListMakanan(listMakanan);
    printf("Length dari list makanan: %d", lengthListMakanan(listMakanan));
    int d;
    printf("\nSEARCH INPUT ID: ");
    scanf("%d", &d);
    printMakanan(searchMakanan(listMakanan, d));
}