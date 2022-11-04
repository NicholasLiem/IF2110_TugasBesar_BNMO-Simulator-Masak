#include "../headers/command.h"

Word COMMAND_START = {"START", 5}; //
Word COMMAND_EXIT = {"EXIT", 4}; //
Word COMMAND_MIX = {"MIX",3};
Word COMMAND_FRY = {"FRY", 3};
Word COMMAND_CHOP = {"CHOP", 4}; //
Word COMMAND_BOIL = {"BOIL", 4}; //
Word COMMAND_BUY = {"BUY", 3}; //
Word COMMAND_WAIT = {"WAIT", 4}; //
Word COMMAND_UNDO = {"UNDO", 4}; //
Word COMMAND_REDO = {"REDO", 4}; //
Word COMMAND_CATALOG = {"CATALOG", 7}; //
Word COMMAND_COOKBOOK = {"COOKBOOK", 8}; //
Word COMMAND_MOVE = {"MOVE", 4}; //
Word COMMAND_EAST = {"EAST", 4}; //
Word COMMAND_NORTH = {"NORTH", 5}; //
Word COMMAND_SOUTH = {"SOUTH", 5}; //
Word COMMAND_WEST = {"WEST", 4}; //
Word COMMAND_HELP = {"HELP", 4};


void printMenu(){
    printf("Silahkan Pilih Command Berikut: \n");
    printf("START\n");
    printf("EXIT\n");
    // printf("CATALOG\n");
    // printf("MOVE\n");
    // printf("HELP\n");
}

void printHelp(){
    printf("\n");
    printf("------------------------------------------------------------\n");
    printf("Daftar Command Tersedia\n");
    printf("------------------------------------------------------------\n");
    printf("Command Program\n");
    printf("------------------------------------------------------------\n");
    printf("1. CATALOG - Melihat daftar makanan tersedia\n");
    printf("2. COOKBOOK - Melihat daftar resep tersedia\n");
    printf("3. WAIT (X) (Y) - Menunggu selama X jam dan Y menit\n");
    printf("4. MOVE NORTH/EAST/SOUTH/WEST - Bergerak satu langkah ke arah yang dituju\n");
    printf("5. UNDO - Mengulang ke keadaan sebelumnya\n");
    printf("6. REDO - Mengulangi apa yang sudah di UNDO\n");
    printf("------------------------------------------------------------\n");
    printf("Command Aksi\n");
    printf("------------------------------------------------------------\n");
    printf("1. BUY - Melakukan aksi pembelian makanan\n");
    printf("2. BOIL - Melakukan aksi perebusan makanan\n");
    printf("3. CHOP - Melakukan aksi pemotongan makanan\n");
    printf("4. MIX - Melakukan aksi pencampuran makanan\n");
    printf("5. FRY - Melakukan aksi penggorengan makanan\n");
    printf("------------------------------------------------------------\n");
    printf("Command Lain\n");
    printf("------------------------------------------------------------\n");
    printf("1. HELP - Menampilkan daftar command tersedia\n");
    printf("2. EXIT - Keluar dari program\n");
    printf("------------------------------------------------------------\n");
    printf("\n");
}

void notInput(){
    printf("Command tidak dikenali! Masukan input yang benar.\n");
    endWord = true;
}

void promptName(Word *word) {
    printf("Hello? Siapa disitu? (tanpa spasi): ");
    STARTCOMMAND();
    copyWord(word, currentWord);
    RESETCOMMAND();
    printf("Hi "); printWord(*word);
    printf("!\n");
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
    } else if (isEqualWord(currentWord, COMMAND_BOIL) || isEqualWord(currentWord, COMMAND_CHOP) || isEqualWord(currentWord, COMMAND_FRY) || isEqualWord(currentWord, COMMAND_MIX) || isEqualWord(currentWord, COMMAND_BUY)) {
        ADVCOMMAND();
        if (isEqualWord(currentWord, COMMAND_BOIL) && isAdjacentTo(&peta, 'B')) {
            displayMenu(COMMAND_BOIL);
            getCookChoice();
        } else if (isEqualWord(currentWord, COMMAND_CHOP) && isAdjacentTo(&peta, 'C')) {
            displayMenu(COMMAND_CHOP);
            getCookChoice();
        } else if (isEqualWord(currentWord, COMMAND_MIX) && isAdjacentTo(&peta, 'M')) {
            displayMenu(COMMAND_MIX);
            getCookChoice();
        } else if (isEqualWord(currentWord, COMMAND_BUY) && isAdjacentTo(&peta, 'T')) {
            displayMenu(COMMAND_BUY);
            getCookChoice();
        } else if (isEqualWord(currentWord, COMMAND_FRY) && isAdjacentTo(&peta, 'F')) {
            displayMenu(COMMAND_FRY);
            getCookChoice();
        } else {
            printf("Maaf, anda tidak berada di station yang tepat untuk melakukan perintah.");
        }
    } else if (isEqualWord(currentWord, COMMAND_COOKBOOK)) {
        printListResep(listTreeResep, listMakanan);
        ADVCOMMAND();
    } else if (isEqualWord(currentWord, COMMAND_CATALOG)) {
        commandCatalog(listMakanan);
        ADVCOMMAND();
    } else if (isEqualWord(currentWord, COMMAND_HELP)){
        printHelp();
        ADVCOMMAND();
    } 
    else notInput();
}

int getCookChoice() {
    printf("Jadi, mau pilih apa? ");
    RESETCOMMAND();
    STARTCOMMAND();
    int choice = 0;
    if (wordIsInt(currentWord)) {
        choice = strToInt(currentWord);
    }
    ADVCOMMAND();
    if (!endWord) {
        notInput();
    }
    return choice;
}
void displayInfo() {
    if (isStarted) {
        printf("Player Name: ");
        printWord(playerName);
        printf("\nTime: ");
        TulisTIME(currentTime);
        printNotif(listNotif);
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

