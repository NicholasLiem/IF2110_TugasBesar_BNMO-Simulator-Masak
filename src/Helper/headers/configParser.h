/* Definisi type boolean */

#ifndef _CONFIGPARSER_h
#define _CONFIGPARSER_h

#include <stdio.h>
#include "../../ADT/headers/wordmachine.h"
#include "../../ADT/headers/listlinier.h"
#include "../../ADT/headers/tree.h"
#include "../../ADT/headers/makanan.h"
#include "../../ADT/headers/word.h"
#include "../../ADT/headers/peta.h"

extern ListMakanan listMakanan;
extern List listTreeResep;
extern Peta peta;

void addMark(const char *filename);
void copyFile(const char *filename);
void copyTempFile(const char *filename);

void parseMakanan();
void parsePeta();
void parseResep();

void loadConfigMakanan(ListMakanan *listMakanan);
void loadConfigPeta(Peta *peta);
void loadConfigResep();

#endif