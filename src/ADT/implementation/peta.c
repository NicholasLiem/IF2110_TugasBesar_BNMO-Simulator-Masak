#include <stdio.h>
#include "../headers/peta.h"

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
void CreatePeta(int length, int width, Peta *P){
    LEN_EFF(*P) = length;
    WIDTH_EFF(*P) = width;

    int x, y;
    for(y = 0; y<=width; y++){
        for(x = 0; x<=length; x++){
            ELMT(*P, x, y) = SPACE;
        }
    }
}

void LoadPeta(Peta *P, Word map){
    int current = 0;
    int i = 0;
    int j = 0;

    while(current < map.Length){
        if(map.TabWord[current] == '\n'){
            j = 0;
            i++;
        }else{ // current char != '\n'
            ELMT(*P, j, i) = map.TabWord[current];
        }
        current++;
        j++;
    }
}

/* *** Selektor Peta *** */
boolean isLocationOutOfBound(Peta P, POINT p){
    return Kuadran(p)!=1  || (int)Absis(p)>=LEN_EFF(P) || (int)Ordinat(p)>=WIDTH_EFF(P);
}

boolean isLocationColliding(Peta P, POINT p){
    return ELMT(P, (int)Absis(p), (int)Ordinat(p)) != SPACE;
}

boolean isLocationEff(Peta P, POINT p){
    return isLocationOutOfBound(P, p) || isLocationColliding(P, p);
}

/* *** Selektor: Untuk sebuah peta P yang terdefinisi: *** */
POINT locationOf(Peta *P, Legend t){
    int x, y;
    POINT p;

    for(y = 0; y<WIDTH_EFF(*P); y++){
        for(x = 0; x<LEN_EFF(*P); x++){
            if(ELMT(*P, x, y) == t){
                CreatePoint(&p, x, y);
                return p;
            }
        }
    }
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */                           
void MoveLegend(POINT LegPoint, Peta *P, char direction){
    int x, y, nx, ny;
    x = (int) Absis(LegPoint);
    y = (int) Ordinat(LegPoint);

    switch(direction){
        case 'N':
            Geser(&LegPoint, 0, 1);
            break;
        case 'S':
            Geser(&LegPoint, 0, -1);
            break;
        case 'W':
            Geser(&LegPoint, -1, 0);
            break;
        case 'E':
            Geser(&LegPoint, 1, 0);
            break;
    }

    if(isLocationOutOfBound(*P, LegPoint)){
        printf("Out of bound");
    }
    else if(isLocationColliding(*P, LegPoint)){
        printf("Collision");
    }
    else{
        nx = (int) Absis(LegPoint);
        ny = (int) Ordinat(LegPoint);

        ELMT(*P, nx, ny) = ELMT(*P, x, y);
        ELMT(*P, x, y) = SPACE;
    }
}

void MoveSimulator(Peta *P, char direction){
    POINT LegPoint = locationOf(P, SIMULATOR);
    MoveLegend(LegPoint, P, direction);
}

void DisplayPeta(Peta P){
    int x, y;
    int i;

    for(i = 0; i < LEN_EFF(P)+2; i++){ // Mencetak * di awal Peta
        printf("*");
    }
    printf("\n");
    for(y = 0; y < WIDTH_EFF(P); y++){
        printf("*");
        for(x = 0; x < LEN_EFF(P); x++){
            if(ELMT(P, x, y) == SPACE) printf(" ");
            else printf("%c", ELMT(P, x, y));
        }
        printf("*\n");
    }
    for(i = 0; i < LEN_EFF(P)+2; i++){ // Mencetak * di akhir Peta
        printf("*");
    }
}
