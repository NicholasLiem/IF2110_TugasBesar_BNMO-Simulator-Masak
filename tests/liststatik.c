#include "src/adt/liststatik/liststatik.h"
#include <stdio.h>

// gcc -std=c17 -I. src/adt/charmachine/*.c src/adt/kulkas/*.c src/adt/listlinier/*.c src/adt/liststatik/*.c src/adt/makanan/*.c src/adt/matrix/*.c src/adt/peta/*.c src/adt/point/*.c src/adt/prioqueuedinamik/*.c src/adt/set/*.c src/adt/stack/*.c src/adt/time/*.c src/adt/tree/*.c src/adt/word/*.c src/adt/wordmachine/*.c src/helper/command/*.c src/helper/configparser/*.c src/helper/simulator/*.c -o bin/liststatik tests/liststatik.c
int main() {
    ListStatik l1, l2;
    CreateListStatik(&l1);
    CreateListStatik(&l2);

    if(isEmpty(l1)) printf("Empty\n");

    insertFirst(&l1, 3);
    insertLast(&l1, 5);
    insertLast(&l1, 2);
    insertLast(&l1, 9);
    insertLast(&l1, 1);
    printf("list1: ");
    printList(l1);
    printf("\n");
    if(!isEmpty(l1)) printf("Not Empty\n");
    printf("Length: %d\n", listLength(l1));

    insertLast(&l2, 12);
    insertLast(&l2, 25);
    printf("list2: ");
    printList(l2);
    printf("\n");

    if(isListEqual(l1, l2)) printf("list1 and list2 are equal\n");
    else printf("list1 and list2 are not equal\n");


    ElType min, max;
    extremeValues(l1, &max, &min);
    printf("list 1 min: %d\n", min);
    printf("list 1 max: %d\n", max);

    sortList(&l1, true);

    printf("sorted list 1: ");
    printList(l1);   
    printf("\n");
}