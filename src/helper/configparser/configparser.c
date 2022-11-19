#include "configparser.h"

Word contohPeta;

FILE *file, *temp;

ListMakanan listMakanan;
List listTreeResep;
Peta peta;

char dirResep[] = "./src/konfigurasi/Resep.txt";
char dirMakanan[] = "./src/konfigurasi/Makanan.txt";
char dirPeta[] = "./src/konfigurasi/Peta.txt";

/* Bagian mekanisme ngeread file*/
void addMark(const char *filename){
    fclose(file);
    fclose(temp);
    file = fopen(filename, "a");
    fputs("\n.", file);
    file = freopen(filename, "r", file);
}

void copyFile(const char *filename){
    fclose(file);
    fclose(temp);
    file = fopen(filename, "r");
    temp = fopen("./src/konfigurasi/__temp__", "w");
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
    file = fopen("./src/konfigurasi/__temp__", "r");
    temp = fopen(filename, "w");
    char line[255];
    while(fgets(line, 255, file) != NULL){
        fputs(line, temp);
    }
    fclose(file);
    fclose(temp);
    remove("./src/konfigurasi/__temp__");
}

/* ======================================= */


/* Bagian mekanisme parsing */
void parseMakanan(ListMakanan *listMakanan){
    Makanan makananTemp;
    int ID_MAKANAN;
    Word NAMA_MAKANAN;
    Word AKSI;
    TIME EXP;
    TIME LAMAPENGIRIMAN;

    STARTWORDFILE(dirMakanan);
    int jumlahMakanan = strToInt(currentWord);
    int i;
    ADVWORDFILE();
    for(i = 0; i < jumlahMakanan; i++){
        ID_MAKANAN = strToInt(currentWord);
        ADVWORDFILE();
        
        copyWord(&NAMA_MAKANAN, currentWord);
        ADVWORDFILE();
        
        EXP = wordToTime(currentWord);
        ADVWORDFILE();
        LAMAPENGIRIMAN = wordToTime(currentWord);
        ADVWORDFILE();
        toUpper(&currentWord);
        copyWord(&AKSI, currentWord);
        ADVWORDFILE();
        createMakanan(&makananTemp, ID_MAKANAN, AKSI, NAMA_MAKANAN, EXP, LAMAPENGIRIMAN);
        insertMakanan(listMakanan, makananTemp);
    }
}

void parsePeta(Peta *peta){
    int jumlahBaris, jumlahKolom , i, j;
    
    STARTWORDFILE(dirPeta);
    jumlahBaris = strToInt(currentWord);
    ADVWORDFILE();
    jumlahKolom = strToInt(currentWord);
    ADVWORDFILE();

    CreatePeta(jumlahKolom, jumlahBaris, peta);
    
    for(i = 0; i < jumlahBaris; i++){
        for (j = 0; j < jumlahKolom; j++){
            (*peta).Map[i][j] = currentWord.TabWord[j];
        }
        ADVWORDFILE();
    }
}

void parseResep(List* listTreeResep) {
    STARTWORDFILE("./src/konfigurasi/Resep.txt");
    int banyakRoot = strToInt(currentWord);
    ADVWORD();
    for (int i = 0; i < banyakRoot; i++) {
        int nodeNum = strToInt(currentWord);
        ADVWORD();
        treeAddress treeResep;
        CreateTree(&treeResep);
        int parent = strToInt(currentWord);
        addRoot(&treeResep, parent);
        ADVWORD();
        boolean isFirst = true;
        for (int i = 0; i < nodeNum; i++) {
            if (!isFirst) {
                parent = strToInt(currentWord);
                ADVWORD();
            }
            int childNumber = strToInt(currentWord);
            ADVWORD();
            for (int i = 0; i < childNumber; i++) {
                int child = strToInt(currentWord);
                addChild(&treeResep, parent, child);
                ADVWORD();
            }
            isFirst = false;
        }
        ListType treeAddr;
        treeAddr.address = treeResep;
        insertFirstLin(listTreeResep, treeAddr);
    }
}


/* Bagian loading file + parsing*/
void loadConfigMakanan(ListMakanan *listMakanan){
    copyFile(dirMakanan);
    addMark(dirMakanan);
    parseMakanan(listMakanan);
    copyTempFile(dirMakanan);
}

void loadConfigPeta(Peta *peta){
    copyFile(dirPeta);
    addMark(dirPeta);
    parsePeta(peta);
    copyTempFile(dirPeta);
}

void loadConfigResep(List *listTreeResep){
    copyFile(dirResep);
    addMark(dirResep);
    CreateListLin(listTreeResep, 2);
    parseResep(listTreeResep);
    copyTempFile(dirResep);
}