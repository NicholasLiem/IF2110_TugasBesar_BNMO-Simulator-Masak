/* File : stack.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */

#ifndef simulator_H
#define simulator_H

#include "configParser.h"

extern Word playerName;
extern POINT currentLoc;
extern TIME currentTime;
extern boolean isStarted;
extern List listNotif;

void simLoadConfig();

boolean simMove(char c);

void simAdvTime(long time);

void printNotif();
#endif
