#ifndef MAKANAN_H
#define MAKANAN_H

#define MAX_CHAR 100
#define CAPACITY 100

#include "boolean.h"
#include "time.h"
#include "point.h"
#include "word.h"
#include "liststatik.h"
#include <stdlib.h>

typedef struct { 
	int id; 
	Word nama;
	Word aksi;
	TIME exp;
	TIME lamaPengiriman;
} Makanan;

typedef struct {
	Makanan contents[CAPACITY];
} ListMakanan;

/* *** Notasi Akses: Selektor POINT *** */
#define ID(P) (P).id
#define NAMA(P) (P).nama
#define AKSI(P) (P).aksi
#define EXP(P) (P).exp
#define LAMAPENGIRIMAN(P) (P).lamaPengiriman

void createMakanan(Makanan* makanan, int id, Word aksi, Word nama, TIME exp, TIME lamaPengiriman);

void printMakanan(Makanan makanan);

void increaseTime(Makanan* makanan, int lamaDetik);

void CreateListMakanan(ListMakanan *l);

void insertMakanan(ListMakanan *l, Makanan makanan);

void displayListMakanan(ListMakanan l);

int lengthListMakanan(ListMakanan l);
#endif