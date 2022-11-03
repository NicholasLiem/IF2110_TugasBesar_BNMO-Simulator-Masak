/* File : queue.h */
/* ADT PRIOQUEUE DINAMIS, SELALU RATA KIRI"*/

#ifndef QUEUE_H
#define QUEUE_H

#include "boolean.h"
#include "makanan.h"
#include "listlinier.h"

#define CAPACITY_MULT 100

/* Definisi elemen dan address */
typedef Makanan ElTypeQueue;
typedef struct {
	ElTypeQueue * buffer; 
	int idxTail;
    int capacity;
} Queue;


/* ********* AKSES (Selektor) ********* */
/* Jika q adalah Queue, maka akses elemen : */
#define BUFFER(q) (q).buffer
#define IDX_TAIL(q) (q).idxTail
#define     TAIL(q) (q).buffer[(q).idxTail]

void CreateQueue(Queue *q);

void expandQueue(Queue *q);

boolean isEmptyQ(Queue q);

boolean isFullQ(Queue q);

void enqueue(Queue *q, ElTypeQueue val);

boolean dequeue(Queue *q, ElTypeQueue *val);

void displayQueue(Queue q);

void sortQueue(Queue *q);

void shiftLeft(Queue *q, int startPos);


void advTime(Queue *q, int time);

void removeExpired(Queue* q, List* notifWord);


#endif