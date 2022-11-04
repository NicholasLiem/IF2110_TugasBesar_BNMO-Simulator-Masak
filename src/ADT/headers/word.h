#ifndef WORD_H
#define WORD_H

#define NMax 200
#define BLANK ' '

#include "stdio.h"
#include "boolean.h"
#include "time.h"
#include "liststatik.h"

typedef struct {
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..CAPACITY-1] */
   int Length;
} Word;

void setWord(Word* word, char* input);

void addChar(Word* word, char input);

void printWord(Word word);

void copyWord(Word* nama, Word w);

int strToInt(Word w);

boolean wordIsInt(Word w);

boolean isEqualWord(Word word1, Word word2);

void toUpper(Word* word);

TIME wordToTime(Word w);

void appendWord(Word* word1, Word word2);
// ListStatik WordToMapSize(Word w);
Word intToWord(int num);

Word timeToWord (TIME T);

#endif