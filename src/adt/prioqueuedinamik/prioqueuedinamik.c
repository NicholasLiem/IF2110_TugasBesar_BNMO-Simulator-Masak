#include "prioqueuedinamik.h"

void CreateQueue(Queue *q) {
    BUFFER((*q)) = malloc(sizeof(ElTypeQueue) * (CAPACITY_MULT+1));
    q->capacity = CAPACITY_MULT;
    IDX_TAIL((*q)) = IDX_UNDEF;
};

void expandQueue(Queue *q) {
    BUFFER((*q)) = realloc(BUFFER((*q)), sizeof(ElTypeQueue) * (q->capacity + CAPACITY_MULT+2));
    q->capacity += CAPACITY_MULT;
};

boolean isEmptyQ(Queue q) {
    return IDX_TAIL(q) == IDX_UNDEF;
};

boolean isFullQ(Queue q) {
    return IDX_TAIL(q) == (q.capacity-1);
};

void enqueue(Queue *q, ElTypeQueue val, char c) {
    if (isEmptyQ(*q)) {
        IDX_TAIL((*q)) = 0;
        TAIL((*q)) = val;
    } else {
        if (isFullQ(*q)) {
            expandQueue(q);
        }
        IDX_TAIL((*q)) += 1;
        TAIL((*q)) = val;
        sortQueue(q, c);
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

int indexOfId(Queue q, ElType id){
    int i;
    for(i = IDX_MIN; i <= IDX_TAIL(q); i++){
        if((q).buffer[i].id == id){
            return i;
        }
    }
    return -1;
}

int lengthQueue(Queue q){
    int i, count = 0;
    for(i = IDX_MIN; i <= IDX_TAIL(q); i++){
        count++;
    }
    return count;
}

Makanan makananOfIndex(Queue q, int idx){
    return q.buffer[idx];
}

void deleteAtQueue(Queue *q, int idx){
    if(IDX_TAIL(*q) == 0){
        IDX_TAIL(*q) = IDX_UNDEF;
    } else{
        shiftLeft(q, idx);
        IDX_TAIL(*q) -= 1;
    }
}

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

void sortQueue(Queue *l, char c) {
    int i, j;
    for (i = 0; i < IDX_TAIL(*l)+1; i++) {
        for (j = i+1; j < IDX_TAIL(*l)+1; j++) {
            Makanan makanan1 = (*l).buffer[i];
            Makanan makanan2 = (*l).buffer[j];
            if (c == 'I') {
                if (TGT(makanan1.exp, makanan2.exp)) {
                    (*l).buffer[i] = makanan2;
                    (*l).buffer[j] = makanan1;
                }
            } else {
                if (TGT(makanan1.lamaPengiriman, makanan2.lamaPengiriman)) {
                    (*l).buffer[i] = makanan2;
                    (*l).buffer[j] = makanan1;
                }
            }
        }
    }
};

void advTimeExpired(Queue *q, int time) {
    int i;
    for (i = 0; i < IDX_TAIL(*q)+1; i++) {
        (*q).buffer[i].exp = PrevNMenit((*q).buffer[i].exp, time);
    }
};

void revTimeExpired(Queue *q, int time) {
    int i;
    for (i = 0; i < IDX_TAIL(*q)+1; i++) {
        (*q).buffer[i].exp = NextNMenit((*q).buffer[i].exp, time);
    }
};

void advTimeDelivery(Queue *q, int time) {
    int i;
    for (i = 0; i < IDX_TAIL(*q)+1; i++) {
        (*q).buffer[i].lamaPengiriman = PrevNMenit((*q).buffer[i].lamaPengiriman, time);
    }
};

void revTimeDelivery(Queue *q, int time) {
    int i;
    for (i = 0; i < IDX_TAIL(*q)+1; i++) {
        (*q).buffer[i].lamaPengiriman = NextNMenit((*q).buffer[i].lamaPengiriman, time);
    }
};

void deleteQ(Queue *q) {
    // delete using dequeue
    ElTypeQueue val;
    while (!isEmptyQ(*q)) {
        dequeue(q, &val);
    }
};

void copyInv(Queue q1, Queue *q2) {
    // copy content from q1 to q2
    for (int i = 0; i < IDX_TAIL(q1)+1; i++) {
        enqueue(q2, (q1).buffer[i], 'I');
    }
};

void copyDel(Queue q1, Queue *q2) {
    for (int i = 0; i < IDX_TAIL(q1)+1; i++) {
        enqueue(q2, (q1).buffer[i], 'D');
    }
};

void removeExpired(Queue *q, List* listNotif, List* listUndo) {
    TIME expired;
    CreateTime(&expired, 0, 0, 0);
    if (isEmptyQ(*q)) {
        return;
    }
    while (!isEmptyQ(*q) && (TEQ((*q).buffer[0].exp, expired) || TLT((*q).buffer[0].exp, expired))) {
        Makanan exp;
        dequeue(q, &exp);
        Word notif;
        setWord(&notif, "Makanan ini telah expired: ");
        appendWord(&notif, exp.nama);
        insertNotif(listNotif, notif);

        setWord(&notif, "Wow! Makanan ini enggak jadi expired! ");
        appendWord(&notif, exp.nama);
        insertNotif(listUndo, notif);
    }
};


List removeArrived(Queue *q, List* listNotif, List* listUndo) {
    TIME expired;
    List makananExpired;
    CreateTime(&expired, 0, 0, 0);
    CreateListLin(&makananExpired, 3);
    if (isEmptyQ(*q)) {
        return makananExpired;
    }
    while (!isEmptyQ(*q) &&(TEQ((*q).buffer[0].lamaPengiriman, expired) || TLT((*q).buffer[0].lamaPengiriman, expired))) {
        Makanan exp;
        dequeue(q, &exp);
        Word notif;
        Word notifUndo;
        Word COMMAND_BUY = {"BUY", 3};
        if(isEqualWord(exp.aksi, COMMAND_BUY)){
            // TulisTIME((*q).buffer[0].lamaPengiriman);
            setWord(&notif, "Hore! Makanan ini telah sampai: ");
            appendWord(&notif, exp.nama);
        }
        else{
            setWord(&notif, "Yay! Makanan ini berhasil dibuat: ");
            appendWord(&notif, exp.nama);
        }
        setWord(&notifUndo, "Tiba-tiba, makanan ini menghilang dari tasmu :( ");
        appendWord(&notifUndo, exp.nama);
        insertNotif(listNotif, notif);
        insertNotif(listUndo, notifUndo);
        ListType temp;
        temp.makanan = exp;
        insertFirstLin(&makananExpired, temp);
    }
    return makananExpired;
};


void displayQueuePretty(Queue q, char type) {
    if (isEmptyQ(q)) {
        printf("\n Kosong :( \n");
    } else {
        for (int i = 0; i <= IDX_TAIL(q); i++) {
            printf("\n %d. ", i+1);
            printWord(q.buffer[i].nama);
            printf(" ---- ");
            if (type == 'I') {
                printf("Sisa waktu sebelum busuk: ");
                printWord(timeToWord(q.buffer[i].exp));
            } else {
                printf("Sisa waktu sebelum sampai: ");
                printWord(timeToWord(q.buffer[i].lamaPengiriman));
            }
        }
    }
}