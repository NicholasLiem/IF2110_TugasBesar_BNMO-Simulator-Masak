#include "src/adt/set/set.h"
#include "stdio.h"
#include "src/helper/configparser/configparser.h"

Word aksi = {"FRY", 3};
Word nama = {"TEST", 4};

// gcc -std=c17 -I. src/adt/charmachine/*.c src/adt/kulkas/*.c src/adt/listlinier/*.c src/adt/liststatik/*.c src/adt/makanan/*.c src/adt/matrix/*.c src/adt/peta/*.c src/adt/point/*.c src/adt/prioqueuedinamik/*.c src/adt/set/*.c src/adt/stack/*.c src/adt/time/*.c src/adt/tree/*.c src/adt/word/*.c src/adt/wordmachine/*.c src/helper/command/*.c src/helper/configparser/*.c src/helper/simulator/*.c -o bin/set tests/set.c

int main() {
    List treeResep;
    loadConfigResep(&treeResep);
    printf("hy");
    ListMakanan listMakanan;
    createListMakanan(&listMakanan);
    loadConfigMakanan(&listMakanan);
    printf("Length dari list makanan: %d", lengthListMakanan(listMakanan));
    printListResep(treeResep, listMakanan);
    ListSet rekom = readTree(treeResep, listMakanan);
    Queue prioqueue;
    CreateQueue(&prioqueue);

    ElTypeQueue baru;
    baru= ELMT(listMakanan, 0);
	enqueue(&prioqueue, baru, 'I');

    baru= ELMT(listMakanan, 2);
	enqueue(&prioqueue, baru, 'I');

    baru= ELMT(listMakanan, 3);
	enqueue(&prioqueue, baru, 'I');

    baru= ELMT(listMakanan, 3);
	enqueue(&prioqueue, baru, 'I');

    baru= ELMT(listMakanan, 9);
	enqueue(&prioqueue, baru, 'I');

    baru= ELMT(listMakanan, 7);
	enqueue(&prioqueue, baru, 'I');

    displayListMakanan(listMakanan);
    // Set inven = getSetInventory(listMakanan, prioqueue);
    // ELMT(inven, 0).quantity = 0;
    // ELMT(inven, 1).quantity = 0;
    // ELMT(inven, 2).quantity = 0;
    // printSet(inven);
    printRecommendation(prioqueue, rekom, listMakanan);
}