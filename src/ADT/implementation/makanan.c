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
	printf("\nID: %d\n", makanan.id);
	printf("Nama: ");
	printWord(makanan.nama);
    printf("\n");
	printf("Aksi: ");
	printWord(makanan.aksi);
    printf("\n");
    printf("Expired: ");
    TulisTIME(makanan.exp);
    printf("\n");
}