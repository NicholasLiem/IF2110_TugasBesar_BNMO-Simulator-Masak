#ifndef _COMMAND_h
#define _COMMAND_h

#include <stdio.h>
#include "../../adt/wordmachine/wordmachine.h"
#include "../../adt/listlinier/listlinier.h"
#include "../../adt/tree/tree.h"
#include "../../adt/makanan/makanan.h"
#include "../../adt/word/word.h"
#include "../../adt/peta/peta.h"
#include "../../adt/kulkas/kulkas.h"
#include "../simulator/simulator.h"


void printMenu();

void notInput();

int getCookChoice();

void promptName(Word *word);

void menuHasNotLogin();

void menuHasLogin();

void displayInfo();

void splashArt();

int displayMenuKulkas();

int actionKulkas(int pilihan);
#endif