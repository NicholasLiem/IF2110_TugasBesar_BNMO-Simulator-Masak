#ifndef WORD_H
#define WORD_H

#define NMax 100
#define BLANK ' '

#include "stdio.h"

typedef struct {
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..CAPACITY-1] */
   int Length;
} Word;

void printWord(Word word);

#endif