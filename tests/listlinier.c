#include "src/adt/listlinier/listlinier.h"
#include "src/adt/makanan/makanan.h"
#include "src/adt/time/time.h"
#include "stdio.h"

// gcc -std=c17 -I. src/adt/charmachine/*.c src/adt/kulkas/*.c src/adt/listlinier/*.c src/adt/liststatik/*.c src/adt/makanan/*.c src/adt/matrix/*.c src/adt/peta/*.c src/adt/point/*.c src/adt/prioqueuedinamik/*.c src/adt/set/*.c src/adt/stack/*.c src/adt/time/*.c src/adt/tree/*.c src/adt/word/*.c src/adt/wordmachine/*.c src/helper/command/*.c src/helper/configparser/*.c src/helper/simulator/*.c -o bin/listlinier tests/listlinier.c
int main() {
    List listAngka;
    List listAddress;
    // ListType angka1;
    // ListType angka2;
    // ListType angka3;
    // ListType address1;
    // ListType address2;
    // ListType address3;
    List listMakanan;
    CreateListLin(&listAngka, 1);
    CreateListLin(&listAddress, 2);
    CreateListLin(&listMakanan, 3);
    ListType makanan1;
    ListType makanan2;
    ListType makanan3;
    Word nama;
    setWord(&nama, "ayam goreng");
    Word aksi;
    setWord(&aksi, "fry");
    TIME expired;
    CreateTime(&expired, 2, 0, 0);

    Makanan temp;
    createMakanan(&temp,2, aksi, nama, expired, expired);
    makanan1.makanan = temp;
    createMakanan(&temp, 3, aksi, nama, expired, expired);
    makanan2.makanan = temp;
    createMakanan(&temp, 4, aksi, nama, expired, expired);
    makanan3.makanan = temp;

    insertFirstLin(&listMakanan, makanan1);
    insertFirstLin(&listMakanan, makanan2);
    insertFirstLin(&listMakanan, makanan3);
    displayListLin(listMakanan);
    ListType makananList = getElmtLin(listMakanan, 0);
    increaseTime(&makananList.makanan, 10);
    setElmtLin(&listMakanan, 0, makananList);
    printf("\n====================================\n");
    displayListLin(listMakanan);
    List listMakanan2;
    copyListLin(listMakanan, &listMakanan2);
    printf("\n====================================\n");
    displayListLin(listMakanan2);
}