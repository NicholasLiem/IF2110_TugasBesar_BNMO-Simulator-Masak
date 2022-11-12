#ifndef PETA_H
#define PETA_H

#include "point.h"
#include "boolean.h"
#include "wordmachine.h"
#include "listlinier.h"

/*  Kamus Umum */
#define LENGTH_CAP 100
#define WIDTH_CAP 100
/* Ukuran maksimum panjang dan lebar */
#define SPACE '#'
/* Nilai elemen objek kosong */
#define SIMULATOR 'S'
// #define TELEPHONE 'T'
// #define MIXER 'M'
// #define CHOPPER 'C'
// #define FRYER 'F'
// #define BOILER 'B'
// #define WALL 'X'

/* Definisi elemen dan koleksi objek */
typedef char Legend;
typedef struct {
    int widthEff; // Lebar peta (Vertikal)
    int lengthEff; // Panjang peta (Horizontal)
    Legend Map[WIDTH_CAP][LENGTH_CAP]; // Pointer to Legend
} Peta;

/* *** Notasi Akses: Selektor Peta *** */
#define LEN_EFF(P) (P).lengthEff
#define WIDTH_EFF(P) (P).widthEff
#define ELMT_PETA(P, x, y) (P).Map[y][x]

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk Peta *** */
void CreatePeta(int length, int width, Peta *P);
/* Membentuk sistem Peta berdasarkan koordinat kartesius yang selalu di kuadran 1 */
/* I.S. Sembarang */
/* F.S. Peta P sesuai dengan definisi terbentuk atau
        mencetak prompt jika length dan width tidak valid */

// void LoadPeta(Peta *P, Word map);
/* Memuat Peta berdasarkan Word map sesuai definisi sistem Peta */
/* I.S. P terdefinisi, map valid */
/* F.S. Elemen-elemen P terdefinisi sesuai Word map */

/* *** Selektor Peta *** */
boolean isLocationOutOfBound(Peta P, POINT p);
/* Mengirimkan true jika <x,y> adalah titik di dalam sistem Peta */

boolean isLocationColliding(Peta P, POINT p);
/* Mengirimkan true jika <x,y> tidak mengalami tubrukan dengan titik lain */

boolean isLocationEff(Peta P, POINT p);
/* Mengirimkan true jika <x,y> adalah titik yang efektif dalam sistem Peta */

/* *** Selektor: Untuk sebuah peta P yang terdefinisi: *** */
POINT locationOf(Peta *P, Legend t);
/* Mendapatkan lokasi <x,y> dari Legend Type t dalam sistem Peta */

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */                           
boolean MoveLegend(POINT LegPoint, Peta *P, char direction, List* listNotif);
/* Menggeser Legend dalam sistem Peta sejauh satu satuan ke arah direction */
/* direction: NORTH, EAST, WEST, SOUTH */
/* I.S. L dan P terdefinisi */
/* F.S. L dalam sistem Peta bergeser sejauh satu ke direction atau
        mencetak prompt jika direction menyebabkan Legend melebihi batas atau menabrak dinding */

void SetLegend(Peta *P, POINT last, POINT now, Legend t);

boolean isAdjacentTo(Peta *P, char symbol);

boolean MoveSimulator(Peta *P, char direction, List* listNotif);
/* Menggeser Simulator sesuai arah mata angin sejauh satu satuan dalam sistem Peta */
/* I.S. Legend Simulator terdefinisi dalam P */
/* F.S. Simulator bergerak sesuai definisi atau
        mencetak prompt jika direction menyebabkan Legend melebihi batas atau menabrak dinding */


/* ********** KELOMPOK BACA/TULIS ********** */
void DisplayPeta(Peta P);
/* I.S. P terdefinisi */
/* F.S. Nilai P.Map[i][j] ditampilkan ke layar per baris per kolom
        Peta dikelilingi oleh simbol '*' sebagai pembatas*/

void placeLegend (Peta *P);
#endif