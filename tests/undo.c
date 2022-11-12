#include <stdio.h>
#include <stdlib.h>
#include "src/Helper/implementation/undo.c"



int main(){
    stackState S;
    CreateStack(&S);
    Peta p;
    TIME t;
    List l;
    Queue q;
    Queue q2;
    CreatePeta(1, 9, &p);
    CreateTime(&t, 1, 0, 0);
    CreateListLin(&l, 4);
    CreateQueue(&q);
    CreateQueue(&q2);
    PushState(&S, p, t, l, q, q2);
    PrintStack(S);
    return 0;
}