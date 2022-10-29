#include "src/ADT/headers/listlinier.h"
#include "src/ADT/headers/makanan.h"
#include "src/ADT/headers/time.h"
#include "stdio.h"

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
    displayListLin(listMakanan);
}