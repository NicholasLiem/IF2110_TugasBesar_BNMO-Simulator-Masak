/* File : stack.h */
/* Implementasi dalam bahasa C dengan linked list */

#include "../../helper/simulator/simulator.h"
#include "../../helper/command/command.h"
#include "../prioqueuedinamik/prioqueuedinamik.h"
#include "../kulkas/kulkas.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef stackt_H
#define stackt_H

typedef struct stackNode* stackAddress;

typedef struct stackNode {
    // Peta currentPeta;
    POINT currentLoc;
    TIME currentTime;
    List currentNotif;
    Queue currentInventory;
    Queue currentDelivery;
    stackAddress next;
    Kulkas currentKulkas;
    ListItemKulkas currentListItemKulkas;
    List notifUndo;
 } stackNode;

typedef struct stackState {
    stackAddress top;
} stackState;

#define TOP(S) (S).top
// #define CURRENT_PETA(S) (S)->currentPeta
#define CURRENT_LOC(S) (S)->currentLoc
#define CURRENT_TIME(S) (S)->currentTime
#define CURRENT_NOTIF(S) (S)->currentNotif
#define CURRENT_INVENTORY(S) (S)->currentInventory
#define CURRENT_DELIVERY(S) (S)->currentDelivery
#define CURRENT_KULKAS(S) (S)->currentKulkas
#define CURRENT_LIST_ITEM_KULKAS(S) (S)->currentListItemKulkas
#define CURRENT_NOTIF_UNDO(S) (S)->notifUndo
#define NEXTSTATE(S) (S)->next

stackAddress AlokStackNode(POINT p, TIME t, List l, Queue q, Queue q2, Kulkas k, ListItemKulkas l2, List l3);

void CreateStack(stackState *S);

boolean isEmptyStack(stackState S);

void PushState(stackState *S, POINT p, TIME t, List l, Queue q, Queue q2, Kulkas k, ListItemKulkas l2, List l3);

void PopState(stackState *S);

void deleteAllState(stackState *S);

void PrintStack(stackState S);

void insertListUndo(stackState *S, List listUndo);
#endif






