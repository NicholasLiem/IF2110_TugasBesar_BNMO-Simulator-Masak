#include "ADT/headers/time.h"
#include "ADT/headers/point.h"
#include "ADT/headers/wordmachine.h"
#include "ADT/headers/word.h"

#include <stdlib.h>
#include <stdio.h>

//  gcc -std=c17 -I. src/ADT/implementation/*.c -o bin/main src/main.c
// ./bin/main.exe
const Word COMMAND_START = {"START", 5};
const Word COMMAND_EXIT = {"EXIT", 4};

void splashArt();

void printMenu(){
    printf("Pilihan Command: \n");
    printf("START\n");
    printf("EXIT\n");
}

void inputUser(Word *input){
    printMenu();
    printf("Massukan command: ");
    STARTCOMMAND();
    copyWord(input, currentWord);
    // ADVCOMMAND();
    // while (!endWord) {
    //     copyWord(input, currentWord);
    //     ADVCOMMAND();
    // }
    // delWord(&currentWord);
    // delChar(&currentChar);
}

void notInput(){
    printf("Command tidak ditemukan\n");
}

void initMenu(Word *input){
    toUpper(input);
    if(isEqualWord(*input, COMMAND_START)){
        printf("Game started\n");
    } else if (isEqualWord(*input, COMMAND_EXIT)){
        printf("Game exited\n");
        exit(0);
    } else notInput();
}   

int main(){
    Word command;
    char str[100];
    splashArt();
    while (true) {
        STARTCOMMAND();
        while(!endWord) {
            inputUser(&currentWord);
            initMenu(&currentWord);
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

void delWord(Word *word){
    for(int i = 0; i < word->Length; i++){
        word->TabWord[i] = 0;
    }
    word->Length = 0;
    endWord = false;
}

void delChar(char *c){
    *c = 0;
}

void strToWord(Word *word, char *str){
    int i = 0;
    while (str[i] != '\0') {
        word->TabWord[i] = str[i];
        i++;
    }
    word->Length = i;
}
