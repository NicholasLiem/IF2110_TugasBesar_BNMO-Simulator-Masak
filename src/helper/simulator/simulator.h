/* File : stack.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */

#ifndef simulator_H
#define simulator_H

#include "../configparser/configparser.h"
#include "../../adt/stack/stack.h"
#include "../../adt/kulkas/kulkas.h"
#include "../../adt/prioqueuedinamik/prioqueuedinamik.h"
#include "../../adt/peta/peta.h"
#include "../../adt/set/set.h" 

extern Word COMMAND_START;
extern Word COMMAND_EXIT;
extern Word COMMAND_MIX;
extern Word COMMAND_FRY;
extern Word COMMAND_CHOP;
extern Word COMMAND_BOIL;
extern Word COMMAND_BUY;
extern Word COMMAND_WAIT;
extern Word COMMAND_UNDO;
extern Word COMMAND_REDO;
extern Word COMMAND_CATALOG;
extern Word COMMAND_COOKBOOK;
extern Word COMMAND_MOVE;
extern Word COMMAND_EAST;
extern Word COMMAND_NORTH;
extern Word COMMAND_SOUTH;
extern Word COMMAND_WEST;
extern Word COMMAND_INVENTORY;
extern Word COMMAND_DELIVERY;
extern Word COMMAND_HELP;
extern Word COMMAND_KULKAS;
extern Word COMMAND_REK;

extern Word playerName;
extern POINT currentLoc;
extern TIME currentTime;
extern boolean isStarted;
extern List listNotif;
extern List oldNotif;
extern List listNotifUndo;
extern Queue listDelivery;
extern Queue listInventory;
extern stackState undo;
extern stackState redo;
extern boolean isRedo;
extern ListSet treeRekomendasi;
void simLoadConfig();

boolean simMove(char c);

void simAdvTime(long time);

void addDelivery(Word COMMAND, int choice, List* listNotif);

void printNotif();
void printNotifUndo();
void processDeliveryAndExpired();

void sendFoodNotif(Makanan food, List* listNotif);
void displayMenu(Word word);
void displayInventory();
void displayDelivery();
void displayKulkas();

void insertMakananToKulkas(int idMakanan, int lebar, int panjang);
void insertMakananFromKulkas(int idKulkas);

void pushNotifUndo(List notifUndo);
void pushUndo(List oldNotif);
void pushRedo(List oldNotif);
void undoState(stackState *undo);
void redoState(stackState *redo);
void simUndo(List oldNotif);
void simRedo(List oldNotif);

// void pushUndoNotif();
// void pushRedoNotif();
// void undoQueue(Queue qInv, Queue qDel, TIME diff);
// void redoQueue(Queue qInv, Queue qDel, TIME diff);

#endif
