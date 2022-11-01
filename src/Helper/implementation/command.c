#include "../headers/command.h"

Word COMMAND_START = {"START", 5};
Word COMMAND_EXIT = {"EXIT", 4};
Word COMMAND_MIX = {"MIX",3};
Word COMMAND_FRY = {"FRY", 3};
Word COMMAND_CHOP = {"CHOP", 4};
Word COMMAND_BOIL = {"BOIL", 4};
Word COMMAND_WAIT = {"WAIT", 4};
Word COMMAND_UNDO = {"UNDO", 4};
Word COMMAND_REDO = {"REDO", 4};
Word COMMAND_CATALOG = {"CATALOG", 7};
Word COMMAND_COOKBOOK = {"COOKBOOK", 8};
Word COMMAND_MOVE = {"MOVE", 4};
Word COMMAND_EAST = {"EAST", 4};
Word COMMAND_NORTH = {"NORTH", 5};
Word COMMAND_SOUTH = {"SOUTH", 5};
Word COMMAND_WEST = {"WEST", 4};

void printMenu(){
    printf("Silahkan Pilih Command Berikut: \n");
    printf("START\n");
    printf("EXIT\n");
    printf("CATALOG\n");
    printf("MOVE\n");
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
        simLoadConfig();
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
                isMoved = simMove('N');
            } else if (isEqualWord(currentWord, COMMAND_EAST)) {
                isMoved = simMove('E');
            } else if (isEqualWord(currentWord, COMMAND_SOUTH)) {
                isMoved = simMove('S');
            } else if (isEqualWord(currentWord, COMMAND_WEST)) {
                isMoved = simMove('W');
            } else {
                notInput();
                return;
            }
            if (isMoved) {
                simAdvTime(1);
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
            simAdvTime(60*jam + menit);
        }
        return;
    } else if (isEqualWord(currentWord, COMMAND_CATALOG)) {
        commandCatalog(listMakanan);
        ADVCOMMAND();
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

