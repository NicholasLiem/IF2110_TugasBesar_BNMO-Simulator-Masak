#include "ADT/headers/time.h"
#include "ADT/headers/point.h"
#include "ADT/headers/wordmachine.h"
#include "ADT/headers/word.h"
#include "Helper/headers/simulator.h"
#include "Helper/headers/command.h"

#include <stdlib.h>
#include <stdio.h>

//  gcc -std=c17 -I. src/ADT/implementation/*.c src/Helper/implementation/*.c -o bin/main src/main.c
// ./bin/main.exe
int main(){
    splashArt();
    promptName(&playerName);
    printMenu();
    CreateTime(&currentTime, 0,0,0);
    CreateListLin(&listNotif, 4);
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
