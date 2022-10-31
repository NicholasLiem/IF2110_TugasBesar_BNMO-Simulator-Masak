#include "../src/Helper/headers/configParser.h"
#include "../src/ADT/headers/tree.h"

int main(){
    char dirPathPeta[100] = "./src/Konfigurasi/Peta.txt";
    char dirPathMakanan[100] = "./src/Konfigurasi/Makanan.txt";
    char dirPathResep[] = "./src/Konfigurasi/Resep.txt";
    // loadConfiguration(dirPathMakanan,0);
    // loadConfiguration(dirPathPeta, 1);
    // loadConfiguration(dirPathResep, 2);

    // for (int i = 0; i < lengthLin(listTreeResep); i++) {
    //     ListType tree = getElmtLin(listTreeResep, i);
    //     printf("Ini resep ke %i\n", i);
    //     PrintTree(tree.address);
    //     printf("-----");
    // }
    Peta peta;
    loadConfigPeta(&peta);
    printf("Ini petanya: \n");
    DisplayPeta(peta);
    // int i = 0;
    // for (int i = 0; i < 3; i++) {
    //     printf("%d ", tempPeta[i]);
    // }
    // printf("\n");
    // i = 0;
    // for (int i = 0; i < 3; i++) {
    //     printf("%d ", tempWaktu[i]);
    // }
}