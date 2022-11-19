#include "../src/helper/configparser/configparser.h"
#include "../src/adt/tree/tree.h"
#include "../src/helper/simulator/simulator.h"

// gcc -std=c17 -I. src/adt/charmachine/*.c src/adt/kulkas/*.c src/adt/listlinier/*.c src/adt/liststatik/*.c src/adt/makanan/*.c src/adt/matrix/*.c src/adt/peta/*.c src/adt/point/*.c src/adt/prioqueuedinamik/*.c src/adt/set/*.c src/adt/stack/*.c src/adt/time/*.c src/adt/tree/*.c src/adt/word/*.c src/adt/wordmachine/*.c src/helper/command/*.c src/helper/configparser/*.c src/helper/simulator/*.c -o bin/configparser tests/configparser.c
int main(){
    createListMakanan(&listMakanan);
    loadConfigMakanan(&listMakanan);
    displayListMakanan(listMakanan);

    // printf("=======================\n");
    // loadConfigPeta(&peta);
    // printf("Ini petanya: \n");
    // DisplayPeta(peta);
    // printf("\n=======================\n");

    // loadConfigResep(&listTreeResep);
    // for (int i = 0; i < lengthLin(listTreeResep); i++) {
    //     ListType tree = getElmtLin(listTreeResep, i);
    //     printf("Ini resep ke %i\n", i);
    //     PrintTree(tree.address, listMakanan);
    //     printf("-----\n");
    // }

    // while (true) {
    //     STARTCOMMAND();
    //     while(!endWord) {
    //         printWord(currentWord);
    //         printf(" ");
    //         ADVCOMMAND();
    //     }
    //     printf("\n");
    //     RESETCOMMAND();
    // }
}