#include "adt/time/time.h"
#include "adt/point/point.h"
#include "adt/wordmachine/wordmachine.h"
#include "adt/word/word.h"
#include "helper/simulator/simulator.h"
#include "helper/command/command.h"

#include <stdlib.h>
#include <stdio.h>

//  gcc -std=c17 -I. src/adt/charmachine/*.c src/adt/kulkas/*.c src/adt/listlinier/*.c src/adt/liststatik/*.c src/adt/makanan/*.c src/adt/matrix/*.c src/adt/peta/*.c src/adt/point/*.c src/adt/prioqueuedinamik/*.c src/adt/set/*.c src/adt/stack/*.c src/adt/time/*.c src/adt/tree/*.c src/adt/word/*.c src/adt/wordmachine/*.c src/helper/command/*.c src/helper/configparser/*.c src/helper/simulator/*.c -o bin/main src/main.c
// ./bin/main.exe

int main(){
    splashArt();
    promptName(&playerName);
    printMenu();
    CreateTime(&currentTime, 0,0,0);
    CreateListLin(&listNotif, 4);
    CreateListLin(&oldNotif, 4);
    CreateListLin(&listNotifUndo, 4);
    CreateQueue(&listInventory);
    CreateQueue(&listDelivery);
    while (true) {
        displayInfo();
        printf("Command Prompt: ");
        STARTCOMMAND();
        while(!endWord) {
            toUpper(&currentWord);
            if (!isStarted) {
                menuHasNotLogin();
            } else {
                menuHasLogin();
            }
        }
        RESETCOMMAND();
    }
    return 0;
}
