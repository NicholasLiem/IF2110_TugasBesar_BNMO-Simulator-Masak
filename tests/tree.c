#include "../src/adt/tree/tree.h"
#include "stdio.h"

// gcc -std=c17 -I. src/adt/charmachine/*.c src/adt/kulkas/*.c src/adt/listlinier/*.c src/adt/liststatik/*.c src/adt/makanan/*.c src/adt/matrix/*.c src/adt/peta/*.c src/adt/point/*.c src/adt/prioqueuedinamik/*.c src/adt/set/*.c src/adt/stack/*.c src/adt/time/*.c src/adt/tree/*.c src/adt/word/*.c src/adt/wordmachine/*.c src/helper/command/*.c src/helper/configparser/*.c src/helper/simulator/*.c -o bin/tree tests/tree.c

int main() {
    treeAddress tree;
    CreateTree(&tree);
    addRoot(&tree, 2);
    addChild(&tree, 2, 1);
    addChild(&tree, 2, 3);
    addChild(&tree, 2, 5);
    addChild(&tree, 5, 6);
    addChild(&tree, 6,7);
    addChild(&tree, 7,8);
    PrintTreePlain(tree);   

    treeAddress tree2;
    CreateTree(&tree2);
    addRoot(&tree2, 50);
    addChild(&tree2, 32, 102);
    addChild(&tree2, 52, 32);
    PrintTreePlain(tree2);
    printf("halo?");
    List arrayTree;
    CreateListLin(&arrayTree, 2);
    ListType etree1, etree2;
    etree1.address = tree;
    etree2.address = tree2;
    insertFirstLin(&arrayTree, etree1);
    insertFirstLin(&arrayTree, etree2);
    displayListLin(getTreeChildrenId(arrayTree, 2));
    printf("\n");
    displayListLin(getAllTreeChildrenId(arrayTree, 2));
    printf("ta\n");
    displayListLin(getAllTreeChildrenId(arrayTree, 1));
}