// NIM: 13521135
// Nama: Nicholas Liem
// Tanggal: 13 Agustus 2022
// Topik praktikum: ADT Matriks
// Deskripsi: Implementasi ADT List Matriks

/* ********** Definisi TYPE Matrix dengan Index dan elemen integer ********** */

#include "boolean.h"
#include "matrix.h"
#include <math.h>
#include <stdio.h>

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void createMatrix(int nRows, int nCols, Matrix *m)
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */
{
    ROW_EFF(*m) = nRows;
    COL_EFF(*m) = nCols;
}

/* *** Selektor "Dunia Matrix" *** */
boolean isMatrixIdxValid(int i, int j)
/* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */
{
    return ((i >= 0 && j >= 0) && (i < ROW_CAP && j < COL_CAP));
}

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType getLastIdxRow(Matrix m)
/* Mengirimkan Index baris terbesar m */
{
    return (ROW_EFF(m) - 1);
}
IdxType getLastIdxCol(Matrix m)
/* Mengirimkan Index kolom terbesar m */
{
    return (COL_EFF(m) - 1);
}

boolean isIdxEff(Matrix m, IdxType i, IdxType j)
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
{
    return ((i >= 0 && i <= getLastIdxRow(m)) && (j >= 0 && j <= getLastIdxCol(m)));
}
ElType getElmtDiagonal(Matrix m, IdxType i)
/* Mengirimkan elemen m(i,i) */
{
    return ELMT(m, i, i);
}

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mOut)
/* Melakukan assignment mOut <- mIn */
{
    createMatrix(ROW_EFF(mIn), COL_EFF(mIn), mOut);
    *mOut = mIn;
}

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol)
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
{
    int i, j;
    createMatrix(nRow, nCol, m);
    for (i = 0; i <= getLastIdxRow(*m); i++)
    {
        for (j = 0; j <= getLastIdxCol(*m); j++)
        {
            scanf("%d", &ELMT(*m, i, j));
        }
    }
}

void displayMatrix(Matrix m)
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
    int i, j;
    for (i = 0; i <= getLastIdxRow(m); i++)
    {
        for (j = 0; j <= getLastIdxCol(m)-1; j++)
        {
            printf("%d ", ELMT(m, i, j));
            if (j == getLastIdxCol(m)-1)
            {
                printf("%d", ELMT(m, i, j+1));
            }
        }
        printf("\n");
    }
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2)
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil penjumlahan matriks: m1 + m2 */
{
    Matrix mOut;
    int i, j;
    createMatrix(ROW_EFF(m1), COL_EFF(m1), &mOut);
    for (i = 0; i <= getLastIdxRow(m1); i++)
    {
        for (j = 0; j <= getLastIdxCol(m1); j++)
        {
            ELMT(mOut, i, j) = ELMT(m1, i, j) + ELMT(m2, i, j);
        }
    }
    return mOut;
}

Matrix subtractMatrix(Matrix m1, Matrix m2)
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
{
    Matrix mOut;
    int i, j;
    createMatrix(ROW_EFF(m1), COL_EFF(m1), &mOut);
    for (i = 0; i <= getLastIdxRow(m1); i++)
    {
        for (j = 0; j <= getLastIdxCol(m1); j++)
        {
            ELMT(mOut, i, j) = ELMT(m1, i, j) - ELMT(m2, i, j);
        }
    }
    return mOut;
}

Matrix multiplyMatrix(Matrix m1, Matrix m2)
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan m1 * m2 */
{
    Matrix mOut;
    int i, j, k;
    createMatrix(ROW_EFF(m1), COL_EFF(m2), &mOut);
    for (i = 0; i <= getLastIdxRow(m1); i++)
    {
        for (j = 0; j <= getLastIdxCol(m2); j++)
        {
            ELMT(mOut, i, j) = 0;
            for (k = 0; k <= getLastIdxCol(m1); k++)
            {
                ELMT(mOut, i, j) += ELMT(m1, i, k) * ELMT(m2, k, j);
            }
        }
    }
    return mOut;
}

Matrix multiplyByConst(Matrix m, ElType x)
/* Mengirim hasil perkalian setiap elemen m dengan x */
{
    Matrix mOut;
    int i, j;
    createMatrix(ROW_EFF(m), COL_EFF(m), &mOut);
    for (i = 0; i <= getLastIdxRow(m); i++)
    {
        for (j = 0; j <= getLastIdxCol(m); j++)
        {
            ELMT(mOut, i, j) = ELMT(m, i, j) * x;
        }
    }
    return mOut;
}

