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
    for(int i = 0; i < lengthListMakanan(listMakanan); i++){
        ElTypeQueue baru;
        baru= ELMT(listMakanan, i);
		enqueue(&prioqueue, baru, 'I');
	}	
    Set inven = getSetInventory(listMakanan, prioqueue);
    printSet(inven);
    printRecommendation(prioqueue, rekom, listMakanan);
}