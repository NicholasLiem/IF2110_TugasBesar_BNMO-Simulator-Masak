/* Definisi type boolean */

#ifndef _CONFIGPARSER_h
#define _CONFIGPARSER_h

#include <stdio.h>
#include "../../adt/wordmachine/wordmachine.h"
#include "../../adt/listlinier/listlinier.h"
#include "../../adt/tree/tree.h"
#include "../../adt/makanan/makanan.h"
#include "../../adt/word/word.h"
#include "../../adt/peta/peta.h"

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
void loadConfigResep(List *listTreeResep);

#endif