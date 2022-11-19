#include "word.h"
#include <math.h>

void printWord(Word word) {
    int i = 0;
    for (i = 0; i < word.Length; i++) {
        printf("%c", word.TabWord[i]);
    }
}

int strToInt(Word w){
    int j, intTemp = 0;
    int multiplier = (int) pow(10, w.Length-1);
    // printf("\ncurrent word is\n");
    // printWord(w);
    // printf("\nword length %d\n", w.Length);
    for(j = 0; j < w.Length; j++){
        intTemp += (w.TabWord[j] - '0') * multiplier;
        multiplier /= 10;
    }
    return intTemp;
}

void copyWord(Word* nama, Word w){
    int j = 0;
    nama->Length = w.Length;
    for (j; j < w.Length; j++){
        nama->TabWord[j] = w.TabWord[j];
    }
    // printWord(*nama);
    // printf("\n");
}

void setWord(Word* word, char* input) {
    int index = 0;
    while (input[index] != '\0') {
        word->TabWord[index] = input[index];
        index++;
    }
    word->Length=index;
};

boolean isEqualWord(Word word1, Word word2) {
    if (word1.Length != word2.Length) {
        return false;
    }
    int j = 0;
    for (j; j < word1.Length; j++){
        if (word1.TabWord[j] != word2.TabWord[j]) {
            return false;
        }
    }  
    return true; 
}
void addChar(Word* word, char input) {
    word->TabWord[word->Length] = input;
    int newLength = word->Length + 1;
    word->Length = newLength;
}

boolean wordIsInt(Word w) {
    int j = 0;
    for (j; j < w.Length; j++){
        if (w.TabWord[j] < '0' || w.TabWord[j] > '9') {
            return false;
        }
    }   
    return true;
}

void toUpper(Word* word) {
    int i = 0;
    for (i; i < word->Length; i++) {
        if (word->TabWord[i] >= 'a' && word->TabWord[i] <= 'z') {
            word->TabWord[i] -= 32;
        }
    }
}

Word intToWord(int num) {
    Word res;
    setWord(&res, "");
    int temp = num;
    int digits = 0;
    while (temp) {
        temp /= 10;
        digits += 1;
    }
    while (digits) {
        temp = num;
        while (temp > 9) {
            temp /= 10;
        }
        addChar(&res, (char) (temp + '0'));
        num -= temp * (int) pow(10, digits-1);
        digits -= 1;
    }
    return res;
}

TIME wordToTime(Word w){
    TIME result;
    int tempWaktu[3];
    int i = 0, j = 0;
    Word temp;
    setWord(&temp, "");
    for(i; i < w.Length; i++){
        if (w.TabWord[i] != BLANK){
            addChar(&temp, w.TabWord[i]);
        } 
        if (w.TabWord[i] == BLANK || i == (w.Length-1)) {
            tempWaktu[j] = strToInt(temp);
            setWord(&temp, "");
            j++;
        }
    }
    CreateTime(&result, tempWaktu[0], tempWaktu[1], tempWaktu[2]);
    return result;
}

void appendWord(Word* word1, Word word2) {
    int index = word1->Length;
    for (int i = 0; i < word2.Length; i++) {
        word1->TabWord[index] = word2.TabWord[i];
        index += 1;
    }
    word1->Length += word2.Length;
};


// ListStatik WordToMapSize(Word w){
//     ListStatik ukuranPeta;
//     CreateListStatik(&ukuranPeta);

//     int i = 0, j = 0;
//     Word temp;
//     setWord(&temp, "");
//     for(i; i < w.Length; i++){
//         if (w.TabWord[i] != BLANK){
//             addChar(&temp, (char) w.TabWord[i]);
//         }
//         if (w.TabWord[i] == BLANK || i == (w.Length-1)){
//             ukuranPeta.contents[j] = strToInt(temp);
//             setWord(&temp, "");
//             j++;
//         }
//     }
//     return ukuranPeta;
// }


Word timeToWord (TIME T)
/* I.S. : T sembarang */
/* F.S. : Nilai T ditulis dg format DD:HH:MM */
/* Proses : menulis nilai setiap komponen T ke layar dalam format DD:HH:MM
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/ 
{
    Word baru;
    Word temp;
    setWord(&baru, "");
    setWord(&temp, "");
    if (Day(T) == 0 && Hour(T) == 0 && Minute(T) == 0){
        setWord(&baru, "0 menit ");
    } else {
        if (Day(T) !=  0){
            Word time = intToWord(Day(T));
            copyWord(&temp, time);
            appendWord(&baru, temp);
            setWord(&temp, " hari ");
            appendWord(&baru, temp);
        }

        if(Hour(T) != 0){
            Word time = intToWord(Hour(T));
            copyWord(&temp, time);
            appendWord(&baru, temp);
            setWord(&temp, " jam ");
            appendWord(&baru, temp);
        }

        if(Minute(T) != 0){
            Word time = intToWord(Minute(T));
            copyWord(&temp, time);
            appendWord(&baru, temp);
            setWord(&temp, " menit ");
            appendWord(&baru, temp);
        }
    }
    return baru;
}