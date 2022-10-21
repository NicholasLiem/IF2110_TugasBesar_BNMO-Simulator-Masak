#include <stdlib.h>
#include <stdio.h>

#include "ADT/MesinKata/wordmachine.c"

void loadMakanan(){
    FILE* ptr;
    ptr = freopen("Konfigurasi/Makanan.txt", "r", stdin);
    if (ptr == NULL){
        printf("Gagal loading file Makanan.txt\n");
    }
    STARTWORD();
    int i = 0;
    while (!endWord){
        for(int j = 0; j < currentWord.Length; j++){
            printf("%c\n", currentWord.TabWord[i]);
        }
        i++;
        ADVWORD();
    }

    //Proses baca makanan
    //Proses masukin makanan ke?
}

void loadPeta(){
    FILE* ptr;
    ptr = freopen("Konfigurasi/Peta.txt", "r", stdin);
    if (ptr == NULL){
        printf("Gagal loading file Peta.txt\n");
    }

    //Proses baca makanan
    //Proses masukin peta ke?
}

void loadResep(){
    FILE* ptr;
    ptr = freopen("Konfigurasi/Resep.txt", "r", stdin);
    if (ptr == NULL){
        printf("Gagal loading file Resep.txt\n");
    }

    //Proses baca resep
    //Proses masukin resep ke?
}

int main(){
    loadMakanan();
//     loadPeta();
//     loadResep();
}

