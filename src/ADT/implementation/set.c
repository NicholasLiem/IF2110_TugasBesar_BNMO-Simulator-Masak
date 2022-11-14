#include "../headers/set.h"

void createSet(Set *himpunan){
    Length(*himpunan) = 0;
    MakananId(*himpunan) = 0;
    for(int i = 0; i < CAPACITY; i++){
        ELMT(*himpunan, i).makananId = 0;
        ELMT(*himpunan, i).quantity = 0;
    }
}

void populateSet(Set *himpunan, int foodId, List M, ListMakanan Refer){
    Length(*himpunan) = lengthListMakanan(Refer); 
    MakananId(*himpunan) = foodId;
    for(int i = 0; i < lengthLin(M); i++){
        int currId = getElmtLin(M, i).value;
        int index = getMakananIndex(Refer, currId);
        ELMT(*himpunan, index).makananId = currId;
        ELMT(*himpunan, index).quantity += 1;
    }
}
/* I.S Himpunan terdefinisi */
/* F.S Membuat sebuah elemen dari himpunan yaitu M menjadi tidak available. */

boolean isSubset(Set himpunan1, Set himpunan2){
    boolean subset = true;
    for(int i = 0; i < Length(himpunan1); i++){
        if (ELMT(himpunan1, i).quantity > ELMT(himpunan2, i).quantity) {
            subset = false;
            break;
        }
    }
    return subset;
}
/* Mengirim true jika himpunan1 subset dari himpunan2 */

ListSet readTree(List TreeResep, ListMakanan Ref){
    ListSet Temp;
    Length(Temp) = lengthListMakanan(Ref);
    for(int i = 0; i < Length(Temp); i++){
        int currId = MAKANAN(Ref, i).id;
        List childrens = getTreeChildrenId(TreeResep, currId);
        printf("Anak %d", currId);
        displayListLin(childrens);
        printf("\n");
        Set foodRequired;
        createSet(&foodRequired);
        populateSet(&foodRequired, currId, childrens, Ref);
        SetElmt(Temp, i) = foodRequired;
    }
    return Temp;
}
/* Mengembalikan list of set yang berisi set-set dari kumpulan resep */
void addSet(Set* himpunan, int currId, ListMakanan Refer) {
    int index = getMakananIndex(Refer, currId);
    ELMT(*himpunan, index).makananId = currId;
    ELMT(*himpunan, index).quantity += 1;
}

Set getSetInventory(ListMakanan KumpulanMakanan, Queue inventory){
    Set Temp;
    createSet(&Temp);
    Temp.length = lengthListMakanan(KumpulanMakanan);
    for (int i = 0; i <= IDX_TAIL(inventory); i++){
        addSet(&Temp, inventory.buffer[i].id, KumpulanMakanan);
    }
    return Temp;
}
/* Mengembalikan set yang berisi elemen-elemen dari inventory */

void printRecommendation(Queue ListInventory, ListSet setPohon, ListMakanan Ref){
    Set Now;
    boolean found = false;
    int idx = 0;
    Set setInventory = getSetInventory(Ref, ListInventory); 
    printf("\nList Resep yang Dapat Dibuat:\n");
    for(int i = 0; i < Length(setPohon); i++){
        Set currSet = SetElmt(setPohon, i);
        printSet(currSet);
        printf("\n");
        if (isSubset(currSet, setInventory)){
            found = true;
            printf("   %d. ", (idx+1));
            Makanan curr = searchMakanan(Ref, currSet.makananId);
            printWord(curr.nama);
            printf("\n");
            idx++;
        }
    }
    if(!found){
        printf("Tidak ada resep yang dapat dibuat.\n");
    }
}

void printSet(Set set) {
    printf("Isi set ");
    for (int i = 0; i < Length(set); i++) {
        printf("%d ", ELMT(set, i).quantity);
    }
    printf("\n");
}
/* I.S KumpulanMakanan, ListRekomendasi, dan Resep terdefinisi */
/* F.S Menuliskan rekomendasi resep */