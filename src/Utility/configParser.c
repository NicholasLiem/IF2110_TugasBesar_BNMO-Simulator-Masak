#include <stdio.h>

#include "../ADT/headers/wordmachine.h"

//Abaikan dulu ini variabel penampung, nanti semuanya dimasukkin ke ADTnya masing-masing.
Word namaMakanan;
Word aksi;
int temp2[1];
int tempWaktu[5];

int tempPeta[5];
Word contohPeta;

FILE *file, *temp;

void addMark(const char *filename){
    fclose(file);
    fclose(temp);
    file = fopen(filename, "a");
    fputs("\n.", file);
    file = freopen(filename, "r", file);
    file = freopen(filename, "r", stdin);
    if (file == NULL){
        printf("Gagal loading file");
    }
}

void copyFile(const char *filename){
    fclose(file);
    fclose(temp);
    file = fopen(filename, "r");
    temp = fopen("./src/Konfigurasi/__temp__", "w");
    char line[255];
    while(fgets(line, 255, file) != NULL){
        fputs(line, temp);
    }
    fclose(file);
    fclose(temp);
}

void copyTempFile(const char *filename){
    fclose(file);
    fclose(temp);
    file = fopen("./src/Konfigurasi/__temp__", "r");
    temp = fopen(filename, "w");
    char line[255];
    while(fgets(line, 255, file) != NULL){
        fputs(line, temp);
    }
    fclose(file);
    fclose(temp);
    remove("./src/Konfigurasi/__temp__");
}

void parseStrToTime(Word w){
    int i = 0, j = 0;
    Word temp;
    setWord(&temp, "");
    for(i; i < w.Length; i++){
        if (w.TabWord[i] != BLANK){
            addChar(&temp, w.TabWord[i]);
        } 
        if (w.TabWord[i] == BLANK || i == (w.Length-1)) {
            tempWaktu[j] = strToInt(temp);
            setWord(&temp, "");
            j++;
        }
    }
    printWord(w);
    printf("\n");
}

void parseStrToMapSize(Word w){
    int i = 0, j = 0;
    Word temp;
    setWord(&temp, "");
    for(i; i < w.Length; i++){
        if (w.TabWord[i] != BLANK){
            addChar(&temp, (char) w.TabWord[i]);
        }
        if (w.TabWord[i] == BLANK || i == (w.Length-1)){
            tempPeta[j] = strToInt(temp);
            setWord(&temp, "");
            j++;
        }
    }
    printWord(w);
    printf("\n");
}

void parseMakanan(){
    STARTWORD();
    ADVWORD();
    int line = 1;
    while(!endWord){
        switch(line){
            case 1:
                temp2[0] = strToInt(currentWord);
                printf("%d\n", temp2[0]);
                ADVWORD();
                line++;
                break;
            case 2:
                copyWord(&namaMakanan, currentWord);
                ADVWORD();
                line++;
                break;
            case 3:
                parseStrToTime(currentWord);
                ADVWORD();
                line++;              
                break;
            case 4:
                parseStrToTime(currentWord);
                ADVWORD();
                line++;
                break;
            default:
                copyWord(&aksi, currentWord);
                ADVWORD();
                line = 1;
                break;
        }
    }
}

void parsePeta(){
    STARTWORD();
    parseStrToMapSize(currentWord);
    ADVWORD();
    while(!endWord){
        copyWord(&contohPeta, currentWord);
        ADVWORD();
    }
}

void loadConfiguration(const char *filedir, int configNum){
    // 0 : Makanan.txt
    // 1 : Peta.txt
    // 2 : Resep.txt

    copyFile(filedir);
    addMark(filedir);
    if (configNum == 0){
        parseMakanan();
    } else if (configNum == 1){
        parsePeta();
    } else {
        // parseMakanan();
    }
    copyTempFile(filedir);
}

int main(){
    char dirPathPeta[100] = "./src/Konfigurasi/Peta.txt";
    char dirPathMakanan[100] = "./src/Konfigurasi/Makanan.txt";
    loadConfiguration(dirPathMakanan,0);
    loadConfiguration(dirPathPeta, 1);
    int i = 0;
    for (int i = 0; i < 3; i++) {
        printf("%d ", tempPeta[i]);
    }
    printf("\n");
    i = 0;
    for (int i = 0; i < 3; i++) {
        printf("%d ", tempWaktu[i]);
    }
}