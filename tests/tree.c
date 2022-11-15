#include "src/ADT/headers/tree.h"
#include "stdio.h"

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