#include <stdio.h>

#include "../ADT/implementation/wordmachine.c"

Word namaMakanan;
Word aksi;
int temp2[1];
int tempWaktu[3];

int tempPeta[2];
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
    temp = fopen("../Konfigurasi/__temp__", "w");
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
    file = fopen("../Konfigurasi/__temp__", "r");
    temp = fopen(filename, "w");
    char line[255];
    while(fgets(line, 255, file) != NULL){
        fputs(line, temp);
    }
    fclose(file);
    fclose(temp);
    remove("../Konfigurasi/__temp__");
}

int strToInt(Word w){
    int j, intTemp = 0;
    intTemp = w.TabWord[0] - 48;
    for(j = 1; j < w.Length; j++){
        intTemp = intTemp*10 + (w.TabWord[j] - 48);
    }
    return intTemp;
}

void copyWord(Word nama, Word w){
    int j = 0;
    nama.Length = w.Length;
    for (j; j < w.Length; j++){
        nama.TabWord[j] = w.TabWord[j];
    }
    printWord(nama);
    printf("\n");
}

void parseStrToTime(Word w){
    int i = 0, j = 0;
    for(i; i < w.Length; i++){
        if (w.TabWord[i] != BLANK){
            tempWaktu[j] = w.TabWord[i] - 48;
            j++;
        }
    }
    printWord(w);
    printf("\n");
}

void parseStrToMapSize(Word w){
    int i = 0, j = 0;
    for(i; i < w.Length; i++){
        if (w.TabWord[i] != BLANK){
            tempPeta[j] = w.TabWord[i] - 48;
            j++;
        }
    }
    printWord(w);
    printf("\n");
}

void parseMakanan(){
    STARTWORD();
    int line = 1;
    //Skip bagian N pertama
    ADVWORD();

    while(!endWord){
        switch(line){
            case 1:
                temp2[0] = strToInt(currentWord);
                printf("%d\n", temp2[0]);
                ADVWORD();
                line++;
                break;
            case 2:
                copyWord(namaMakanan, currentWord);
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
                copyWord(aksi, currentWord);
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
        copyWord(contohPeta, currentWord);
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
        parseMakanan();
    }
    copyTempFile(filedir);
}

int main(){
    loadConfiguration("../Konfigurasi/Peta.txt", 1);
}