#include "../headers/kulkas.h"

/* Sistem pengisian mulai dari paling kiri atas ke kanan dan baru ke bawah */

void createKulkas(Kulkas* kulkas){
/* I.S kulkas bebas
   F.S kulkas baru terdefinisi dengan ukuran yang ditetapkan*/
    kulkas->matrixKulkas.mem[UKURAN_BARIS][UKURAN_KOLOM];
    kulkas->jumlahMakanan = 0;
    kulkas->matrixKulkas.colEff = UKURAN_KOLOM;
    kulkas->matrixKulkas.rowEff = UKURAN_BARIS;
}

ItemKulkas createItemKulkas(Kulkas kulkas, Makanan itemMakanan){
/* Membentuk ItemKulkas yang memiliki idKulkas */
    ItemKulkas newItemKulkas;
    ITEM_MAKANAN(newItemKulkas) = itemMakanan;
    ID_KULKAS(newItemKulkas) = JMLH_MAKANAN(kulkas) + 1;
    return newItemKulkas;
}

void insertMakananKulkas(Kulkas* kulkas, Makanan itemMakanan)
/* I.S Kulkas terdefinisi, makanan terdefinisi
   F.S Makanan masuk ke dalam kulkas dan terhapus dari inventory player*/
{
    int i, j;
    int lebar = itemMakanan.lebar;
    int panjang = itemMakanan.panjang;
    ItemKulkas newItemKulkas = createItemKulkas(*kulkas, itemMakanan);

    findFreeSpot(*kulkas, lebar, panjang, &i, &j);
    // printf("%d %d\n", i, j);
    if (i != -1 && j != -1){
        for (int k = i; k < i + lebar; k++){
            for (int l = j; l < j + panjang; l++){
                ELMT_KULKAS(*kulkas, k, l) = ID_KULKAS(newItemKulkas);
            }
        }
        JMLH_MAKANAN(*kulkas)++;
        Word namaMakanan = itemMakanan.nama;
        printWord(namaMakanan);
        printf(" (%d)", itemMakanan.id);
        printf(" berhasil masuk ke dalam kulkas!\n");
        printf("Registered ID makanan dalam Kulkas: %d\n", ID_KULKAS(newItemKulkas));
    } else {
        printf("Maaf, tidak cukup ruang untuk memasukkan makanan ini!\n");
    }
}

void findFreeSpot(Kulkas kulkas, int lebar, int panjang, int* hasilBaris, int* hasilKolom)
/* Mencari nilai index baris dan kolom yang dapat memuat makanan dengan size tertentu */
{
    int i, j;
    int k, l;
    *hasilBaris = -1;
    *hasilKolom = -1;
    boolean kosong = false;
    for (i = 0; i < BARIS_KULKAS(kulkas); i++){
        for (j = 0; j < KOLOM_KULKAS(kulkas); j++){
            // if (ELMT_KULKAS(kulkas, i, j) == 0){
            //     for (k = 0; k < panjang; k++){
            //         for (l = 0; l < lebar; l++){
            //             if (ELMT_KULKAS(kulkas, i + k, j + l) == 0){
            //                 kosong = true;
            //                 break;
            //             }
            //         }
            //     }
            // }
            // Algoritma Check Freespotnya belom jalan
        }
    }
}

boolean isIdMakananValid(Kulkas kulkas, int id){
    return(id >= 1 && id <= JMLH_MAKANAN(kulkas));
}
/* Mengecek apakah nilai id makanan di kulkas */

void ambilMakanan(Kulkas* kulkas, int idMakanan);
/* I.S Kulkas terdefinisi dan idMakanan terdefinisi
   F.S Menghapus makanan yang ada di kulkas dan memasukkannya ke dalam inventory player*/

void printKulkas(Kulkas kulkas)
/* Menampilkan isi kulkas yang berisi id item makanan kulkas */
{
    int i, j;
    for (i = 0; i < BARIS_KULKAS(kulkas); i++){
        for (j = 0; j < KOLOM_KULKAS(kulkas); j++){
            printf("%d ", ELMT_KULKAS(kulkas, i, j));
        }
        printf("\n");
    }
}

void searchMakananKulkas(Kulkas kulkas, int idMakananKulkas);
void listMakananKulkas(Kulkas kulkas);