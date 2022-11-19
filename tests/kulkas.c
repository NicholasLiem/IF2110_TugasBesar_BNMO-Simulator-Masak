#include "src/ADT/kulkas/kulkas.h"
#include "src/ADT/makanan/makanan.h"
#include "src/ADT/time/time.h"
#include <stdio.h>

// gcc -std=c17 -I. src/adt/charmachine/*.c src/adt/kulkas/*.c src/adt/listlinier/*.c src/adt/liststatik/*.c src/adt/makanan/*.c src/adt/matrix/*.c src/adt/peta/*.c src/adt/point/*.c src/adt/prioqueuedinamik/*.c src/adt/set/*.c src/adt/stack/*.c src/adt/time/*.c src/adt/tree/*.c src/adt/word/*.c src/adt/wordmachine/*.c src/helper/command/*.c src/helper/configparser/*.c src/helper/simulator/*.c -o bin/kulkas tests/kulkas.c
const Word AKSI = {"Makan",5};
const Word NAMA = {"Nasi Goreng",11};
const Word NAMA1 = {"Ayam Goreng",11};

int main(){
    ListItemKulkas s;
    createListItemKulkas(&s);
    TIME t1;
    CreateTime(&t1,1,1,1);
    TIME t2;
    CreateTime(&t2,2,2,2);
    Makanan testMakanan;
    createMakanan(&testMakanan, 1, AKSI, NAMA, t1, t2);
    setLebarMakanan(&testMakanan, 2);
    setPanjangMakanan(&testMakanan, 1);

    Makanan ayamGoreng;
    createMakanan(&ayamGoreng, 2, AKSI, NAMA1, t1, t2);
    setLebarMakanan(&ayamGoreng, 2);
    setPanjangMakanan(&ayamGoreng, 2);

    Kulkas kulkasPanasonic;
    createKulkas(&kulkasPanasonic);
    
    insertMakananKulkas(&s, &kulkasPanasonic, testMakanan, 1,2);
    insertMakananKulkas(&s,&kulkasPanasonic, ayamGoreng, 1,2); 
    insertMakananKulkas(&s,&kulkasPanasonic, ayamGoreng, 1,2); 
    insertMakananKulkas(&s,&kulkasPanasonic, ayamGoreng, 1,2); 
    insertMakananKulkas(&s,&kulkasPanasonic, ayamGoreng, 1,2); 
    insertMakananKulkas(&s,&kulkasPanasonic, testMakanan, 1,2);
    insertMakananKulkas(&s,&kulkasPanasonic, testMakanan, 1,2);
    printKulkas(kulkasPanasonic);
    printItemKulkas(s);
    deleteItemKulkas(&s, &kulkasPanasonic, 1);
    printItemKulkas(s);
    printKulkas(kulkasPanasonic);
    return 0;
}