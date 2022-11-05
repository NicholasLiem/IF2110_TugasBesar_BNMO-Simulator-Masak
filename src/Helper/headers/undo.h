
#include <stdio.h>
#include "simulator.h"
#include "../../ADT/headers/prioqueuedinamik.h"
#include "command.h"

#ifndef UNDO_H
#define UNDO_H

typedef struct stackNode* stackAddress;

typedef struct stackNode {
    Peta currentPeta;
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
#define CURRENT_PETA(S) (S)->currentPeta
#define CURRENT_TIME(S) (S)->currentTime
#define CURRENT_NOTIF(S) (S)->currentNotif
#define CURRENT_INVENTORY(S) (S)->currentInventory
#define CURRENT_DELIVERY(S) (S)->currentDelivery
#define NEXTSTATE(S) (S)->next

stackAddress AlokStackNode(Peta p, TIME t, List l, Queue q, Queue q2);

void CreateStack(stackState *S);

boolean isEmptyStack(stackState S);

void PushState(stackState *S, Peta p, TIME t, List l, Queue q, Queue q2);

void PopState(stackState *S);

void deleteAllState(stackState *S);

void PrintStack(stackState S);

#endif






