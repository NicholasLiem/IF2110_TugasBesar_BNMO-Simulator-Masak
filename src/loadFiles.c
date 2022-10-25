#include <stdio.h>

#include "ADT/MesinKata/wordmachine.c"

char temp[50];

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
                ADVWORD();
                break;
            case 2:
                ADVWORD();
                break;
            case 3:
                ADVWORD();
                break;
            case 4:
                ADVWORD();
                break;
            case 5:
                ADVWORD();
                break;
            default:
                endWord = true;
                break;
        }
        // Line 0 = Integer
        // Line 1 = Integer
        // Line 2 = char[]
        // Line 3 = Time
        // Line 4 = Time
        // Line 5 = Action
        for(int j = 0; j < currentWord.Length; j++){
            printf("%c", currentWord.TabWord[j]);
        }
        printf("\n");
        ADVWORD();
    }

    //Proses baca makanan
    //Proses masukin makanan ke?
}

// void loadPeta(){
//     FILE* ptr;
//     ptr = freopen("Konfigurasi/Peta.txt", "r", stdin);
//     if (ptr == NULL){
//         printf("Gagal loading file Peta.txt\n");
//     }

//     //Proses baca makanan
//     //Proses masukin peta ke?
// }

// void loadResep(){
//     FILE* ptr;
//     ptr = freopen("Konfigurasi/Resep.txt", "r", stdin);
//     if (ptr == NULL){
//         printf("Gagal loading file Resep.txt\n");
//     }

//     //Proses baca resep
//     //Proses masukin resep ke?
// }

int main(){
    loadMakanan();
//     loadPeta();
//     loadResep();
}

