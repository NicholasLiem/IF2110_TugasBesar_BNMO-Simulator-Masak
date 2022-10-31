#include "../headers/configParser.h"
Word contohPeta;

FILE *file, *temp;

List listTreeResep;

/* Bagian mekanisme ngeread file*/
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

/* ======================================= */


/* Bagian mekanisme parsing */
void parseMakanan(ListMakanan *listMakanan){
    Makanan makananTemp;
    int ID_MAKANAN;
    Word NAMA_MAKANAN;
    Word AKSI;
    TIME EXP;
    TIME LAMAPENGIRIMAN;

    STARTWORD();
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
        
        copyWord(&AKSI, currentWord);
        ADVWORDFILE();
        createMakanan(&makananTemp, ID_MAKANAN, AKSI, NAMA_MAKANAN, EXP, LAMAPENGIRIMAN);
        insertMakanan(listMakanan, makananTemp);
    }
}

void parsePeta(Matrix *peta){
    int jumlahBaris, jumlahKolom , i, j;
    
    STARTWORD();
    jumlahBaris = strToInt(currentWord);
    ADVWORDFILE();
    jumlahKolom = strToInt(currentWord);
    ADVWORDFILE();

    createMatrix(jumlahBaris, jumlahKolom, peta);
    
    for(i = 0; i < jumlahBaris; i++){
        for (j = 0; j < jumlahKolom; j++){
            (*peta).mem[i][j] = currentWord.TabWord[j];
        }
        ADVWORDFILE();
    }
}

void parseResep() {
    STARTWORD();
    int banyakRoot = strToInt(currentWord);
    printf("%d\n", banyakRoot);
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
        insertFirstLin(&listTreeResep, treeAddr);
    }
}


/* Bagian loading file + parsing*/
void loadConfigMakanan(ListMakanan *listMakanan){
    copyFile("./src/Konfigurasi/Makanan.txt");
    addMark("./src/Konfigurasi/Makanan.txt");
    parseMakanan(listMakanan);
    copyTempFile("./src/Konfigurasi/Makanan.txt");
}

void loadConfigPeta(Matrix *peta){
    copyFile("./src/Konfigurasi/Peta.txt");
    addMark("./src/Konfigurasi/Peta.txt");
    parsePeta(peta);
    copyTempFile("./src/Konfigurasi/Peta.txt");
}

void loadConfigResep(){
    copyFile("./src/Konfigurasi/Resep.txt");
    addMark("./src/Konfigurasi/Resep.txt");
    CreateListLin(&listTreeResep, 2);
    parseResep();
    copyTempFile("./src/Konfigurasi/Resep.txt");
}