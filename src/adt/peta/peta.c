#include "peta.h"

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
void CreatePeta(int length, int width, Peta *P){
    LEN_EFF(*P) = length;
    WIDTH_EFF(*P) = width;

    int x, y;
    for(y = 0; y<=width; y++){
        for(x = 0; x<=length; x++){
            ELMT_PETA(*P, x, y) = SPACE;
        }
    }
}

void placeLegend (Peta *P) {
    ELMT_PETA(*P,0,0) = SIMULATOR;
}

// void LoadPeta(Peta *P, Word map){
//     int current = 0;
//     int i = 0;
//     int j = 0;

//     while(current < map.Length){
//         if(map.TabWord[current] == '\n'){
//             j = 0;
//             i++;
//         }else{ // current char != '\n'
//             ELMT_PETA(*P, j, i) = map.TabWord[current];
//         }
//         current++;
//         j++;
//     }
// }

/* *** Selektor Peta *** */
boolean isLocationOutOfBound(Peta P, POINT p){
    return Kuadran(p) != 1  || (int) Absis(p) >= LEN_EFF(P) || (int) Ordinat(p) >= WIDTH_EFF(P);
}

boolean isLocationColliding(Peta P, POINT p){
    return ELMT_PETA(P, (int)Absis(p), (int)Ordinat(p)) != SPACE;
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
            if(ELMT_PETA(*P, x, y) == t){
                CreatePoint(&p, x, y);
                return p;
            }
        }
    }
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */                           
boolean MoveLegend(POINT LegPoint, Peta *P, char direction, List* listNotif){
    int x, y, nx, ny;
    x = (int) Absis(LegPoint);
    y = (int) Ordinat(LegPoint);

    switch(direction){
        case 'N':
            Geser(&LegPoint, 0, -1);
            break;
        case 'S':
            Geser(&LegPoint, 0, 1);
            break;
        case 'W':
            Geser(&LegPoint, -1, 0);
            break;
        case 'E':
            Geser(&LegPoint, 1, 0);
            break;
    }

    if(isLocationOutOfBound(*P, LegPoint)){
        Word notif;
        setWord(&notif, "Out of bound");
        insertNotif(listNotif, notif);
        return false;
    }
    else if(isLocationColliding(*P, LegPoint)){
        Word notif;
        setWord(&notif, "Collision");
        insertNotif(listNotif, notif);
        return false;
    }
    else{
        nx = (int) Absis(LegPoint);
        ny = (int) Ordinat(LegPoint);

        ELMT_PETA(*P, nx, ny) = ELMT_PETA(*P, x, y);
        ELMT_PETA(*P, x, y) = SPACE;
        return true;
    }
}

void SetLegend(Peta *P, POINT last, POINT now, Legend t){
    int x, y;
    if(!isLocationEff(*P,now)){
        x = (int) Absis(now);
        y = (int) Ordinat(now);
        ELMT_PETA(*P, x, y) = t;
        x = (int) Absis(last);
        y = (int) Ordinat(last);
        ELMT_PETA(*P, x, y) = SPACE;
    }
    
}

boolean MoveSimulator(Peta *P, char direction, List* listNotif){
    POINT LegPoint = locationOf(P, SIMULATOR);
    return MoveLegend(LegPoint, P, direction, listNotif);
}

boolean isAdjacentTo(Peta *P, char symbol) {
    POINT LegPoint = locationOf(P, SIMULATOR);
    POINT left = PrevX(LegPoint);
    POINT right = NextX(LegPoint);
    POINT up = NextY(LegPoint);
    POINT down = PrevY(LegPoint);
    if (isLocationEff(*P, left) && ELMT_PETA(*P, (int) Absis(left), (int) Ordinat(left)) == symbol) {
        return true;    
    }
    if (isLocationEff(*P, right) && ELMT_PETA(*P, (int) Absis(right), (int) Ordinat(right)) == symbol) {
        return true;    
    }
    if (isLocationEff(*P, up) && ELMT_PETA(*P, (int) Absis(up), (int) Ordinat(up)) == symbol) {
        return true;    
    }
    if (isLocationEff(*P, down) && ELMT_PETA(*P, (int) Absis(down), (int) Ordinat(down)) == symbol) {
        return true;    
    }
    return false;
}

void DisplayPeta(Peta P){
    int x, y;
    int i;

    for(i = 0; i < LEN_EFF(P)+2; i++){ // Mencetak * di awal Peta
        printf("* ");
    }
    printf("\n");
    for(y = 0; y < WIDTH_EFF(P); y++){
        printf("* ");
        for(x = 0; x < LEN_EFF(P); x++){
            if(ELMT_PETA(P, x, y) == SPACE) printf("  ");
            else printf("%c ", ELMT_PETA(P, x, y));
        }
        printf("*\n");
    }
    for(i = 0; i < LEN_EFF(P)+2; i++){ // Mencetak * di akhir Peta
        printf("* ");
    }
}

