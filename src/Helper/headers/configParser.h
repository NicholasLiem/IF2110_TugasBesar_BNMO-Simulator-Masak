/* Definisi type boolean */

#ifndef _CONFIGPARSER_h
#define _CONFIGPARSER_h

#include "../../ADT/headers/listlinier.h"

extern List listTreeResep;

void addMark(const char *filename);

void copyFile(const char *filename);

void copyTempFile(const char *filename);

void parseStrToTime(Word w);

void parseStrToMapSize(Word w);

void parseMakanan();

void parsePeta();
void parseResep();

void loadConfiguration(const char *filedir, int configNum);

#endif