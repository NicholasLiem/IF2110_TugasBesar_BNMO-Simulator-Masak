#include <stdio.h>
#include "wordmachine.h"

boolean endWord;
Word currentWord;

void IgnoreBlanks()
{
    /* Mengabaikan satu atau beberapa BLANK
       I.S. : currentChar sembarang
       F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    while (currentChar == BLANK || currentChar == '\n')
    {
        ADV();
    }
}

void IgnoreBlanksc()
{
    /* Mengabaikan satu atau beberapa BLANK
       I.S. : currentChar sembarang
       F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    while (currentChar == BLANK)
    {
        ADV();
    }
}

void STARTWORD()
{
    /* I.S. : currentChar sembarang
       F.S. : endWord = true, dan currentChar = MARK;
              atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
              currentChar karakter pertama sesudah karakter terakhir kata */
    START();
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        endWord = true;
    }
    else
    {
        endWord = false;
        CopyWord();
    }
}

void STARTWORDFILE(char* filename) {
    STARTFILE(filename);
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        endWord = true;
    }
    else
    {
        endWord = false;
        CopyWord();
    }
};

void STARTCOMMAND()
{
    STARTc();
    IgnoreBlanksc();
    if(currentChar == MARK_COMMAND)
    {
        endWord = true;
    }
    else
    {
        endWord = false;
        CopyWordCommand();
    }
}

void ADVCOMMAND(){
    IgnoreBlanksc();
    if(currentChar == MARK_COMMAND)
    {
        endWord = true;
    }
    else
    {
        CopyWordCommand();
        IgnoreBlanksc();
    }
}

void RESETCOMMAND() {
    currentChar = ' ';
    endWord = false;
}

void ADVWORD() {
    IgnoreBlanks();
    if (currentChar == MARK) {
        endWord = true;
    } else {
        CopyWord();
        IgnoreBlanks();
    }
};
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, endWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWord() {
    int counter = 0;
    while (currentChar != MARK && currentChar != BLANK && currentChar != MARK_COMMAND) {
        currentWord.TabWord[counter] = currentChar;
        ADV();
        counter++;
    }
    if (counter > NMax) {
        counter = NMax;
    }
    currentWord.Length = counter;
};

void CopyWordCommand() {
    int counter = 0;
    while (currentChar != BLANK && currentChar != MARK_COMMAND) {
        currentWord.TabWord[counter] = currentChar;
        ADVc();
        counter++;
    }
    if (counter > NMax) {
        counter = NMax;
    }
    currentWord.Length = counter;
};

void ADVWORDFILE()
{
    /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
       F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
              currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
              Jika currentChar = MARK, endWord = true.
       Proses : Akuisisi kata menggunakan procedure CopyWord */
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        endWord = true;
    }
    else
    {
        CopyWordFile();
        IgnoreBlanks();
    }
}

void CopyWordFile()
{
    /* Mengakuisisi kata, menyimpan dalam currentWord
       I.S. : currentChar adalah karakter pertama dari kata
       F.S. : currentWord berisi kata yang sudah diakuisisi;
              currentChar = BLANK atau currentChar = MARK;
              currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
              Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
    currentWord.Length = 0;
    while (currentChar != '\n' && currentChar != MARK)
    {
        if (currentWord.Length < NMax)
        { // jika lebih akan terpotong
            currentWord.TabWord[currentWord.Length++] = currentChar;
            ADV();
        }
        else
            break;
    }
}
