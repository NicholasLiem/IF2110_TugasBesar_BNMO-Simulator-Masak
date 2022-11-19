#include "kulkas.h"

// const Makanan MAKANAN_NULL = {IDX_UNDEF_LIST_STATIK, {"NULL",4}, {"NULL",4}, {0,0,0}, {0,0,0}, 0, 0};
const ItemKulkas ITEMKULKAS_NULL = {{IDX_UNDEF_LIST_STATIK, {"NULL",4}, {"NULL",4}, {0,0,0}, {0,0,0}, 0, 0}, IDX_UNDEF_LIST_STATIK};

/* Inisialisasi size makanan dari input pengguna */

/* Sistem pengisian mulai dari paling kiri atas ke kanan dan baru ke bawah */
/* Sistem penomoran juga bermula dari 1, 2, 3, ..., n dengan n adalah jumlah makanan */
/* Jadi dapat dipastikan setiap makanan memiliki ID yang berbeda-beda */
/* Pemasukkan makanan memiliki batasan orientasi di mana jika sizenya adalah panjang x lebar,
    maka yang dimasukkan ke dalam kulkas juga demikian tidak bisa ditaruh dalam bentuk lebar x panjang */

void createKulkas(Kulkas* kulkas){
/* I.S kulkas bebas
   F.S kulkas baru terdefinisi dengan ukuran yang ditetapkan*/
    kulkas->matrixKulkas.mem[UKURAN_BARIS][UKURAN_KOLOM];
    kulkas->jumlahMakanan = 0;
    kulkas->matrixKulkas.colEff = UKURAN_KOLOM;
    kulkas->matrixKulkas.rowEff = UKURAN_BARIS;
}

ItemKulkas createItemKulkas(ListItemKulkas* listItemKulkas, Kulkas kulkas, Makanan itemMakanan){
/* Membentuk ItemKulkas yang memiliki idKulkas */
    ItemKulkas newItemKulkas;
    ITEM_MAKANAN(newItemKulkas) = itemMakanan;
    ID_KULKAS(newItemKulkas) = JMLH_MAKANAN(kulkas) + 1;
    listItemKulkas->contents[ID_KULKAS(newItemKulkas)] = newItemKulkas;
    return newItemKulkas;
}

void createListItemKulkas(ListItemKulkas* listItemKulkas){
/* I.S: listItemKulkas bebas
   F.S: listItemKulkas baru terdefinisi */
    int i;
    for(i = 0; i < CAPACITY; i++){
        listItemKulkas->contents[i] = ITEMKULKAS_NULL;
    }
}

boolean insertMakananKulkas(ListItemKulkas* listItemKulkas, Kulkas* kulkas, Makanan itemMakanan, int lebar, int panjang)
/* I.S Kulkas terdefinisi, makanan terdefinisi
   F.S Makanan masuk ke dalam kulkas dan terhapus dari inventory player*/
{
    int i, j;
    itemMakanan.lebar = lebar;
    itemMakanan.panjang = panjang;
    findFreeSpot(*kulkas, lebar, panjang, &i, &j);
    if (i != -1 && j != -1){
        ItemKulkas newItemKulkas = createItemKulkas(listItemKulkas, *kulkas, itemMakanan);
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
        return false;
    }
    return true;
}

void findFreeSpot(Kulkas kulkas, int lebar, int panjang, int* hasilBaris, int* hasilKolom)
/* Mencari nilai index baris dan kolom yang dapat memuat makanan dengan size tertentu */
{
    int i, j;
    int k, l;
    *hasilBaris = -1;
    *hasilKolom = -1;
    int luas = panjang*lebar;
    int count;
    boolean kosong = false;
    for (i = 0; i <= BARIS_KULKAS(kulkas)-lebar; i++){
        count = 0;
        for (j = 0; j <= KOLOM_KULKAS(kulkas)-panjang; j++){
            if (ELMT_KULKAS(kulkas, i, j) == 0){
                for (k = 0; k < lebar; k++){
                    for (l = 0; l < panjang; l++){
                        if (ELMT_KULKAS(kulkas, i + k, j + l) == 0){
                            count++;
                        }
                    }
                }
            if (count == luas){
                    *hasilKolom = j;
                    break;
                }
            }
        }
        if (count == luas){
            *hasilBaris = i;
            break;
        }
    }
}

void findFreeSpotUser(Kulkas kulkas, int lebar, int panjang, int* hasilBaris, int* hasilKolom, int barisUser, int kolomUser){
    // Mencari lokasi tersedia pada kulkas pada idx yang diminta user
    int i, j;
    *hasilBaris = -1;
    *hasilKolom = -1;
    int luas = panjang*lebar;
    int count;
    boolean kosong = false;
    for(i = 0; i < lebar; i++){
        for(j = 0; j < panjang; j++){
            if(ELMT_KULKAS(kulkas, barisUser + i, kolomUser + j) == 0){
                count++;
            }
        }
    }
    if(count == luas){
        *hasilBaris = barisUser;
        *hasilKolom = kolomUser;
    }
}

