#ifndef PETA_H
#define PETA_H

#include "point.h"
#include "boolean.h"
#include "wordmachine.h"

/*  Kamus Umum */
#define LENGTH_CAP 100
#define WIDTH_CAP 100
/* Ukuran maksimum panjang dan lebar */
#define SPACE '#'
/* Nilai elemen objek kosong */
#define SIMULATOR 'S'
#define TELEPHONE 'T'
#define MIXER 'M'
#define CHOPPER 'C'
#define FRYER 'F'
#define BOILER 'B'
#define WALL 'X'

/* Definisi elemen dan koleksi objek */
typedef char LegType;
typedef struct {
    LegType Type;
    POINT Lokasi;
} Legend;
typedef struct {
    int widthEff; // Lebar peta (Vertikal)
    int lengthEff; // Panjang peta (Horizontal)
    Legend* Map[WIDTH_CAP][LENGTH_CAP]; // Pointer to Legend
    Legend contents[WIDTH_CAP*LENGTH_CAP]; // Collection of Legends
} Peta;

/* *** Notasi Akses: Selektor Legend *** */
#define TYPE(L) (L).Type
#define LOC(L) (L).Lokasi
#define ABSIS(L) (L).Lokasi.X
#define ORDINAT(L) (L).Lokasi.Y

/* *** Notasi Akses: Selektor Peta *** */
#define LEN_EFF(P) (P).lengthEff
#define WIDTH_EFF(P) (P).widthEff
#define ELMT(P, x, y) (P).Map[y][x]
#define MAP_POINT(P, x, y) (P).Map[y][x]->Lokasi
#define MAP_TYPE(P, x, y) (P).Map[y][x]->Type
#define LEGENDS(P) (P).contents

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk Peta *** */
void CreatePeta(int length, int width, Peta *P);
/* Membentuk sistem Peta berdasarkan koordinat kartesius yang selalu di kuadran 1 */
/* I.S. Sembarang */
/* F.S. Peta P sesuai dengan definisi terbentuk atau
        mencetak prompt jika length dan width tidak valid */

void LoadPeta(Peta *P, Word map);
/* Memuat Peta berdasarkan Word map sesuai definisi sistem Peta */
/* I.S. P terdefinisi, map valid */
/* F.S. Elemen-elemen P terdefinisi sesuai Word map */

/* *** Selektor Peta *** */
boolean isLocationValid(int x, int y);
/* Mengirimkan true jika <x,y> adalah titik yang valid dalam sistem Peta */

/* *** Selektor: Untuk sebuah peta P yang terdefinisi: *** */
Legend getLegendOf(Peta *P, LegType t);
/* Mendapatkan Legend dari Legend Type t dalam sistem Peta */

POINT locationOf(Peta *P, LegType t);
/* Mendapatkan lokasi <x,y> dari Legend Type t dalam sistem Peta */

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */                           
void MoveLegend(Legend *L, Peta *P, int x, int y);
/* Menggeser Legend dalam sistem Peta sejauh <x,y> */
/* I.S. L dan P terdefinisi */
/* F.S. L dalam sistem Peta bergeser sejauh <x,y> atau
        mencetak prompt jika <x,y> menyebabkan Legend melebihi batas */

void MoveSimulator(Peta *P, char direction);
/* Menggeser Simulator sesuai arah mata angin sejauh satu satuan dalam sistem Peta */
/* I.S. Legend Simulator terdefinisi dalam P */
/* F.S. Simulator bergerak sesuai definisi atau
        mencetak prompt jika direction tidak valid */


#endif