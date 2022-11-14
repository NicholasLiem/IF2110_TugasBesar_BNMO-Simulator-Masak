#include "../src/ADT/headers/prioqueuedinamik.h"

Word aksi = {"FRY", 3};
Word nama = {"TEST", 4};

int main() {
    Queue prioqueue;
    CreateQueue(&prioqueue);
    Makanan temp; 
    TIME waktu;
    CreateTime(&waktu, 0, 0, 10);
    createMakanan(&temp, 1, aksi, nama, waktu, waktu);
    enqueue(&prioqueue, temp, 'I');
    temp.exp = PrevNMenit(temp.exp, 2);
    enqueue(&prioqueue, temp, 'I');
    temp.exp = NextMenit(temp.exp);
    enqueue(&prioqueue, temp, 'I');
    displayQueue(prioqueue);
    printf("%d\n", prioqueue.capacity);
    advTime(&prioqueue, 10);
    printf("------******----");
    // dequeue(&prioqueue, &temp);
    // dequeue(&prioqueue, &temp);
    // dequeue(&prioqueue, &temp);
    displayQueue(prioqueue);
}