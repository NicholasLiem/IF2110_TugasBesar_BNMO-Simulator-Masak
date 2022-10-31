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


void splashArt();

void printMenu(){
    printf("Pilihan Command: \n");
    printf("START\n");
    printf("EXIT\n");
    printf("HELP\n");
}

void notInput(){
    printf("Command tidak ditemukan\n");
}

// void initMenu(Word *input){
//     toUpper(input);
//     if(isEqualWord(*input, COMMAND_START)){
//         printf("Game started\n");
//     } else if (isEqualWord(*input, COMMAND_EXIT)){
//         printf("Game exited\n");
//         exit(0);
//     } else notInput();
// }   

int main(){
    Word command;
    char str[100];
    splashArt();
    printMenu();
    while (true) {
        STARTCOMMAND();
        while(!endWord) {
            toUpper(&currentWord);
            if (isEqualWord(currentWord, COMMAND_START)){
                printf("Game started\n");
                printf("Loading...");
                loadConfig();
            } else if (isEqualWord(currentWord, COMMAND_EXIT)){
                printf("Game exited\n");
                exit(0);
            } else notInput();
            ADVCOMMAND();
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

