#ifndef MAKANAN_H
#define MAKANAN_H

#define MAX_CHAR 100

#include "boolean.h"
#include "time.h"
#include "point.h"
#include "word.h"
#include <stdlib.h>
typedef struct { 
	int id; 
	Word nama;
	Word aksi;
	TIME exp;
	TIME lamaPengiriman;
} Makanan;

/* *** Notasi Akses: Selektor POINT *** */
#define ID(P) (P).id
#define EXP(P) (P).exp

void createMakanan(Makanan* makanan, int id, Word aksi, Word nama, TIME exp, TIME lamaPengiriman);

void printMakanan(Makanan makanan);

void increaseTime(Makanan* makanan, int lamaDetik);
#endif