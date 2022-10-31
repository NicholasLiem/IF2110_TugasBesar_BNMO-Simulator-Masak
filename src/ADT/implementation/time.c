#include <stdio.h>
#include "../headers/time.h"

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsTIMEValid (int D, int H, int M){
/* Mengirim true jika D,H,M dapat membentuk T yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */
    return (((H >= 0) && (H <= 23)) && ((M >= 0) && (M <= 59)) && ((D >= 0) && (D <= 31)));
}

/* *** Konstruktor: Membentuk sebuah TIME dari komponen-komponennya *** */
void CreateTime (TIME * T, int DD, int HH, int MM)
/* Membentuk sebuah TIME dari komponen-komponennya yang valid */
/* Prekondisi : DD, HH, MM valid untuk membentuk TIME */
{
    Day(*T) = DD;
    Hour(*T) = HH;
    Minute(*T) = MM;
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaTIME (TIME * T)
/* I.S. : T tidak terdefinisi */
/* F.S. : T terdefinisi dan merupakan jam yang valid */
/* Proses : mengulangi membaca komponen DD, HH, MM sehingga membentuk T */
/* yang valid. Tidak mungkin menghasilkan T yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen DD, HH, MM
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika TIME tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
   diulangi hingga didapatkan jam yang valid. */
/* Contoh: 
   60 3 4
   Jam tidak valid
   1 3 4
   --> akan terbentuk TIME <1,3,4> */
{
    int D;
    int H;
    int M;
    scanf("%d %d %d", &D, &H, &M);
    while (!(IsTIMEValid(D, H, M))){
        printf("Jam tidak valid\n");
        scanf("%d %d %d", &D, &H, &M);
    }
    CreateTime(T, D, H, M);
}
   
void TulisTIME (TIME T)
/* I.S. : T sembarang */
/* F.S. : Nilai T ditulis dg format DD:HH:MM */
/* Proses : menulis nilai setiap komponen T ke layar dalam format DD:HH:MM
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/ 

{
    if (Day(T) == 0 && Hour(T) == 0 && Minute(T) == 0){
        printf("0 ");
    } else {
        if(Day(T) !=  0){
            printf("%d hari ", Day(T));
        }

        if(Hour(T) != 0){
            printf("%d jam ", Hour(T));
        }

        if(Minute(T) != 0){
            printf("%d menit ", Minute(T));
        }
    }
}

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long TIMEToMenit (TIME T)
/* Diberikan sebuah TIME, mengkonversi menjadi jumlah Menit dari pukul 0:0:0 */
/* Rumus : menit = 24*60*DD + 60*HH + MM */

{
    return ((60*24*Day(T)) + (60*Hour(T)) + Minute(T));
}

TIME MenitToTIME (long N)
/* Mengirim  konversi Menit ke TIME */
{
    TIME t;
    int d;
    int h;
    int m;
    
    d = (N/(1440)); 
	h = (N -(1440*h))/60;
	m = (N - h*60 - d*1440);
	
    CreateTime(&t, d, h, m);
    return t;
}

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean TEQ (TIME T1, TIME T2)
/* Mengirimkan true jika T1=T2, false jika tidak */
{
    long t1 = TIMEToMenit(T1);
    long t2 = TIMEToMenit(T2);
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
    long t1 = TIMEToMenit(T1);
    long t2 = TIMEToMenit(T2);
    return (t1 < t2);
}
boolean TGT (TIME T1, TIME T2)
/* Mengirimkan true jika T1>T2, false jika tidak */
/* *** Operator aritmatika TIME *** */
{
    long t1 = TIMEToMenit(T1);
    long t2 = TIMEToMenit(T2);
    return (t1 > t2);
}

TIME NextMenit (TIME T){
    return MenitToTIME(TIMEToMenit(T) + 1);
}
/* Mengirim 1 Menit setelah T dalam bentuk TIME */
TIME NextNMenit (TIME T, int N)
/* Mengirim N Menit setelah T dalam bentuk TIME */
{
    return MenitToTIME(TIMEToMenit(T) + N);
}
TIME PrevMenit (TIME T)
/* Mengirim 1 Menit sebelum T dalam bentuk TIME */
{
    return MenitToTIME(TIMEToMenit(T) - 1);
}
TIME PrevNMenit (TIME T, int N)
/* Mengirim N Menit sebelum T dalam bentuk TIME */
/* *** Kelompok Operator Aritmetika *** */
{
    return MenitToTIME(TIMEToMenit(T) - N);
}

long Durasi (TIME TAw, TIME TAkh)
/* Mengirim TAkh-TAw dlm Menit, dengan kalkulasi */
/* Jika TAw > TAkh, maka TAkh adalah 1 hari setelah TAw */
{
    long t1 = TIMEToMenit(TAw);
    long t2 = TIMEToMenit(TAkh);
    long diff = t2-t1;
    return diff;
}
