#include <stdio.h>
#include ".\ADT\headers\peta.h"

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
void CreatePeta(int length, int width, Peta *P){
    LEN_EFF(*P) = length;
    WIDTH_EFF(*P) = width;

    int x, y;
    for(y = 0; y<=width; y++){
        for(x = 0; x<=length; x++){
            ELMT(*P, x, y) = NULL;
        }
    }
}

void LoadPeta(Peta *P, Word map){
    
}

/* *** Selektor Peta *** */
boolean isLocationValid(int x, int y);

/* *** Selektor: Untuk sebuah peta P yang terdefinisi: *** */
Legend getLegendOf(Peta *P, LegType t);

POINT locationOf(Peta *P, LegType t);

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */                           
void MoveLegend(Legend *L, Peta *P, int x, int y);

void MoveSimulator(Peta *P, char direction);
