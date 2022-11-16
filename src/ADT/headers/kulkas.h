#ifndef KULKAS_H
#define KULKAS_H

#define UKURAN_BARIS 10
#define UKURAN_KOLOM 20
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

typedef struct {
	ItemKulkas contents[CAPACITY];
} ListItemKulkas;

#define ELMT_KULKAS(M, i, j) (M).matrixKulkas.mem[(i)][(j)]
#define BARIS_KULKAS(M) (M).matrixKulkas.rowEff
#define KOLOM_KULKAS(M) (M).matrixKulkas.colEff
#define JMLH_MAKANAN(M) (M).jumlahMakanan
#define ID_KULKAS(M) (M).idKulkasMakanan
#define ITEM_MAKANAN(M) (M).itemMakanan
#define ITEM_KULKAS_MAKANAN(M, i) (M).contents[(i)]

void createKulkas(Kulkas* kulkas);
/* I.S: kulkas bebas
   F.S: kulkas baru terdefinisi dengan ukuran yang ditetapkan*/

void createListItemKulkas(ListItemKulkas* listItemKulkas);
/* I.S: listItemKulkas bebas
   F.S: listItemKulkas baru terdefinisi */

ItemKulkas createItemKulkas(ListItemKulkas* listItemKulkas, Kulkas kulkas, Makanan itemMakanan);
/* Membentuk ItemKulkas yang memiliki idKulkas */

boolean insertMakananKulkas(ListItemKulkas* listItemKulkas,Kulkas* kulkas, Makanan itemMakanan, int lebar, int panjang);
/* I.S: Kulkas terdefinisi, makanan terdefinisi
   F.S: Makanan masuk ke dalam kulkas dan terhapus dari inventory player*/

void findFreeSpot(Kulkas kulkas, int lebar, int panjang, int* hasilBaris, int* hasilKolom);
/* Mencari nilai index baris dan kolom yang dapat memuat makanan dengan size tertentu */

boolean isIdMakananValid(Kulkas kulkas, int id);
/* Mengecek apakah nilai id makanan di kulkas */

Makanan ambilMakanan(ListItemKulkas* listItemKulkas, Kulkas* kulkas, int idMakanan);
/* I.S: Kulkas terdefinisi dan idMakanan terdefinisi
   F.S: Menghapus makanan yang ada di kulkas dan memasukkannya ke dalam inventory player*/

void deleteItemKulkas(ListItemKulkas *listItemKulkas, Kulkas* kulkas, int idMakananKulkas);

void deleteAllKulkas(ListItemKulkas *listItemKulkas, Kulkas* kulkas);

void copyKulkas(Kulkas kulkas, Kulkas* kulkasCopy, ListItemKulkas listItemKulkas, ListItemKulkas* listItemKulkasCopy);

void printItemKulkas(ListItemKulkas listItemKulkas);

void printKulkas(Kulkas kulkas);
/* I.S: Kulkas terdefinisi
   F.S: Mengeluarkan tampilan kulkas dengan ID Kulkas sbg identifier makanan*/

boolean isMakananInKulkas(Kulkas kulkas, int idMakananKulkas);
/* I.S Kulkas terdefinisi dan idMakananKulkas terdefinisi
   F.S Menampilkan makanan yang ada di kulkas berdasarkan idMakananKulkas*/
#endif