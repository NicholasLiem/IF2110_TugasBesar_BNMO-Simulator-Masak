// Implementasi N-ary tree dengan representasi pointer

#ifndef TREE_H
#define TREE_H

#include "../boolean.h"
#include "../listlinier/listlinier.h"
#include "../makanan/makanan.h"

#define ElType int

typedef struct treeNode {
    ElType foodId;
    List listChildren;
} TreeNode;

typedef struct Node *addrNode;

typedef addrNode Tree;
typedef int infotype;

/* Selektor */
#define FOODID(P) (P)->foodId
#define CHILDREN(T) (T)->listChildren

#define treeAddress TreeNode*
/* *** Konstruktor *** */
void CreateTree(treeAddress* T);
/* I.S. T sembarang */
/* F.S. Terbentuk pohon T kosong */

/* Manajemen Memory */
treeAddress AlokNode(ElType X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X,  FirstChild(P)=Nil, NextSibling(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */


/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty(treeAddress T);
/* Mengirimkan true jika pohon T kosong */

boolean IsSubsTree(treeAddress T1, treeAddress T2);
/* Mengirimkan true jika pohon T1 merupakan pohon induk dari T2 */
/* yaitu semua simpul T2 adalah simpul T1 */

/* *** Traversal *** */
void PrintTree(treeAddress T, ListMakanan l);
/* I.S. T terdefinisi, h adalah jarak indentasi */
/* F.S. Semua simpul T dicetak  */

/* *** Searching *** */
treeAddress SearchTree(treeAddress T, ElType X);
/* Mengirimkan address simpul dengan Info(P)=X */
/* Jika tidak ada simpul dengan Info(P)=X, mengirimkan Nil */


/* *** Fungsi-Fungsi Lain *** */
int NbElmt(treeAddress T);
/* Mengirimkan banyaknya elemen (node) pohon biner T */
/* Mengirimkan 0 jika T kosong */

void addRoot(treeAddress *p, ElType root);


void addChild(treeAddress *P, ElType parent, ElType child);
/* I.S. P tidak kosong, X terdefinisi */
/* F.S. P bertambah simpulnya, dengan X sebagai anak Y */
/* Jika Kiri = true, maka X menjadi anak kiri Y */
/* Jika Kiri = false, maka X menjadi anak kanan Y */

void printListResep(List p, ListMakanan l);

List getTreeChildrenId(List T, ElType parent);

void PrintTreePlain(treeAddress T);
List getAllTreeChildrenId(List T, ElType parent);

#endif