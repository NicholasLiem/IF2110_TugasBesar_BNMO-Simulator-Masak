#include "../headers/point.h"
#include <stdio.h>
#include <math.h>
        
/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
void CreatePoint (POINT * P, float X, float Y)
/* Membentuk sebuah POINT dari komponen-komponennya */
{
    Absis(*P) = X;
    Ordinat(*P) = Y;
}
/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                                 
void BacaPOINT (POINT * P)
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk 
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2 
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
{
    float X;
    float Y;
    scanf("%f %f", &X, &Y);
    CreatePoint(P, X, Y);
}
void TulisPOINT (POINT P)
/* Nilai P ditulis ke layar dengan format "(X,Y)" 
   tanpa spasi, enter, atau karakter lain di depan, belakang, 
   atau di antaranya 
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */      
{
    POINT p;
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
    BacaPOINT(&p);
}          

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2)
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
{
    return ((Ordinat(P1) == Ordinat(P2)) && ((Absis(P1) == Absis(P2))));
}
boolean NEQ (POINT P1, POINT P2)
/* Mengirimkan true jika P1 tidak sama dengan P2 */
{
    return (!EQ(P1, P2));
}

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P)
/* Menghasilkan true jika P adalah titik origin */
{
    return ((Ordinat(P) == 0) && (Absis(P) == 0));
}
boolean IsOnSbX (POINT P)
/* Menghasilkan true jika P terletak Pada sumbu X */
{
    return (Ordinat(P) == 0);
}
boolean IsOnSbY (POINT P)
/* Menghasilkan true jika P terletak pada sumbu Y */
{
    return (Absis(P) == 0);
}
int Kuadran (POINT P)
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */
{
    if (Absis(P) > 0){
        if (Ordinat(P) > 0){
            return 1;
        } else {
            return 4;
        }
    } else {
        if (Ordinat(P) > 0){
            return 2;
        } else {
            return 3;
        }
    }
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */                           
POINT NextX (POINT P)
/* Mengirim salinan P dengan absis ditambah satu */      
{
    POINT p;
    float x = Absis(P) + 1;
    float y = Ordinat(P);
    CreatePoint(&p, x, y);
    return p;
}        

POINT NextY (POINT P)
/* Mengirim salinan P dengan ordinat ditambah satu */
{
    POINT p;
    float x = Absis(P);
    float y = Ordinat(P) + 1;
    CreatePoint(&p, x, y);
    return p;
}        
POINT PlusDelta (POINT P, float deltaX, float deltaY)
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
{
    POINT p;
    float x = Absis(P) + deltaX;
    float y = Ordinat(P) + deltaY;
    CreatePoint(&p, x, y);
    return p;
}        

POINT MirrorOf (POINT P, boolean SbX)
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
{
    if (SbX){
        POINT p;
        float y = (-1)*Ordinat(P);
        float x = Absis(P);
        CreatePoint(&p, x, y);
        return p;
    } else {
        POINT p;
        float y = Ordinat(P);
        float x = (-1)*Absis(P);
        CreatePoint(&p, x, y);
        return p;
    }
}

float Jarak0 (POINT P)
/* Menghitung jarak P ke (0,0) */
{
    return (sqrtf((Ordinat(P)*Ordinat(P)) + (Absis(P)*Absis(P))));
}

float Panjang (POINT P1, POINT P2)
/* Menghitung panjang garis yang dibentuk P1 dan P2 */
/* Perhatikanlah bahwa di sini spec fungsi kurang baik sebab menyangkut ADT Garis. */
/* Tuliskan spec fungsi yang lebih tepat. */
{
    return (sqrtf(powf((Ordinat(P2)-Ordinat(P1)),2) + powf((Absis(P2)-Absis(P1)),2)));
}

void Geser (POINT *P, float deltaX, float deltaY)
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
{
    // P-> X += deltaX;
    // P-> Y += deltaY;
    Absis(*P) += deltaX;
    Ordinat(*P) += deltaY; 
}

void GeserKeSbX (POINT *P)
/* I.S. P terdefinisi */
/* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
/* Proses : P digeser ke sumbu X. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */
{
    Ordinat(*P) = 0;
}


void GeserKeSbY (POINT *P)
/* I.S. P terdefinisi*/
/* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
/* Proses : P digeser ke sumbu Y. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */
{
    Absis(*P) = 0;
}

void Mirror (POINT *P, boolean SbX)
/* I.S. P terdefinisi */
/* F.S. P dicerminkan tergantung nilai SbX atau SbY */
/* Jika SbX true maka dicerminkan terhadap sumbu X */
/* Jika SbX false maka dicerminkan terhadap sumbu Y */
{
    if (SbX){
        Ordinat(*P) = (-1)*Ordinat(*P);
    } else {
        Absis(*P) = (-1)*Absis(*P);
    }
}

void Putar (POINT *P, float Sudut)
/* I.S. P terdefinisi */
/* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) */
{
    float rad = (-1)*(Sudut * (22.0/7) / 180);
    float absis = Absis(*P);
    float ordinat = Ordinat(*P);
    Absis(*P) = absis*(cos(rad)) - ordinat*(sin(rad));
    Ordinat(*P) = absis*(sin(rad)) + ordinat*(cos(rad));
}
