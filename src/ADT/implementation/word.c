#include "../headers/word.h"
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