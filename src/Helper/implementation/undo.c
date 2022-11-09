#include "../headers/undo.h"
#include <stdio.h>
#include <stdlib.h>

stackAddress AlokStackNode(Peta p, TIME t, List notif, Queue inv, Queue deliv) {
    stackAddress pNew = (stackAddress) malloc(sizeof(stackNode));
    if (pNew != NULL) {
        CURRENT_PETA(pNew) = p;
        CURRENT_TIME(pNew) = t;
        CURRENT_NOTIF(pNew) = notif;
        CURRENT_INVENTORY(pNew) = inv;
        CURRENT_DELIVERY(pNew) = deliv;
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

void PushState(stackState *S, Peta p, TIME t, List notif, Queue inv, Queue deliv) {
    stackAddress pNew = AlokStackNode(p, t, notif, inv, deliv);
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
        List listNotif = CURRENT_NOTIF(currentState);
        printf("\nTime: ");
        TulisTIME(CURRENT_TIME(currentState));
        printf("\nMap:\n");
        DisplayPeta(CURRENT_PETA(currentState));
        printf("\nNotification:\n");
        printNotif(listNotif);
        printf("\nInventory:\n");
        displayQueuePretty(CURRENT_INVENTORY(currentState), 'I');
        printf("\nDelivery:\n");
        displayQueuePretty(CURRENT_DELIVERY(currentState), 'D');
        printf("\n");
    }
}
    






