
#include "../headers/tree.h"
#include "../headers/listlinier.h"

/* *** Konstruktor *** */
void CreateTree(treeAddress* T) {
    (*T) = NULL;    
};
/* I.S. T sembarang */
/* F.S. Terbentuk pohon T kosong */

/* Manajemen Memory */
treeAddress createTreeNode(ElType X) {
    treeAddress temp = malloc(sizeof(TreeNode));
    FOODID(temp) = X;
    List children;
    CreateListLin(&children, 2);
    CHILDREN(temp) = children;
    return temp;
};
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X,  FirstChild(P)=Nil, NextSibling(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */

/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty(treeAddress T) {
    if (T == NULL) {
        return true;
    }
    return false;
};
/* Mengirimkan true jika pohon T kosong */

boolean IsSubsTree(treeAddress T1, treeAddress T2) {

};
/* Mengirimkan true jika pohon T1 merupakan pohon induk dari T2 */
/* yaitu semua simpul T2 adalah simpul T1 */

/* *** Traversal *** */
void PrintTree(treeAddress T) {
    printf("Node: %d\n", FOODID(T));  
    int index = 0;
    List children = CHILDREN(T);
    if (isEmptyLin(children)) {
        printf("Leaf Node\n");
    } else {
        printf("Children: \n"); 
        while (index < lengthLin((CHILDREN(T)))) {
            ListType addr = getElmtLin(children, index);
            treeAddress child = (treeAddress) addr.address;
            printf("%d ", FOODID(child));
            index+=1;
        }
        printf("\n");
        // Rekursi
        index = 0;
        while (index < lengthLin((CHILDREN(T)))) {
            ListType addr = getElmtLin(children, index);
            treeAddress child = (treeAddress) addr.address;
            PrintTree(child);
            index += 1;
        }
    }
};
/* I.S. T terdefinisi, h adalah jarak indentasi */
/* F.S. Semua simpul T dicetak  */

/* *** Searching *** */
treeAddress SearchTree(treeAddress T, ElType X) {
    if (FOODID(T) == X) {
        return T;
    }
    // Rekursi
    int index = 0;
    List children = CHILDREN(T);
    while (index < lengthLin((CHILDREN(T)))) {
        ListType addr = getElmtLin(children, index);
        treeAddress child = (treeAddress) addr.address;
        treeAddress hasil = SearchTree(child, X);
        index += 1;
        if (hasil != NULL) {
            return hasil;
        }
    }
    return NULL;
};
/* Mengirimkan address simpul dengan Info(P)=X */
/* Jika tidak ada simpul dengan Info(P)=X, mengirimkan Nil */

/* *** Fungsi-Fungsi Lain *** */
int NbElmt(treeAddress T) {

};
/* Mengirimkan banyaknya elemen (node) pohon biner T */
/* Mengirimkan 0 jika T kosong */

void addRoot(treeAddress *p, ElType root) {
    CreateTree(p);
    treeAddress tempNode = createTreeNode(root);
    (*p) = tempNode;
};

void addChild(treeAddress *p, ElType parent, ElType child) {
    treeAddress currNode = SearchTree(*p, parent);
    if (currNode != NULL) {
        treeAddress alreadyExist = SearchTree(*p, child);
        // Sudah ada elemen ini sebelumnya, kita refer ke dia saja.
        if (alreadyExist != NULL) {
            ListType tampung;
            tampung.address = alreadyExist;
            insertFirstLin(&CHILDREN(currNode), tampung);
        } else {
            // Buat yang baru
            treeAddress newNode = createTreeNode(child);
            ListType tampung;
            tampung.address = newNode;
            insertFirstLin(&CHILDREN(currNode), tampung);
        }
    }
};
/* I.S. P tidak kosong, X terdefinisi */
/* F.S. P bertambah simpulnya, dengan X sebagai anak Y */
