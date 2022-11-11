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
}

void insertMakanan(Kulkas* kulkas, Makanan itemMakanan)
/* I.S Kulkas terdefinisi, makanan terdefinisi
   F.S Makanan masuk ke dalam kulkas dan terhapus dari inventory player*/
{
    int i, j;
    int lebar = itemMakanan.lebar;
    int panjang = itemMakanan.panjang;
    ItemKulkas newItemKulkas = createItemKulkas(*kulkas, itemMakanan);
    if (canInsert(*kulkas, lebar, panjang)){
        for (i = 0; i < lebar; i++){
            for (j = 0; j < panjang; j++){
                ELMT_KULKAS(*kulkas, i, j) = ID_KULKAS(newItemKulkas);
            }
        }
        JMLH_MAKANAN(*kulkas)++;
    }
}

boolean canInsert(Kulkas kulkas, int lebar, int panjang)
/* Mengecek apakah suatu makanan dengan size tertentu bisa dimasukkan ke kulkas 
   akan dikembalikan nilai false jika tidak bisa */
{
    int petak;
    for(petak = 0; petak < BARIS_KULKAS(kulkas) * KOLOM_KULKAS(kulkas); petak++){
        if(ELMT_KULKAS(kulkas, petak / KOLOM_KULKAS(kulkas), petak % KOLOM_KULKAS(kulkas)) == ID_KOSONG){
            if(petak + lebar * panjang <= BARIS_KULKAS(kulkas) * KOLOM_KULKAS(kulkas)){
                int i;
                for(i = 0; i < lebar * panjang; i++){
                    if(ELMT_KULKAS(kulkas, (petak + i) / KOLOM_KULKAS(kulkas), (petak + i) % KOLOM_KULKAS(kulkas)) != ID_KOSONG){
                        return false;
                    }
                }
                return true;
            }
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
