#include <stdio.h>

#include "headers/wordmachine.h"
#include "headers/time.h"

Word namaMakanan;
Word aksi;
int temp1[1];
int temp2[1];
int tempWaktu[2];

void printWord(Word w){
    int i = 0;
    for(i; i < w.Length; i++){
        printf("%c", w.TabWord[i]);
    }
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
    // printWord(nama);
}

void parseStrToTime(Word w){
    int i = 0, j = 0;
    for(i; i < w.Length; i++){
        if (w.TabWord[i] != BLANK){
            tempWaktu[j] = w.TabWord[i];
            j++;
        }
    }

    
}


void loadMakanan(){
    FILE* ptr;
    ptr = freopen("Konfigurasi/Makanan.txt", "r", stdin);
    if (ptr == NULL){
        printf("Gagal loading file Makanan.txt\n");
    }
    STARTWORD();
    int line = 0;
    while (!endWord){
        switch(line){
            case 1:
                temp1[0] = strToInt(currentWord);
                printf("%d\n", temp1[0]);
                line++;
                ADVWORD();
                break;
            case 2:
                temp2[0] = strToInt(currentWord);
                printf("%d\n", temp2[0]);
                line++;
                ADVWORD();
                break;
            case 3:
                copyWord(namaMakanan, currentWord);
                line++;
                ADVWORD();
                break;
            case 4:
                line++;
                ADVWORD();
                break;
            case 5:
                copyWord(aksi, currentWord);
                line++;
                ADVWORD();
                break;
            default:
                line++;
                break;
        }
        // Line 0 = Integer
        // Line 1 = Integer
        // Line 2 = char[]
        // Line 3 = Time
        // Line 4 = Time
        // Line 5 = char[]
        // for(int j = 0; j < currentWord.Length; j++){
        //     printf("%c", currentWord.TabWord[j]);
        // }
        // printf("\n");
        // ADVWORD();
    }
}

int main(){
    loadMakanan();
}

