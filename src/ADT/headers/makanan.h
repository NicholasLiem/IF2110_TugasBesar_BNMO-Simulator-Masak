#ifndef MAKANAN_H
#define MAKANAN_H

#define MAX_CHAR 100

#include "boolean.h"
#include "time.h"
#include "point.h"
#include "word.h"

typedef struct { 
	int ID; 
	Word Nama;
	Word aksi;
	TIME Exp;
	TIME LamaPengiriman;
} MAKANAN;

/* *** Notasi Akses: Selektor POINT *** */
#define ID(P) (P).ID
#define EXP(P) (P).EXP
#define LOC(P) (P).Lokasi
#define DELIVERY(P) (P).LamaPengiriman

#endif