/* File : stack.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */

#include <stdio.h>
#include "../../Helper/headers/simulator.h"
#include "../../Helper/headers/command.h"
#include "../../ADT/headers/prioqueuedinamik.h"

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
#define NEXTSTATE(S) (S)->next

stackAddress AlokStackNode(POINT p, TIME t, List l, Queue q, Queue q2);

void CreateStack(stackState *S);

boolean isEmptyStack(stackState S);

void PushState(stackState *S, POINT p, TIME t, List l, Queue q, Queue q2);

void PopState(stackState *S);

void deleteAllState(stackState *S);

void PrintStack(stackState S);

#endif






