#include "../src/adt/prioqueuedinamik/prioqueuedinamik.h"
Word aksi = {"FRY", 3};
Word nama = {"TEST", 4};

// gcc -std=c17 -I. src/adt/charmachine/*.c src/adt/kulkas/*.c src/adt/listlinier/*.c src/adt/liststatik/*.c src/adt/makanan/*.c src/adt/matrix/*.c src/adt/peta/*.c src/adt/point/*.c src/adt/prioqueuedinamik/*.c src/adt/set/*.c src/adt/stack/*.c src/adt/time/*.c src/adt/tree/*.c src/adt/word/*.c src/adt/wordmachine/*.c src/helper/command/*.c src/helper/configparser/*.c src/helper/simulator/*.c -o bin/prioqueue tests/prioqueue.c

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
    advTimeDelivery(&prioqueue, 10);
    printf("------******----");
    // dequeue(&prioqueue, &temp);
    // dequeue(&prioqueue, &temp);
    // dequeue(&prioqueue, &temp);
    displayQueue(prioqueue);
}