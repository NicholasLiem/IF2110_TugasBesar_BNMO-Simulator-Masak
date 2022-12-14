#include "makanan.h"

void createMakanan(Makanan* makanan, int id, Word aksi, Word nama, TIME exp, TIME lamaPengiriman) {
	makanan->id = id;
	makanan->aksi = aksi;
    makanan->nama = nama;
	makanan->exp = exp;
	makanan->lamaPengiriman = lamaPengiriman;
	makanan->lebar = 0;
	makanan->panjang = 0;
}

void setLebarMakanan(Makanan* makanan, int lebar){
	makanan->lebar = lebar;
}

void setPanjangMakanan(Makanan* makanan, int panjang){
	makanan->panjang = panjang;
}

void increaseTime(Makanan* makanan, int durasiMenit) {
    makanan->exp = NextNMenit(makanan->exp, durasiMenit);
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

void createListMakanan(ListMakanan *l){
	int i;
	for(i = IDX_MIN; i < CAPACITY; i++){
		ELMT(*l, i).id = IDX_UNDEF_LIST_STATIK;
	}
}

void insertMakanan(ListMakanan *l, Makanan makanan){
	int i;
	for(i = IDX_MIN; i < CAPACITY; i++){
		if(ELMT(*l, i).id == IDX_UNDEF_LIST_STATIK){
			ELMT(*l, i) = makanan;
			break;
		}
	}
}

void displayListMakanan(ListMakanan l){
	int i;
	for(i = 0; i < lengthListMakanan(l); i++){
		if(ELMT(l, i).id != IDX_UNDEF_LIST_STATIK){
			printMakanan(ELMT(l, i));
		}
	}
}

void commandCatalog(ListMakanan l){
	int i;
	for(i = IDX_MIN; i < lengthListMakanan(l); i++){
		if(ELMT(l, i).id != IDX_UNDEF_LIST_STATIK){
			printf("%d. ", i+1);
			printWord(ELMT(l, i).nama);
			printf(" - ");
			TulisTIME(ELMT(l, i).exp);
			printf("- ");
			printWord(ELMT(l, i).aksi);
			printf(" - ");
			TulisTIME(ELMT(l, i).lamaPengiriman);
			printf("\n");
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

Makanan searchMakanan(ListMakanan L, int ID){
	int i;
	Makanan null;
	TIME tnull;
	CreateTime(&tnull, 0, 0, 0);
	Word nama;
	setWord(&nama, "null");
	createMakanan(&null, IDX_UNDEF_LIST_STATIK, nama, nama, tnull, tnull);
	for(i = IDX_MIN; i < lengthListMakanan(L); i++){
			if(ID(L.contents[i]) == ID){
				return ELMT(L, i);
			}
		}
	return null;
}
Makanan searchMakananCommand(ListMakanan l, int ID, Word action) {
	int i;
	Makanan null;
	TIME tnull;
	CreateTime(&tnull, 0, 0, 0);
	Word nama;
	setWord(&nama, "null");
	createMakanan(&null, IDX_UNDEF_LIST_STATIK, nama, nama, tnull, tnull);
	for(i = IDX_MIN; i < lengthListMakanan(l); i++){
			if(ID(l.contents[i]) == ID && isEqualWord(ELMT(l, i).aksi, action)){
				return ELMT(l, i);
			}
		}
	return null;
};

void displayMakananList(ListMakanan l, Word action) {
	int i;
	for(i = 0; i < lengthListMakanan(l); i++){
		if (isEqualWord(ELMT(l, i).aksi, action)){
			printf("ID (%d). ", ELMT(l,i).id);
			printWord(ELMT(l, i).nama);
			printf(" --- Duration: ");
			TulisTIME(ELMT(l, i).lamaPengiriman);
			printf("\n");
		}
	}	
}
int getMakananIndex(ListMakanan l, int ID) {
	int i;
	for(i = 0; i < lengthListMakanan(l); i++){
		if (ELMT(l, i).id == ID){
			return i;
		}
	}	
	return -1;
};