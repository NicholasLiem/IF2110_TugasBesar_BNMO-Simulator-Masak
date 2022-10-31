#include "../headers/simulator.h"

void loadConfig() {
    CreateListMakanan(&listMakanan);
    loadConfigMakanan(&listMakanan);
    displayListMakanan(listMakanan);

    // printf("=======================\n");
    loadConfigPeta(&peta);
    printf("Ini petanya: \n");
    DisplayPeta(peta);
    printf("\n=======================\n");

    loadConfigResep(&listTreeResep);
    for (int i = 0; i < lengthLin(listTreeResep); i++) {
        ListType tree = getElmtLin(listTreeResep, i);
        printf("Ini resep ke %i\n", i);
        PrintTree(tree.address);
        printf("-----\n");
    }

};