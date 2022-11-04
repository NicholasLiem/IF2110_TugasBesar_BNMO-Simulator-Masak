#include <stdio.h>
#include <stdlib.h>
#include "../headers/listlinier.h"

Address newNode(ListType val){
    Address p = (Address) malloc(sizeof(Node));
    if (p != NULL){
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}

/* Definisi List : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
/**
 * Tulis jenis elemen list, lihat list elemen yang dapat digunakan di listlinier.h
*/
void CreateListLin(List *l, int elType){
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
    FIRST((*l)) = NULL;
    TYPE((*l)) = elType;
}

/****************** TEST LIST KOSONG ******************/
boolean isEmptyLin(List l){
/* Mengirim true jika list kosong */
    return (FIRST(l) == NULL);
}

/****************** GETTER SETTER ******************/
ListType getElmtLin(List l, int idx){
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */
    Address p = FIRST(l);
    int i = 0;
    while (i < idx){
        p = NEXT(p);
        i++;
    }
    return INFO(p);
}

void setElmtLin(List *l, int idx, ListType val){
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */
    Address p = FIRST((*l));
    int i = 0;
    while (i < idx){
        p = NEXT(p);
        i++;
    }
    INFO(p) = val;
}

int indexOfLin(List l, ListType val){
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */
    Address p = FIRST(l);
    int i = 0;
    while (p != NULL){
        switch(TYPE(l)) {
            //merupakan int
            case 1:
                if (INFO(p).value == val.value){
                    return i;
                }
                break;
            // merupakan int*
            case 2:
                if (INFO(p).address == val.address){
                    return i;
                }
                break;
            case 3:
                if (INFO(p).makanan.id == val.makanan.id){
                    return i;
                }
                break;
            case 4:
                if (isEqualWord(INFO(p).kata, val.kata)) {
                    return i;
                }
                break;
            default:
                break;
        }
        p = NEXT(p);
        i++;
    }
    return IDX_UNDEF;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirstLin(List *l, ListType val){
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */
    Address p = newNode(val);
    if(p != NULL){
        NEXT(p) = FIRST((*l));
        FIRST((*l)) = p;
    }
}

void insertLastLin(List *l, ListType val){
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    Address p = newNode(val);
    if (p != NULL){
        if (isEmptyLin(*l)){
            FIRST((*l)) = p;
        } else {
            Address last = FIRST((*l));
            while (NEXT(last) != NULL){
                last = NEXT(last);
            }
            NEXT(last) = p;
        }
    }

}

void insertAtLin(List *l, ListType val, int idx){
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    Address p = newNode(val);
    if (p != NULL){
        if (idx == 0){
            insertFirstLin(l, val);
        } else {
            Address prev = FIRST((*l));
            int i = 0;
            while (i < idx - 1){
                prev = NEXT(prev);
                i++;
            }
            NEXT(p) = NEXT(prev);
            NEXT(prev) = p;
        }
    }
    
}

// /*** PENGHAPUSAN ELEMEN ***/
void deleteFirstLin(List *l, ListType *val){
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
    Address p = FIRST((*l));
    *val = INFO(p);
    FIRST((*l)) = NEXT(p);
    free(p);
}

void deleteLastLin(List *l, ListType *val){
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */
    Address p = FIRST((*l));
    if (NEXT(p) == NULL){
        deleteFirstLin(l, val);
    } else {
        Address prev = p;
        p = NEXT(p);
        while (NEXT(p) != NULL){
            prev = p;
            p = NEXT(p);
        }
        *val = INFO(p);
        NEXT(prev) = NULL;
        free(p);
    }
}

void deleteAtLin(List *l, int idx, ListType *val){
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */
    Address p = FIRST((*l));
    if (idx == 0){
        deleteFirstLin(l, val);
    } else {
        Address prev = p;
        int i = 0;
        while (i < idx){
            prev = p;
            p = NEXT(p);
            i++;
        }
        *val = INFO(p);
        NEXT(prev) = NEXT(p);
        free(p);
    }
}


// /****************** PROSES SEMUA ELEMEN LIST ******************/
void displayListLin(List l){
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    Address p = FIRST(l);
    int i = 1;
    while (p != NULL){
        switch(TYPE(l)) {
            //merupakan int
            case 1:
                printf("%d", INFO(p).value);
                break;
            // merupakan int*
            case 2:
                printf("%p", INFO(p).address);
                break;
            case 3:
                printMakanan(INFO(p).makanan);
                break;
            case 4:
                printf("   %d. ", i);
                printWord(INFO(p).kata);
                printf("\n");
                break;
            default:
                break;
        }
        i += 1;
        p = NEXT(p);
    }
}

int lengthLin(List l){
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
    int n = 0;
    Address p = FIRST(l);
    while (p != NULL){
        n++;
        p = NEXT(p);
    }
    return n;
}

void insertNotif(List* l1, Word notif) {
    ListType notifEl;
    notifEl.kata = notif;
    insertFirstLin(l1, notifEl);
}
/****************** PROSES TERHADAP LIST ******************/
List concatLin(List l1, List l2) {
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */
    List l3;
    CreateListLin(&l3, TYPE(l1));
    Address p = FIRST(l1);
    while (p != NULL){
        insertLastLin(&l3, INFO(p));
        p = NEXT(p);
    }
    p = FIRST(l2);
    while (p != NULL){
        insertLastLin(&l3, INFO(p));
        p = NEXT(p);
    }
    return l3;
}