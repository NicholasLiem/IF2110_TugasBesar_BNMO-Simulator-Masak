#include "../headers/makanan.h"
#include "../headers/time.h"

void createMakanan(Makanan* makanan, int id, Word aksi, Word nama, TIME exp, TIME lamaPengiriman) {
	makanan->id = id;
	makanan->aksi = aksi;
    makanan->nama = nama;
	makanan->exp = exp;
	makanan->lamaPengiriman = lamaPengiriman;
}

void increaseTime(Makanan* makanan, int durasiDetik) {
    makanan->exp = NextNDetik(makanan->exp, durasiDetik);
}

void printMakanan(Makanan makanan) {
	printf("\nID: %d\n", ID(makanan));
	printf("Nama: ");
	printWord(NAMA(makanan));
    printf("\n");
	printf("Aksi: ");
	printWord(AKSI(makanan));
    printf("\n");
    printf("Expired: ");
    TulisTIME(EXP(makanan));
    printf("\n");
}

void CreateListMakanan(ListMakanan *l){
	int i = IDX_MIN;
	for(i; i < CAPACITY; i++){
		ELMT(*l, i).id = IDX_UNDEF_LIST_STATIK;
	}
}

void insertMakanan(ListMakanan *l, Makanan makanan){
	int i = IDX_MIN;
	for(i; i < CAPACITY; i++){
		if(ELMT(*l, i).id == IDX_UNDEF_LIST_STATIK){
			ELMT(*l, i) = makanan;
			break;
		}
	}
}

void displayListMakanan(ListMakanan l){
	int i = IDX_MIN;
	for(i; i < CAPACITY; i++){
		if(ELMT(l, i).id != IDX_UNDEF_LIST_STATIK){
			printMakanan(ELMT(l, i));
		}
	}
}

int lengthListMakanan(ListMakanan l){
	int i;
	int count = 0;
	for(i = IDX_MIN; i < CAPACITY; i++){
		if(ELMT(l, i).id != IDX_UNDEF_LIST_STATIK){
			count++;
		}
	}
	return count;
}