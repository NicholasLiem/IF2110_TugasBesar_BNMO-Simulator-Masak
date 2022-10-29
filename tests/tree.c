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
    PrintTree(tree);   
    printf("\n\ntes dua subtree duplikat\n\n");
    treeAddress tree2;
    CreateTree(&tree2);
    addRoot(&tree2, 2);
    addChild(&tree2, 2, 3);
    addChild(&tree2, 2, 3);
    addChild(&tree2, 3, 5);
    addChild(&tree2, 3, 7);
    PrintTree(tree2);  
}