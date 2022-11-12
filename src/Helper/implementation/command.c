#include "../headers/command.h"

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
                 pushUndo(oldNotif);
                isMoved = simMove('N');
            } else if (isEqualWord(currentWord, COMMAND_EAST)) {
                pushUndo(oldNotif);
                isMoved = simMove('E');
            } else if (isEqualWord(currentWord, COMMAND_SOUTH)) {
                pushUndo(oldNotif);
                isMoved = simMove('S');
            } else if (isEqualWord(currentWord, COMMAND_WEST)) {
                pushUndo(oldNotif);
                isMoved = simMove('W');
            } else {
                notInput();
            }
            printf("done");
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
            pushUndo(oldNotif);
            simAdvTime(60*jam + menit);
        }
    } else if (isEqualWord(currentWord, COMMAND_BOIL) || isEqualWord(currentWord, COMMAND_CHOP) || isEqualWord(currentWord, COMMAND_FRY) || isEqualWord(currentWord, COMMAND_MIX) || isEqualWord(currentWord, COMMAND_BUY)) {
        ADVCOMMAND();
        int choice = 0;
        if (isEqualWord(currentWord, COMMAND_BOIL) && isAdjacentTo(&peta, 'B')) {
            displayMenu(COMMAND_BOIL);
            choice = getCookChoice();
            if (choice != 0) pushUndo(oldNotif);
            addDelivery(COMMAND_BOIL, choice, &listNotif);
        } else if (isEqualWord(currentWord, COMMAND_CHOP) && isAdjacentTo(&peta, 'C')) {
            displayMenu(COMMAND_CHOP);
            choice = getCookChoice();
             if (choice != 0) pushUndo(oldNotif);
            addDelivery(COMMAND_CHOP, choice, &listNotif);
        } else if (isEqualWord(currentWord, COMMAND_MIX) && isAdjacentTo(&peta, 'M')) {
            displayMenu(COMMAND_MIX);
            choice = getCookChoice();
            if (choice != 0) pushUndo(oldNotif);
            addDelivery(COMMAND_MIX, choice, &listNotif);
        } else if (isEqualWord(currentWord, COMMAND_BUY) && isAdjacentTo(&peta, 'T')) {
            displayMenu(COMMAND_BUY);
            choice = getCookChoice();
             if (choice != 0) pushUndo(oldNotif);
            addDelivery(COMMAND_BUY, choice, &listNotif);
        } else if (isEqualWord(currentWord, COMMAND_FRY) && isAdjacentTo(&peta, 'F')) {
            displayMenu(COMMAND_FRY);
            choice = getCookChoice();
            if (choice != 0) pushUndo(oldNotif);
            addDelivery(COMMAND_FRY, choice, &listNotif);
        } else {
            printf("Maaf, anda tidak berada di station yang tepat untuk melakukan perintah.");
        }
        if (choice == 0) {
            printf("Tolong jangan ngerjain saya ya.. Banyak tubes tau cape..\n");
        }
    } else if (isEqualWord(currentWord, COMMAND_COOKBOOK)) {
        printListResep(listTreeResep, listMakanan);
        ADVCOMMAND();
    } else if (isEqualWord(currentWord, COMMAND_CATALOG)) {
        commandCatalog(listMakanan);
        ADVCOMMAND();
    } else if (isEqualWord(currentWord, COMMAND_DELIVERY)) {
        displayDelivery();
        ADVCOMMAND();
    } else if (isEqualWord(currentWord, COMMAND_INVENTORY)) {
        displayInventory();
        ADVCOMMAND();
    } else if (isEqualWord(currentWord, COMMAND_UNDO)){
        simUndo(oldNotif);
        ADVCOMMAND();
    } else if (isEqualWord(currentWord, COMMAND_REDO)){
        simRedo();
        ADVCOMMAND();
    } else if (isEqualWord(currentWord, COMMAND_HELP)){
        printHelp();
        ADVCOMMAND();
    } 
    else notInput();
    processDeliveryAndExpired();
    deleteAllLin(&oldNotif);
    copyListLin(listNotif, &oldNotif);
    // printf("\n");
    // printf("u========UNDO : LAST STATE========u\n");
    // PrintStack(undo);
    // printf("n========UNDO : LAST STATE========n\n");
}

int getCookChoice() {
    printf("Jadi, mau pilih apa? :");
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
        printf("\nPlayer name: ");
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

