#ifndef PETA_H
#define PETA_H

#include "point.h"
#include "boolean.h"

/*  Kamus Umum */
#define LENGTH_CAP 100
#define WIDTH_CAP 100
/* Ukuran maksimum panjang dan lebar */
#define SPACE '#'
/* Nilai elemen objek kosong */

/* Definisi elemen dan koleksi objek */
typedef char LegType;
typedef struct {
    LegType Type;
    POINT Lokasi;
} Legend;
typedef struct {
    int lengthEff;
    int widthEff;
    Legend contents[WIDTH_CAP][LENGTH_CAP];
} Peta;

/* *** Notasi Akses: Selektor Legend *** */
#define TYPE(L) (L).Type
#define LOC(L) (L).Lokasi
#define ABSIS(L) (L).Lokasi.X
#define ORDINAT(L) (L).Lokasi.Y

/* *** Notasi Akses: Selektor Peta *** */
#define LEN_EFF(P) (P).lengthEff
#define WIDTH_EFF(P) (P).widthEff
#define ELMT_

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
void CreatePeta(int length, int width, Peta *p);
/* Membentuk sistem peta berdasarkan koordinat kartesius yang selalu di kuadran 1 */
/* I.S. length dan width valid */
/* F.S. Peta p sesuai dengan definisi terbentuk */

#endif