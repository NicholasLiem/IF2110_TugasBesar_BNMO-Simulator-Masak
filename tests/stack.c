#include <stdio.h>
#include <stdlib.h>
#include "../src/adt/stack/stack.h"

// gcc -std=c17 -I. src/adt/charmachine/*.c src/adt/kulkas/*.c src/adt/listlinier/*.c src/adt/liststatik/*.c src/adt/makanan/*.c src/adt/matrix/*.c src/adt/peta/*.c src/adt/point/*.c src/adt/prioqueuedinamik/*.c src/adt/set/*.c src/adt/stack/*.c src/adt/time/*.c src/adt/tree/*.c src/adt/word/*.c src/adt/wordmachine/*.c src/helper/command/*.c src/helper/configparser/*.c src/helper/simulator/*.c -o bin/stack tests/stack.c

int main(){
    stackState S;
    CreateStack(&S);
    POINT pe;
    TIME t;
    List l;
    Queue q;
    Queue q2;
    CreatePoint(&pe, 1, 2);
    CreateTime(&t, 1, 0, 0);
    CreateListLin(&l, 4);
    CreateQueue(&q);
    CreateQueue(&q2);
    Kulkas qk;
    createKulkas(&qk);
    ListItemKulkas df;
    createListItemKulkas(&df);
    PushState(&S, pe, t, l, q, q2, qk, df, l);
    PrintStack(S);
    return 0;
}