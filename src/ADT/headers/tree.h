// Implementasi N-ary tree dengan representasi pointer

#ifndef TREE_H
#define TREE_H

#include "boolean.h"

#define ElType int

// Definisi tNode:
typedef struct tNode * address;
typedef struct tNode {
    ElType info;
    address firstChild;
    address nextSibling;
} Node;
typedef address Tree;


/* Selektor */
#define INFO(P) (P)->info
#define FCHILD(P) (P)->firstChild
#define SIBLING(P) (P)->nextSibling
#define ROOT(T) (T)


/* *** Konstruktor *** */
void CreateTree(Tree *T);
/* I.S. T sembarang */
/* F.S. Terbentuk pohon T kosong */

/* Manajemen Memory */
address AlokNode(ElType X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X,  FirstChild(P)=Nil, NextSibling(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */

void DealokNode(address P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty(Tree T);
/* Mengirimkan true jika pohon T kosong */
boolean IsTreeOneElmt(Tree T);
/* Mengirimkan true jika pohon T tidak kosong dan hanya memiliki 1 elemen */
boolean IsSubsTree(Tree T1, Tree T2);
/* Mengirimkan true jika pohon T1 merupakan pohon induk dari T2 */
/* yaitu semua simpul T2 adalah simpul T1 */

/* *** Traversal *** */
void PrintTree(Tree T, int h);
/* I.S. T terdefinisi, h adalah jarak indentasi */
/* F.S. Semua simpul T dicetak dengan indentasi sebanyak h */
/* Setiap pohon ditulis dengan pohon kiri di sebelah kiri dan */
/* pohon kanan di sebelah kanan */
/* Contoh: jika h=2, maka setiap simpul dicetak dengan indentasi 2 */
/* Contoh: jika h=0, maka setiap simpul dicetak tanpa indentasi */
/* Contoh: jika h=-1, maka setiap simpul dicetak dengan indentasi -1 */

/* *** Searching *** */
address SearchTree(Tree T, ElType X);
/* Mengirimkan address simpul dengan Info(P)=X */
/* Jika tidak ada simpul dengan Info(P)=X, mengirimkan Nil */

/* *** Fungsi-Fungsi Lain *** */
int NbElmt(Tree T);
/* Mengirimkan banyaknya elemen (node) pohon biner T */
/* Mengirimkan 0 jika T kosong */
boolean IsDaun(Tree T);
/* Mengirimkan true jika T adalah pohon biner kosong atau T adalah daun */
int Tinggi(Tree T);
/* Mengirimkan tinggi pohon biner T */
/* Mengirimkan 0 jika T kosong */
int TinggiDaun(Tree T);
/* Mengirimkan tinggi daun terkecil di pohon biner T */
/* Mengirimkan 0 jika T kosong */

/* *** Operasi lain *** */
void AddDaunTerkiri(Tree *P, ElType X);
/* I.S. P tidak kosong, X terdefinisi */
/* F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri */
void AddDaun(Tree *P, ElType X, ElType Y, boolean Kiri);
/* I.S. P tidak kosong, X terdefinisi */
/* F.S. P bertambah simpulnya, dengan X sebagai anak Y */
/* Jika Kiri = true, maka X menjadi anak kiri Y */
/* Jika Kiri = false, maka X menjadi anak kanan Y */
void DelDaunTerkiri(Tree *P, ElType *X);
/* I.S. P tidak kosong */
/* F.S. P dihapus simpul daun terkiri, dengan X adalah Info(P) yang dihapus */
/* Jika P adalah pohon biner kosong, maka P harus tetap kosong */
void DelDaun(Tree *P, ElType X);
/* I.S. P tidak kosong */
/* F.S. P dihapus simpulnya, dengan X adalah Info(P) yang dihapus */
/* Jika ada lebih dari 1 daun berInfo(X), yang dihapus adalah daun terkiri */
/* Jika tidak ada daun berInfo(X), maka P tetap */
/* Jika P menjadi pohon biner kosong, maka P harus tetap kosong */

#endif