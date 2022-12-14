#ifndef SET_H
#define SET_H

#include "../boolean.h"
#include "../makanan/makanan.h"
#include "../wordmachine/wordmachine.h"
#include "../charmachine/charmachine.h"
#include "../time/time.h"
#include "../tree/tree.h"
#include "../prioqueuedinamik/prioqueuedinamik.h"
// #include "simulator.h"


typedef struct {
    int quantity;
    int makananId;
    boolean terminal;
} SetElmt;

typedef struct {
   SetElmt contents[CAPACITY];
   int length;
   int makananId;
   boolean terminal;
} Set;

typedef struct {
    Set contents[CAPACITY];
    int length;
} ListSet;

/* ********** SELEKTOR ********** */
#define SetElmt(l, i) (l).contents[(i)]
#define MakananId(s) (s).makananId
#define Terminal(s) (s).terminal
#define Available(el) el.available
#define IDElmtSet(el) el.ID
#define Length(l) (l).length
#define Rekomendasi(l) (l).nama
#define JumlahSet(L) (L).JumlahSet


void createSet(Set *himpunan);

void populateSet(Set *himpunan, int foodId, List M, ListMakanan Refer);
/* I.S Himpunan terdefinisi */
/* F.S Membuat sebuah elemen dari himpunan yaitu M menjadi tidak available. */

boolean isSubset(Set himpunan1, Set himpunan2, ListSet pohon);
/* Mengirim true jika himpunan1 subset dari himpunan2 */

ListSet readTree(List TreeResep, ListMakanan Ref);
/* Mengembalikan list of set yang berisi set-set dari kumpulan resep */
void addSet(Set* himpunan, int currId, ListMakanan Refer);

Set getSetInventory(ListMakanan KumpulanMakanan, Queue inventory);
/* Mengembalikan set yang berisi elemen-elemen dari inventory */

void printRecommendation(Queue ListInventory, ListSet setPohon, ListMakanan Ref);
/* I.S KumpulanMakanan, ListRekomendasi, dan Resep terdefinisi */
/* F.S Menuliskan rekomendasi resep */

void printSet(Set set);

Set unionSet(Set himpunan1, Set himpunan2);
#endif