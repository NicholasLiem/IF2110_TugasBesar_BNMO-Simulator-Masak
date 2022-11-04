#ifndef _COMMAND_h
#define _COMMAND_h

#include <stdio.h>
#include "../../ADT/headers/wordmachine.h"
#include "../../ADT/headers/listlinier.h"
#include "../../ADT/headers/tree.h"
#include "../../ADT/headers/makanan.h"
#include "../../ADT/headers/word.h"
#include "../../ADT/headers/peta.h"
#include "simulator.h"


void printMenu();

void notInput();

int getCookChoice();

void promptName(Word *word);

void menuHasNotLogin();

void menuHasLogin();

void displayInfo();

void splashArt();
#endif