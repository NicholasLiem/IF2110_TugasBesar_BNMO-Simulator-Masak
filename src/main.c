#include "ADT/headers/time.h"
#include "ADT/headers/point.h"
#include "ADT/headers/wordmachine.h"
#include "ADT/headers/word.h"
#include "Helper/headers/simulator.h"

#include <stdlib.h>
#include <stdio.h>

//  gcc -std=c17 -I. src/ADT/implementation/*.c src/Helper/implementation/*.c -o bin/main src/main.c
// ./bin/main.exe
const Word COMMAND_START = {"START", 5};
const Word COMMAND_EXIT = {"EXIT", 4};
const Word COMMAND_MIX = {"MIX",3};
const Word COMMAND_FRY = {"FRY", 3};
const Word COMMAND_CHOP = {"CHOP", 4};
const Word COMMAND_BOIL = {"BOIL", 4};
const Word COMMAND_WAIT = {"WAIT", 4};
const Word COMMAND_UNDO = {"UNDO", 4};
const Word COMMAND_REDO = {"REDO", 4};
const Word COMMAND_CATALOG = {"CATALOG", 7};
const Word COMMAND_COOKBOOK = {"COOKBOOK", 8};
const Word COMMAND_MOVE = {"MOVE", 4};
const Word COMMAND_EAST = {"EAST", 4};
const Word COMMAND_NORTH = {"NORTH", 5};
const Word COMMAND_SOUTH = {"SOUTH", 5};
const Word COMMAND_WEST = {"WEST", 4};

Word playerName;
POINT currentLoc;
TIME currentTime;
boolean isStarted = false;

void splashArt();

void printMenu(){
    printf("Silahkan Pilih Command Berikut: \n");
    printf("START\n");
    printf("EXIT\n");
    // printf("HELP\n");
}

void notInput(){
    printf("Command tidak dikenali! Masukan input yang benar.\n");
    endWord = true;
}

void promptName(Word *word) {
    printf("Hello? Siapa disitu? (tanpa spasi):");
    STARTCOMMAND();
    copyWord(word, currentWord);
    RESETCOMMAND();
    printf("Hi "); printWord(*word);
    printf(" !\n");
}

void menuHasNotLogin() {
    if (isEqualWord(currentWord, COMMAND_START)){
        printf("Game started\n");
        printf("Loading...\n");
        loadConfig();
        printf("Load success!\n");
        isStarted = true;
    } else if (isEqualWord(currentWord, COMMAND_EXIT)){
        printf("Game exited\n");
        exit(0);
    } else notInput();
    return;
}

void menuHasLogin() {
    if (isEqualWord(currentWord, COMMAND_EXIT)){
        printf("Game exited\n");
        exit(0);
    } else if (isEqualWord(currentWord, COMMAND_MOVE)) {
        ADVCOMMAND();
        boolean isMoved = false;
        if (!endWord) {
            if (isEqualWord(currentWord, COMMAND_NORTH)) {
                isMoved = MoveSimulator(&peta, 'N');
            } else if (isEqualWord(currentWord, COMMAND_EAST)) {
                isMoved = MoveSimulator(&peta, 'E');
            } else if (isEqualWord(currentWord, COMMAND_SOUTH)) {
                isMoved = MoveSimulator(&peta, 'S');
            } else if (isEqualWord(currentWord, COMMAND_WEST)) {
                isMoved = MoveSimulator(&peta, 'W');
            } else {
                notInput();
                return;
            }
            if (isMoved) {
                currentTime = NextMenit(currentTime);
            }
            ADVCOMMAND();
        }
    } else if (isEqualWord(currentWord, COMMAND_WAIT)) {
        ADVCOMMAND();

        int jam, menit;
        boolean invalidTime = false;
        if (wordIsInt(currentWord) && !endWord) {
            jam = strToInt(currentWord);
        } else {
            invalidTime = true;
        }

        ADVCOMMAND();
        if (wordIsInt(currentWord) && !endWord) {
            menit = strToInt(currentWord);
        } else {
            invalidTime = true;
        }
        ADVCOMMAND();
        if (invalidTime || !endWord) {
            notInput();
        } else {
            currentTime = NextNMenit(currentTime, 60*jam + menit);
        }
        return;
    } else notInput();
}

void displayInfo() {
    if (isStarted) {
        printf("Player name: ");
        printWord(playerName);
        printf("\nTime: ");
        TulisTIME(currentTime);
        printf("\nMap:\n");
        DisplayPeta(peta);
        printf("\n");
    }
}
int main(){
    splashArt();
    promptName(&playerName);
    printMenu();
    CreateTime(&currentTime, 0,0,0);
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

void splashArt(){
    puts(
    "Selamat datang di program simulasi masak! \n"
    "                (^_^)                       \n"
    "                        ______               \n"     
    " _________       .---\"\"\"      \"\"\"---. \n"            
    ":______.-':      :  .--------------.  :     \n"        
    "| ______  |      | :                : |     \n"        
    "|:______B:|      | | Selamat Datang | |     \n"        
    "|:______B:|      | |       di       | |     \n"        
    "|:______B:|      | |program simulasi| |     \n"        
    "|         |      | |     masak!     | |     \n"        
    "|:_____:  |      | |                | |     \n"        
    "|    ==   |      | :                : |     \n"        
    "|       O |      :  '--------------'  :     \n"        
    "|       o |      :'---...______...---'      \n"        
    "|       o |-._.-i___/'             \\._      \n"        
    "|'-.____o_|   '-.   '-...______...-'  `-._  \n"        
    ":_________:      `.____________________   `-.___.-. \n"
    "                .'.eeeeeeeeeeeeeeeeee.'.      :___: \n"
    "               .'.eeeeeeeeeeeeeeeeeeeeee.'.         \n"
    "              :____________________________:             ");  
}

