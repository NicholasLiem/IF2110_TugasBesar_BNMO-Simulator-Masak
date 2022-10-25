#include <stdio.h>
#include "../headers/time.h"

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsTIMEValid (int H, int M, int S){
/* Mengirim true jika H,M,S dapat membentuk T yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */
    return (((H >= 0) && (H <= 23)) && ((M >= 0) && (M <= 59)) && ((S >= 0) && (S <= 59)));
}

/* *** Konstruktor: Membentuk sebuah TIME dari komponen-komponennya *** */
void CreateTime (TIME * T, int HH, int MM, int SS)
{
    Hour(*T) = HH;
    Minute(*T) = MM;
    Second(*T) = SS;
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaTIME (TIME * T)
/* I.S. : T tidak terdefinisi */
/* F.S. : T terdefinisi dan merupakan jam yang valid */
/* Proses : mengulangi membaca komponen HH, MM, SS sehingga membentuk T */
/* yang valid. Tidak mungkin menghasilkan T yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen HH, MM, SS
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika TIME tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
   diulangi hingga didapatkan jam yang valid. */
/* Contoh: 
   60 3 4
   Jam tidak valid
   1 3 4
   --> akan terbentuk TIME <1,3,4> */
{
    int H;
    int M;
    int S;
    scanf("%d %d %d", &H, &M, &S);
    while (!(IsTIMEValid(H, M, S))){
        printf("Jam tidak valid\n");
        scanf("%d %d %d", &H, &M, &S);
    }
    CreateTime(T, H, M, S);
}
   
void TulisTIME (TIME T)
/* I.S. : T sembarang */
/* F.S. : Nilai T ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen T ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/ 
{
    printf("%d:%d:%d", Hour(T), Minute(T), Second(T));
}

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long TIMEToDetik (TIME T)
/* Diberikan sebuah TIME, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */
{
    return ((3600*Hour(T)) + (60*Minute(T)) + Second(T));
}

TIME DetikToTIME (long N)
/* Mengirim  konversi detik ke TIME */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang 
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus: 
   N1 = N mod 86400, baru N1 dikonversi menjadi TIME */
{
    TIME t;
    int h;
    int m;
    int s;
    
    if (N >= 86400){
        N = N % 86400;
    }

    h = (N/3600); 
	m = (N -(3600*h))/60;
	s = (N -(3600*h)-(m*60));
	
    CreateTime(&t, h, m, s);
    return t;
}

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean TEQ (TIME T1, TIME T2)
/* Mengirimkan true jika T1=T2, false jika tidak */
{
    long t1 = TIMEToDetik(T1);
    long t2 = TIMEToDetik(T2);
    return (t1 == t2);
}
boolean TNEQ (TIME T1, TIME T2)
/* Mengirimkan true jika T1 tidak sama dengan T2 */
{
    return (!TEQ(T1, T2));
}
boolean TLT (TIME T1, TIME T2)
/* Mengirimkan true jika T1<T2, false jika tidak */
{
    long t1 = TIMEToDetik(T1);
    long t2 = TIMEToDetik(T2);
    return (t1 < t2);
}
boolean TGT (TIME T1, TIME T2)
/* Mengirimkan true jika T1>T2, false jika tidak */
/* *** Operator aritmatika TIME *** */
{
    long t1 = TIMEToDetik(T1);
    long t2 = TIMEToDetik(T2);
    return (t1 > t2);
}

TIME NextDetik (TIME T){
    long t = TIMEToDetik(T);
    t++;
    if (t >= 86400){
        t = t % 86400;
    }
    return DetikToTIME(t);
}
/* Mengirim 1 detik setelah T dalam bentuk TIME */
TIME NextNDetik (TIME T, int N)
/* Mengirim N detik setelah T dalam bentuk TIME */
{
    long t = TIMEToDetik(T);
    t += N;
    if (t >= 86400){
        t = t % 86400;
    }
    return DetikToTIME(t);
}
TIME PrevDetik (TIME T)
/* Mengirim 1 detik sebelum T dalam bentuk TIME */
{
    long t = TIMEToDetik(T);
    t--;
    if (t < 0){
        t = t + 86400;
    }
    return DetikToTIME(t);
}
TIME PrevNDetik (TIME T, int N)
/* Mengirim N detik sebelum T dalam bentuk TIME */
/* *** Kelompok Operator Aritmetika *** */
{
    long t = TIMEToDetik(T);
    t -= N;
    if (t < 0){
        t = t + 86400;
    }
    return DetikToTIME(t);
}

long Durasi (TIME TAw, TIME TAkh)
/* Mengirim TAkh-TAw dlm Detik, dengan kalkulasi */
/* Jika TAw > TAkh, maka TAkh adalah 1 hari setelah TAw */
{
    long t1 = TIMEToDetik(TAw);
    long t2 = TIMEToDetik(TAkh);
    long diff = t2-t1;
    if (t1 > t2){
        diff += 86400;
    }
    return diff;
}
