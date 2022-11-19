#include "../src/adt/peta/peta.h"
#include "../src/adt/listlinier/listlinier.h"
// gcc -std=c17 -I. src/adt/charmachine/*.c src/adt/kulkas/*.c src/adt/listlinier/*.c src/adt/liststatik/*.c src/adt/makanan/*.c src/adt/matrix/*.c src/adt/peta/*.c src/adt/point/*.c src/adt/prioqueuedinamik/*.c src/adt/set/*.c src/adt/stack/*.c src/adt/time/*.c src/adt/tree/*.c src/adt/word/*.c src/adt/wordmachine/*.c src/helper/command/*.c src/helper/configparser/*.c src/helper/simulator/*.c -o bin/peta tests/peta.c
int main() {
    List listNotif;
    CreateListLin(&listNotif, 4);
    Peta p;
    CreatePeta(10, 10, &p);
    DisplayPeta(p);
    printf("\n");
    placeLegend(&p);
    DisplayPeta(p);
    printf("\n");
    MoveSimulator(&p, 'S', &listNotif);
    DisplayPeta(p);
    printf("\n");
    POINT po;
    CreatePoint(&po, -1, 0);
    printf("%d", isLocationOutOfBound(p, po));
}