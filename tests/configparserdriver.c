#include "../src/Helper/headers/configParser.h"
#include "../src/ADT/headers/tree.h"

int main(){
    ListMakanan listMakanan;
    CreateListMakanan(&listMakanan);
    loadConfigMakanan(&listMakanan);
    displayListMakanan(listMakanan);

    printf("=======================\n");
    Peta peta;
    loadConfigPeta(&peta);
    printf("Ini petanya: \n");
    DisplayPeta(peta);
    printf("\n=======================\n");

    loadConfigResep();
    for (int i = 0; i < lengthLin(listTreeResep); i++) {
        ListType tree = getElmtLin(listTreeResep, i);
        printf("Ini resep ke %i\n", i);
        PrintTree(tree.address);
        printf("-----\n");
    }

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