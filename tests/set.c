#include "src/ADT/headers/set.h"
#include "stdio.h"
#include "src/Helper/headers/configParser.h"

Word aksi = {"FRY", 3};
Word nama = {"TEST", 4};

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