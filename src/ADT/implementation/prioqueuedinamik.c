#include "../headers/prioqueuedinamik.h"

void CreateQueue(Queue *q) {
    BUFFER((*q)) = malloc(sizeof(ElTypeQueue) * (CAPACITY_MULT+1));
    q->capacity = CAPACITY_MULT;
    IDX_TAIL((*q)) = IDX_UNDEF;
};

void expandQueue(Queue *q) {
    BUFFER((*q)) = realloc(q, sizeof(ElTypeQueue) * (q->capacity + CAPACITY_MULT));
    q->capacity += CAPACITY_MULT;
};

boolean isEmptyQ(Queue q) {
    return IDX_TAIL(q) == IDX_UNDEF;
};

boolean isFullQ(Queue q) {
    return IDX_TAIL(q) == (q.capacity-1);
};

void enqueue(Queue *q, ElTypeQueue val) {
    if (isEmptyQ(*q)) {
        IDX_TAIL((*q)) = 0;
        TAIL((*q)) = val;
    } else {
        if (isFullQ(*q)) {
            expandQueue(q);
        }
        IDX_TAIL((*q)) += 1;
        TAIL((*q)) = val;
        sortQueue(q);
    }
};

boolean dequeue(Queue *q, ElTypeQueue *val) {
    if (isEmptyQ(*q)) {
        return false;
    } else {
        *val = (*q).buffer[0];
        if (IDX_TAIL((*q)) == 0) {
            IDX_TAIL((*q)) = IDX_UNDEF;
        } else {
            shiftLeft(q, 0);
            IDX_TAIL((*q)) -= 1;
        }
        return true;
    }
};

void shiftLeft(Queue *q, int startPos) {
    for (int i = startPos; i < IDX_TAIL((*q)); i++) {
        q->buffer[i] = q->buffer[i+1];
    }
}

void displayQueue(Queue q) {
    for (int i = 0; i <= IDX_TAIL(q); i++) {
        printMakanan(q.buffer[i]);
        printf("----");
    }
};

void sortQueue(Queue *l) {
    int i, j;
    for (i = 0; i < IDX_TAIL(*l)+1; i++) {
        for (j = i+1; j < IDX_TAIL(*l)+1; j++) {
            Makanan makanan1 = (*l).buffer[i];
            Makanan makanan2 = (*l).buffer[j];
            if (TGT(makanan1.exp, makanan2.exp)) {
                (*l).buffer[i] = makanan2;
                (*l).buffer[j] = makanan1;
            }
        }
    }
};

void advTime(Queue *q, int time) {
    int i;
    for (i = 0; i < IDX_TAIL(*q)+1; i++) {
        (*q).buffer[i].exp = PrevNMenit((*q).buffer[i].exp, time);
    }
};

void removeExpired(Queue *q, List* listNotif) {
    TIME expired;
    CreateTime(&expired, 0, 0, 0);
    while (TEQ((*q).buffer[0].exp, expired) || TLT((*q).buffer[0].exp, expired)) {
        Makanan exp;
        dequeue(q, &exp);
        Word notif;
        setWord(&notif, "Makanan ini telah expired: ");
        appendWord(&notif, exp.nama);
        ListType notifEl;
        notifEl.kata = notif;
        insertFirstLin(listNotif, notifEl);
    }
};