#include <stdio.h>
#include <stdlib.h>
#include "../../ADT/headers/stack.h"

stackAddress AlokStackNode(POINT p, TIME t, List notif, Queue inv, Queue deliv, Kulkas k, ListItemKulkas l2, List l3) {
    stackAddress pNew = (stackAddress) malloc(sizeof(stackNode));
    if (pNew != NULL) {
        // CURRENT_PETA(pNew) = p;
        CURRENT_LOC(pNew) = p;
        CURRENT_TIME(pNew) = t;
        CURRENT_NOTIF(pNew) = notif;
        CURRENT_INVENTORY(pNew) = inv;
        CURRENT_DELIVERY(pNew) = deliv;
        CURRENT_KULKAS(pNew) = k;
        CURRENT_LIST_ITEM_KULKAS(pNew) = l2;
        CURRENT_NOTIF_UNDO(pNew) = l3;
        NEXTSTATE(pNew) = NULL;
    }
    return pNew;
}

void CreateStack(stackState *S) {
    TOP(*S) = NULL;
}

boolean isEmptyStack(stackState S) {
    return (TOP(S) == NULL);
}

void PushState(stackState *S, POINT p, TIME t, List notif, Queue inv, Queue deliv, Kulkas k, ListItemKulkas l2, List l3) {
    stackAddress pNew = AlokStackNode(p, t, notif, inv, deliv, k, l2, l3);
    if (pNew != NULL) {
        NEXTSTATE(pNew) = TOP(*S);
        TOP(*S) = pNew;
    }
}

void PopState(stackState *S) {
    if (!isEmptyStack(*S)) {
        stackAddress pDel = TOP(*S);
        TOP(*S) = NEXTSTATE(TOP(*S));
        free(pDel);
    }
}

void deleteAllState(stackState *S) {
    while (!isEmptyStack(*S)) {
        PopState(S);
    }
}

void PrintStack(stackState S) {
    stackAddress currentState = TOP(S);
    if (currentState != NULL) {
        printf("\nTime: ");
        TulisTIME(CURRENT_TIME(currentState));
        printf("\nMap:\n");
        DisplayPeta(peta);
        printf("\nNotification:\n");
        displayListLin(CURRENT_NOTIF(currentState));
        printf("\nInventory:\n");
        displayQueuePretty(CURRENT_INVENTORY(currentState), 'I');
        printf("\nDelivery:\n");
        displayQueuePretty(CURRENT_DELIVERY(currentState), 'D');
        printf("\n");
        printKulkas(CURRENT_KULKAS(currentState));
        printf("\n");
        printItemKulkas(CURRENT_LIST_ITEM_KULKAS(currentState));
        printf("\n");
    }
}