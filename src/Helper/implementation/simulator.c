#include "../headers/simulator.h"

Word COMMAND_START = {"START", 5};
Word COMMAND_EXIT = {"EXIT", 4};
Word COMMAND_MIX = {"MIX",3};
Word COMMAND_FRY = {"FRY", 3};
Word COMMAND_CHOP = {"CHOP", 4};
Word COMMAND_BOIL = {"BOIL", 4};
Word COMMAND_BUY = {"BUY", 3};
Word COMMAND_WAIT = {"WAIT", 4};
Word COMMAND_UNDO = {"UNDO", 4};
Word COMMAND_REDO = {"REDO", 4};
Word COMMAND_CATALOG = {"CATALOG", 7};
Word COMMAND_COOKBOOK = {"COOKBOOK", 8};
Word COMMAND_MOVE = {"MOVE", 4};
Word COMMAND_EAST = {"EAST", 4};
Word COMMAND_NORTH = {"NORTH", 5};
Word COMMAND_SOUTH = {"SOUTH", 5};
Word COMMAND_WEST = {"WEST", 4};
Word COMMAND_INVENTORY = {"INVENTORY", 9};
Word COMMAND_DELIVERY = {"DELIVERY", 8};
Word COMMAND_HELP = {"HELP", 4};

Word playerName;
POINT currentLoc;
TIME currentTime;
boolean isStarted = false;
List listNotif;
Queue listDelivery;
Queue listInventory;
stackState undo;
stackState redo;
boolean isRedo = false;

void simLoadConfig() {
    createListMakanan(&listMakanan);
    loadConfigMakanan(&listMakanan);
    // displayListMakanan(listMakanan);

    // printf("=======================\n");
    loadConfigPeta(&peta);
    placeLegend(&peta);
    // printf("Ini petanya: \n");
    // DisplayPeta(peta);
    // printf("\n=======================\n");

    loadConfigResep(&listTreeResep);
    // for (int i = 0; i < lengthLin(listTreeResep); i++) {
    //     ListType tree = getElmtLin(listTreeResep, i);
    //     printf("Ini resep ke %i\n", i);
    //     PrintTree(tree.address);
    //     printf("-----\n");
    // }
};

boolean simMove(char c) {
    return MoveSimulator(&peta, c, &listNotif);
}

void simAdvTime(long time) {
    currentTime = NextNMenit(currentTime, time);
    advTimeExpired(&listInventory, time);
    advTimeDelivery(&listDelivery, time);
}

void printNotif() {
    printf("\nNotifikasi: \n");
    if (isEmptyLin(listNotif)) {
        return;
    }
    displayListLin(listNotif);
    while (!isEmptyLin(listNotif)) {
        ListType temp;
        deleteFirstLin(&listNotif, &temp);
    }
}

void displayMenu(Word action) {
    printf("==============");
    printWord(action);
    printf("==============\n");
    displayMakananList(listMakanan, action);
    printf("Masukkan ID MAKANAN yang anda inginkan!\n");
    printf("Jika berubah pikiran/tidak ada yang memenuhi, masukkan 0\n\n");
}

void addDelivery(Word COMMAND, int foodId, List* listNotif) {
    if (isEqualWord(COMMAND, COMMAND_BUY)) {
        Makanan food = searchMakananCommand(listMakanan, foodId, COMMAND);
        if (food.id == -1) {
            Word notif;
            setWord(&notif, "ID MAKANAN MU INVALID TAU GA???? Bikin cape!\n");
            insertNotif(listNotif, notif);
        } else {
            enqueue(&listDelivery, food, 'D');       
            sendFoodNotif(food, listNotif);
        }
    }
}

void sendFoodNotif(Makanan food, List* listNotif) {
    Word notif;
    Word temp;
    setWord(&notif, "Baik, nanti kami kirim... Item: ");
    appendWord(&notif, food.nama);
    setWord(&temp, " --- Lama Masuk Tas: ");
    appendWord(&notif, temp);
    Word time = timeToWord(food.lamaPengiriman);
    appendWord(&notif, time);
    insertNotif(listNotif, notif);
}

void processDeliveryAndExpired() {
    List foodReady = removeArrived(&listDelivery, &listNotif);
    Address p = FIRST(foodReady);
    while (p != NULL){
        Makanan food = searchMakanan(listMakanan, p->info.makanan.id);
        food.exp = NextNMenit(food.exp, TIMEToMenit(p->info.makanan.lamaPengiriman));
        enqueue(&listInventory, food, 'I');    
        p = NEXT(p);
    }
    removeExpired(&listInventory, &listNotif);   
}

void displayInventory() {
    printf("=======INVENTORY========");
    displayQueuePretty(listInventory, 'I');
}

void displayDelivery() {
    printf("========DELIVERY========");
    displayQueuePretty(listDelivery, 'D');
}

void pushUndo(){
    PushState(&undo, peta, currentTime, listNotif, listInventory, listDelivery);
    deleteAllState(&redo);
    isRedo = false;
}

void pushRedo(){
    PushState(&redo, peta, currentTime, listNotif, listInventory, listDelivery);
}

void undoState(stackState *undo){
        printf("Undo berhasil\n");
        stackAddress state = TOP(*undo);
        peta = CURRENT_PETA(state);
        currentTime = CURRENT_TIME(state);
        listNotif = CURRENT_NOTIF(state);
        listInventory = CURRENT_INVENTORY(state);
        listDelivery = CURRENT_DELIVERY(state);
        PopState(undo);
    }


void redoState(stackState *redo){

    printf("Redo berhasil\n");
        stackAddress state = TOP(*redo);
        peta = CURRENT_PETA(state);
        currentTime = CURRENT_TIME(state);
        listNotif = CURRENT_NOTIF(state);
        listInventory = CURRENT_INVENTORY(state);
        listDelivery = CURRENT_DELIVERY(state);
        PopState(redo);
    }


void simUndo(){
    printf("========UNDO========\n");
    // if(!isRedo)PopState(&undo);
    if(!isEmptyStack(undo)){
        pushRedo();
        undoState(&undo);
    }
    else{
        printf("Tidak ada state yang bisa di undo\n");
    }
}

void simRedo(){
    isRedo = true;
    printf("========REDO========\n");
    if(!isEmptyStack(redo)){
        PushState(&undo, peta, currentTime, listNotif, listInventory, listDelivery);
        redoState(&redo);
    }
    else{
        printf("Tidak ada state yang bisa di redo\n");
    }
}