void pMultiplyByConst(Matrix *m, ElType k)
/* I.S. m terdefinisi, k terdefinisi */
/* F.S. Mengalikan setiap elemen m dengan k */
{
    int i, j;
    for (i = 0; i <= getLastIdxRow(*m); i++)
    {
        for (j = 0; j <= getLastIdxCol(*m); j++)
        {
            ELMT(*m, i, j) *= k;
        }
    }
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isMatrixEqual(Matrix m1, Matrix m2)
/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
{
    int i, j;
    if (ROW_EFF(m1) != ROW_EFF(m2) || COL_EFF(m1) != COL_EFF(m2) || countElmt(m1) != countElmt(m2))
    {
        return false;
    }
    else
    {
        for (i = 0; i <= getLastIdxRow(m1); i++)
        {
            for (j = 0; j <= getLastIdxCol(m1); j++)
            {
                if (ELMT(m1, i, j) != ELMT(m2, i, j))
                {
                    return false;
                }
            }
        }
        return true;
    }
}

boolean isMatrixNotEqual(Matrix m1, Matrix m2)
/* Mengirimkan true jika m1 tidak sama dengan m2 */
{
    return (!isMatrixEqual(m1, m2));
}
boolean isMatrixSizeEqual(Matrix m1, Matrix m2)
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
/* yaitu RowEff(m1) = RowEff (m2) dan ColEff (m1) = ColEff (m2) */
{
    return (ROW_EFF(m1) == ROW_EFF(m2) && COL_EFF(m1) == COL_EFF(m2));
}

/* ********** Operasi lain ********** */
int countElmt(Matrix m)
/* Mengirimkan banyaknya elemen m */
{
    return (ROW_EFF(m) * COL_EFF(m));
}

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m)
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
{
    return (ROW_EFF(m) == COL_EFF(m));
}
boolean isSymmetric(Matrix m)
/* Mengirimkan true jika m adalah matriks simetri : isSquare(m) 
   dan untuk setiap elemen m, m(i,j)=m(j,i) */
{
    int i, j;
    if (!isSquare(m))
    {
        return false;
    }
    else
    {
        for (i = 0; i <= getLastIdxRow(m); i++)
        {
            for (j = 0; j <= getLastIdxCol(m); j++)
            {
                if (ELMT(m, i, j) != ELMT(m, j, i))
                {
                    return false;
                }
            }
        }
        return true;
    }
}

boolean isIdentity(Matrix m)
/* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan 
   setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
    {
        int i, j;
        if (!isSquare(m))
        {
            return false;
        }
        else
        {
            for (i = 0; i <= getLastIdxRow(m); i++)
            {
                for (j = 0; j <= getLastIdxCol(m); j++)
                {
                    if (i == j)
                    {
                        if (ELMT(m, i, j) != 1)
                        {
                            return false;
                        }
                    }
                    else
                    {
                        if (ELMT(m, i, j) != 0)
                        {
                            return false;
                        }
                    }
                }
            }
            return true;
        }
    }

boolean isSparse(Matrix m)
/* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
{
    int i, j, count = 0;
    for (i = 0; i <= getLastIdxRow(m); i++)
    {
        for (j = 0; j <= getLastIdxCol(m); j++)
        {
            if (ELMT(m, i, j) != 0)
            {
                count++;
            }
        }
    }
    return (count <= (0.05 * countElmt(m)));
}

Matrix negation(Matrix m)
/* Menghasilkan salinan m dengan setiap elemen dinegasikan (dikalikan -1) */
{
    return multiplyByConst(m, -1);
}

void pNegation(Matrix *m)
/* I.S. m terdefinisi */
/* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
{
    pMultiplyByConst(m, -1);
}

float determinant(Matrix m)
/* Prekondisi: isSquare(m) */
/* Menghitung nilai determinan m */
{
    int i, j, k;
    float det = 0;
    Matrix mtemp;
    if (ROW_EFF(m) == 1)
    {
        return ELMT(m, 0, 0);
    }
    else
    {
        for (i = 0; i <= getLastIdxRow(m); i++)
        {
            createMatrix(ROW_EFF(m) - 1, COL_EFF(m) - 1, &mtemp);
            for (j = 1; j <= getLastIdxRow(m); j++)
            {
                for (k = 0; k <= getLastIdxCol(m); k++)
                {
                    if (k < i)
                    {
                        ELMT(mtemp, j - 1, k) = ELMT(m, j, k);
                    }
                    else if (k > i)
                    {
                        ELMT(mtemp, j - 1, k - 1) = ELMT(m, j, k);
                    }
                }
            }
            det += pow(-1, i) * ELMT(m, 0, i) * determinant(mtemp);
        }
        return det;
    }
}

Matrix transpose(Matrix m)
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. menghasilkan salinan transpose dari m, yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
{
    Matrix mOut;
    createMatrix(ROW_EFF(m), COL_EFF(m), &mOut);
    
    Matrix mTemp;
    copyMatrix(m, &mTemp);
    int i, j;
    for (i = 0; i <= getLastIdxRow(m); i++)
        {
            for (j = 0; j <= getLastIdxCol(m); j++)
            {
                ELMT(mOut, i, j) = ELMT(mTemp, j, i);
            }
        }
    return mOut;
}

void pTranspose(Matrix *m)
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
{
    Matrix mTemp;
    copyMatrix(*m, &mTemp);
    int i, j;
    for (i = 0; i <= getLastIdxRow(*m); i++)
        {
            for (j = 0; j <= getLastIdxCol(*m); j++)
            {
                ELMT(*m, i, j) = ELMT(mTemp, j, i);
            }
        }
}

float rowMean(Matrix m, int i){
    int sum = 0;
    int jumlah = getLastIdxCol(m);
    int j;
    for(j = 0; j <= getLastIdxCol(m); j++){
        sum += ELMT(m, i, j);
    }
    return sum/jumlah;
}