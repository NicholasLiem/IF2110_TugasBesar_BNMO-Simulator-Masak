#include "../headers/simulator.h"

Word playerName;
POINT currentLoc;
TIME currentTime;
boolean isStarted = false;
List listNotif;

void simLoadConfig() {
    CreateListMakanan(&listMakanan);
    loadConfigMakanan(&listMakanan);
    // displayListMakanan(listMakanan);

    // printf("=======================\n");
    loadConfigPeta(&peta);
    placeLegend(&peta);
    // printf("Ini petanya: \n");
    // DisplayPeta(peta);
    // printf("\n=======================\n");

    loadConfigResep(&listTreeResep);
    // for (int i = 0; i < lengthLin(listTreeResep); i++) {
    //     ListType tree = getElmtLin(listTreeResep, i);
    //     printf("Ini resep ke %i\n", i);
    //     PrintTree(tree.address);
    //     printf("-----\n");
    // }

};

boolean simMove(char c) {
    return MoveSimulator(&peta, c);
}

void simAdvTime(long time) {
    currentTime = NextNMenit(currentTime, time);
}

