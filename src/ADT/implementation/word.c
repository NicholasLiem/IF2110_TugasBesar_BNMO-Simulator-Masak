#include "../headers/word.h"

void printWord(Word word) {
    int i = 0;
    for (i = 0; i < word.Length; i++) {
        printf("%c", word.TabWord[i]);
    }
}