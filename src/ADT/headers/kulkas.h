#ifndef KULKAS_H
#define KULKAS_H

#define UKURAN_BARIS 50
#define UKURAN_KOLOM 50
#define ID_KOSONG 0

#include "boolean.h"
#include "makanan.h"
#include "matrix.h"
#include "word.h"
#include <stdlib.h>

typedef struct { 
	Matrix matrixKulkas;
    int jumlahMakanan;
} Kulkas;

typedef struct {
	Makanan itemMakanan;
   int idKulkasMakanan;
} ItemKulkas;

#define ELMT_KULKAS(M, i, j) (M).matrixKulkas.mem[(i)][(j)]
#define BARIS_KULKAS(M) (M).matrixKulkas.rowEff
#define KOLOM_KULKAS(M) (M).matrixKulkas.colEff
#define JMLH_MAKANAN(M) (M).jumlahMakanan
#define ID_KULKAS(M) (M).idKulkasMakanan
#define ITEM_MAKANAN(M) (M).itemMakanan

void createKulkas(Kulkas* kulkas);
/* I.S: kulkas bebas
   F.S: kulkas baru terdefinisi dengan ukuran yang ditetapkan*/

ItemKulkas createItemKulkas(Kulkas kulkas, Makanan itemMakanan);
/* Membentuk ItemKulkas yang memiliki idKulkas */

void insertMakananKulkas(Kulkas* kulkas, Makanan itemMakanan);
/* I.S: Kulkas terdefinisi, makanan terdefinisi
   F.S: Makanan masuk ke dalam kulkas dan terhapus dari inventory player*/

void findFreeSpot(Kulkas kulkas, int lebar, int panjang, int* hasilBaris, int* hasilKolom);
/* Mengecek apakah suatu makanan dengan size tertentu bisa dimasukkan ke kulkas 
   akan dikembalikan nilai false jika tidak bisa */

boolean isIdMakananValid(Kulkas kulkas, int id);
/* Mengecek apakah nilai id makanan di kulkas */

void ambilMakanan(Kulkas* kulkas, int idMakanan);
/* I.S: Kulkas terdefinisi dan idMakanan terdefinisi
   F.S: Menghapus makanan yang ada di kulkas dan memasukkannya ke dalam inventory player*/

void printKulkas(Kulkas kulkas);

void searchMakananKulkas(Kulkas kulkas, int idMakananKulkas);
void listMakananKulkas(Kulkas kulkas);
#endif