boolean isIdMakananValid(Kulkas kulkas, int id)
/* Mengecek apakah nilai id makanan di kulkas */
{
    return(id >= 1 && id <= JMLH_MAKANAN(kulkas));
}

Makanan ambilMakanan(ListItemKulkas *listItemKulkas, Kulkas* kulkas, int idMakananKulkas)
/* I.S Kulkas terdefinisi dan idMakanan terdefinisi
   F.S Menghapus makanan yang ada di kulkas dan memasukkannya ke dalam inventory player*/
{
    deleteItemKulkas(listItemKulkas, kulkas, idMakananKulkas-1);
    return listItemKulkas->contents[idMakananKulkas].itemMakanan;
}

void deleteItemKulkas(ListItemKulkas *listItemKulkas, Kulkas* kulkas, int idMakananKulkas){
    int i,j;
    for(i = 0; i < BARIS_KULKAS(*kulkas); i++){
        for(j = 0; j < KOLOM_KULKAS(*kulkas); j++){
            if(ELMT_KULKAS(*kulkas, i, j) == idMakananKulkas){
                ELMT_KULKAS(*kulkas, i, j) = 0;
            }
        }
    }
    listItemKulkas->contents[idMakananKulkas] = ITEMKULKAS_NULL;
}

void deleteAllKulkas(ListItemKulkas *listItemKulkas, Kulkas* kulkas){
    int i,j;
    for(i = 0; i < BARIS_KULKAS(*kulkas); i++){
        for(j = 0; j < KOLOM_KULKAS(*kulkas); j++){
            ELMT_KULKAS(*kulkas, i, j) = 0;
        }
    }
    for(i = 0; i < CAPACITY; i++){
        listItemKulkas->contents[i] = ITEMKULKAS_NULL;
    }
    JMLH_MAKANAN(*kulkas) = 0;
}

void copyKulkas(Kulkas kulkas, Kulkas* kulkasCopy, ListItemKulkas listItemKulkas, ListItemKulkas* listItemKulkasCopy){
    int i,j;
    for(i = 0; i < BARIS_KULKAS(kulkas); i++){
        for(j = 0; j < KOLOM_KULKAS(kulkas); j++){
            ELMT_KULKAS(*kulkasCopy, i, j) = ELMT_KULKAS(kulkas, i, j);
        }
    }
    for(i = 0; i < CAPACITY; i++){
        listItemKulkasCopy->contents[i] = listItemKulkas.contents[i];
    }
    JMLH_MAKANAN(*kulkasCopy) = JMLH_MAKANAN(kulkas);   
}

void printItemKulkas(ListItemKulkas listItemKulkas){
    int ID_KULKAS_MAKANAN;
    int ID_MAKANAN;
    Word NAMA_MAKANAN;
    int i;
    for(i = 0; i < CAPACITY; i++){
        ID_MAKANAN = listItemKulkas.contents[i].itemMakanan.id;
        ID_KULKAS_MAKANAN = listItemKulkas.contents[i].idKulkasMakanan;
        NAMA_MAKANAN = listItemKulkas.contents[i].itemMakanan.nama;
        if(ID_MAKANAN != IDX_UNDEF_LIST_STATIK){
            printf("(ID MAKANAN KULKAS: %d) => NAMA: ", ID_KULKAS_MAKANAN);
            printWord(NAMA_MAKANAN);
            printf(" => DURASI EXPIRED: ");
            TulisTIME(listItemKulkas.contents[i].itemMakanan.exp);
            printf("\n");
        }
    }
}

void printKulkas(Kulkas kulkas)
/* I.S: Kulkas terdefinisi
   F.S: Mengeluarkan tampilan kulkas dengan ID Kulkas sbg identifier makanan*/
{
    int i, j;
    for (i = 0; i < BARIS_KULKAS(kulkas); i++){
        for (j = 0; j < KOLOM_KULKAS(kulkas); j++){
            printf("%d ", ELMT_KULKAS(kulkas, i, j));
        }
        printf("\n");
    }
}

boolean isMakananInKulkas(Kulkas kulkas, int idMakananKulkas){
/* I.S Kulkas terdefinisi dan idMakananKulkas terdefinisi
   F.S Mengembalikan true jika makanan dengan idMakananKulkas ada di kulkas */
    int i, j;
    boolean found = false;
    for (i = 0; i < BARIS_KULKAS(kulkas); i++){
        for (j = 0; j < KOLOM_KULKAS(kulkas); j++){
            if (ELMT_KULKAS(kulkas, i, j) == idMakananKulkas){
                found = true;
                break;
            }
        }
        if (found){
            break;
        }
    }
    return found;
}