#ifndef MAKANAN_H
#define MAKANAN_H

#define MAX_CHAR 100

#include "../boolean.h"
#include "../Time/time.h"
#include "../Point/point.h"

typedef struct { 
	int ID; 
	char Nama[MAX_CHAR];
	TIME Exp;
	POINT Lokasi;
	int LamaPengiriman;
} MAKANAN;

/* *** Notasi Akses: Selektor POINT *** */
#define ID(P) (P).ID
#define EXP(P) (P).EXP
#define LOC(P) (P).Lokasi
#define DELIVERY(P) (P).LamaPengiriman