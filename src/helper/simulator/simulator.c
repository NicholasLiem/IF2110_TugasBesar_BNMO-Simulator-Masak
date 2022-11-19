#include "simulator.h"

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
Word COMMAND_KULKAS = {"KULKAS", 6};
Word COMMAND_REK = {"REKOMENDASI", 11};

Word playerName;
POINT currentLoc;
TIME currentTime;
boolean isStarted = false;
List listNotif;
List oldNotif;
List listNotifUndo;
Queue listDelivery;
Queue listInventory;
Kulkas kulkas;
ListItemKulkas listItemKulkas;
stackState undo;
stackState redo;
ListSet treeRekomendasi;

void simLoadConfig() {
    createKulkas(&kulkas);
    createListItemKulkas(&listItemKulkas);

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
    treeRekomendasi = readTree(listTreeResep, listMakanan);
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

void printNotifUndo() {
    printf("\nNotifikasi: \n");
    if (isEmptyLin(listNotifUndo)) {
        return;
    }
    displayListLin(listNotifUndo);
    while (!isEmptyLin(listNotifUndo)) {
        ListType temp;
        deleteFirstLin(&listNotifUndo, &temp);
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
    Makanan food = searchMakananCommand(listMakanan, foodId, COMMAND);
    if (food.id == -1) {
        Word notif;
        setWord(&notif, "ID MAKANAN MU INVALID TAU GA???? Bikin cape!\n");
        insertNotif(listNotif, notif);
        setWord(&notif, "Tadi makananmu invalid..");
        insertNotif(&listNotifUndo, notif);
    }
    else if (isEqualWord(COMMAND, COMMAND_BUY)) {    
        enqueue(&listDelivery, food, 'D');       
        sendFoodNotif(food, listNotif);
    }else{
        List resepChildren = getTreeChildrenId(listTreeResep, food.id);
        Address addrChild = FIRST(resepChildren);
        Makanan foodRequired;
        boolean failed = false;
        int idxAtInventory;
        int count = 0;
        Queue listInvCopy;
        CreateQueue(&listInvCopy);
        copyInv(listInventory, &listInvCopy);
        while(addrChild != NULL){
            idxAtInventory = indexOfId(listInvCopy, INFO(addrChild).value);
            if(idxAtInventory == -1){
                count++;
                if(!failed){
                    printf("Yahh, kamu gak bisa bikin ");
                    printWord(food.nama);
                    printf(" karena kamu gak punya:\n");
                }
                foodRequired = searchMakanan(listMakanan, INFO(addrChild).value);
                printf("\t%d. ",count);
                printWord(foodRequired.nama);
                printf("\n");

                failed = true;
            } else {
                deleteAtQueue(&listInvCopy, idxAtInventory);
            }
            addrChild = NEXT(addrChild);
        }

        addrChild = FIRST(resepChildren);
        if(!failed){
            while(addrChild != NULL){
                idxAtInventory = indexOfId(listInventory, INFO(addrChild).value);
                deleteAtQueue(&listInventory, idxAtInventory);
                
                addrChild = NEXT(addrChild);
            }
            Word notif;
            Word temp;
            setWord(&notif, "Krrsss... ");
            appendWord(&notif, food.nama);
            setWord(&temp, " akan selesai dibuat dalam ");
            appendWord(&temp, timeToWord(food.lamaPengiriman));
            appendWord(&notif, temp);
            insertNotif(listNotif, notif);  

            setWord(&notif, "Pembuatan ");
            appendWord(&notif, food.nama);
            setWord(&temp, " dibatalkan. ");
            appendWord(&notif, temp);
            insertNotif(&listNotifUndo, notif); 
            enqueue(&listDelivery, food, 'D');
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

    setWord(&notif, "Pengiriman ");
    appendWord(&notif, food.nama);
    setWord(&temp, " dibatalkan. ");
    appendWord(&notif, temp);
    insertNotif(&listNotifUndo, notif); 
}

void processDeliveryAndExpired() {
    // displayQueuePretty(listDelivery, 'D');
    List foodReady = removeArrived(&listDelivery, &listNotif, &listNotifUndo);
    Address p = FIRST(foodReady);
    while (p != NULL){
        Makanan food = searchMakanan(listMakanan, p->info.makanan.id);
        food.exp = NextNMenit(food.exp, TIMEToMenit(p->info.makanan.lamaPengiriman));
        enqueue(&listInventory, food, 'I');    
        p = NEXT(p);
    }
    removeExpired(&listInventory, &listNotif, &listNotifUndo);   
}

void displayInventory() {
    printf("=======INVENTORY========");
    displayQueuePretty(listInventory, 'I');
}

void displayDelivery() {
    printf("========DELIVERY========");
    displayQueuePretty(listDelivery, 'D');
}

void insertMakananToKulkas(int id, int lebar, int panjang){
    if(id >= 1 && id <= lengthQueue(listInventory)){
        pushUndo(oldNotif);
        Makanan makananInventory = makananOfIndex(listInventory, id-1);
        boolean success = insertMakananKulkas(&listItemKulkas, &kulkas, makananInventory, lebar, panjang);
        if (success) {
            Word temp;
            setWord(&temp, "Berhasil memasukan ke kulkas!");
            insertNotif(&listNotif, temp);
            setWord(&temp, "Makanan dikeluarkan dari kulkas");
            insertNotif(&listNotifUndo, temp);
            deleteAtQueue(&listInventory, id-1);
        }
    } else {
        printf("ID makanan di inventory tidak valid!\n");
    }
    //sendNotifMakanan masuk kulkas
}

void insertMakananFromKulkas(int idKulkas){
    if (isIdMakananValid(kulkas, idKulkas)){
        pushUndo(oldNotif);
        Makanan takenFood = ambilMakanan(&listItemKulkas, &kulkas, idKulkas);
        enqueue(&listInventory, takenFood, 'I');
        Word temp;
        setWord(&temp, "Berhasil mengeluarkan makanan dari kulkas!");
        insertNotif(&listNotif, temp);
        setWord(&temp, "Makanan dimasukan ke kulkas dari kulkas");
        insertNotif(&listNotifUndo, temp);
    } else {
        printf("ID makanan di kulkas tidak valid!\n");
    }
    // setNotifMakanan Masuk inventory
}

void displayKulkas(){
    printf("============== ISI KULKAS ============\n");
    printKulkas(kulkas);
    printf("================ INFO ================\n");
    printItemKulkas(listItemKulkas);
}

void pushNotifUndo(List notifUndo){
    stackAddress state = TOP(undo);
    copyListLin(notifUndo, &CURRENT_NOTIF_UNDO(state));
}

void pushUndo(List oldNotif){
    currentLoc = locationOf(&peta, SIMULATOR);
    List copyListNotif;
    copyListLin(oldNotif, &copyListNotif);
    Queue copyListInv, copyListDel;
    CreateQueue(&copyListInv);
    CreateQueue(&copyListDel);
    copyInv(listInventory, &copyListInv);
    copyDel(listDelivery, &copyListDel);
    Kulkas kulkasCopy;
    createKulkas(&kulkasCopy);
    ListItemKulkas listItemCopy;
    createListItemKulkas(&listItemCopy);
    copyKulkas(kulkas, &kulkasCopy, listItemKulkas ,&listItemCopy);
    List copylistNotifUndo;
    copyListLin(listNotif ,&copylistNotifUndo);
    PushState(&undo, currentLoc, currentTime, copyListNotif, copyListInv, copyListDel, kulkasCopy, listItemCopy, copylistNotifUndo);
    deleteAllState(&redo);
}

void pushRedo(List oldNotif){
    currentLoc = locationOf(&peta, SIMULATOR);
    List copyListNotif;
    copyListLin(oldNotif, &copyListNotif);
    Queue copyListInv, copyListDel;
    CreateQueue(&copyListInv);
    CreateQueue(&copyListDel);
    copyInv(listInventory, &copyListInv);
    copyDel(listDelivery, &copyListDel);
    Kulkas kulkasCopy;
    createKulkas(&kulkasCopy);
    ListItemKulkas listItemCopy;
    createListItemKulkas(&listItemCopy);
    copyKulkas(kulkas, &kulkasCopy, listItemKulkas ,&listItemCopy);
    // stackAddress state = TOP(undo);
    List copylistNotifUndo;
    copyListLin(listNotif, &copylistNotifUndo);
    PushState(&redo, currentLoc, currentTime, copyListNotif, copyListInv, copyListDel, kulkasCopy, listItemCopy, copylistNotifUndo);
}

void undoState(stackState *undo){
        printf("Undo berhasil\n");
        stackAddress state = TOP(*undo);
        currentLoc = locationOf(&peta, SIMULATOR);
        SetLegend(&peta, currentLoc , CURRENT_LOC(state), SIMULATOR);
        currentTime = CURRENT_TIME(state);
        List listBaru = concatLin(CURRENT_NOTIF(state), CURRENT_NOTIF_UNDO(state));
        copyListLin(listBaru, &listNotif);
        deleteQ(&listInventory);
        deleteQ(&listDelivery);
        copyInv(CURRENT_INVENTORY(state), &listInventory);
        copyDel(CURRENT_DELIVERY(state), &listDelivery);
        deleteAllKulkas(&listItemKulkas, &kulkas);
        copyKulkas(CURRENT_KULKAS(state), &kulkas, CURRENT_LIST_ITEM_KULKAS(state), &listItemKulkas);
        PopState(undo);
    }


void redoState(stackState *redo){
        printf("Redo berhasil\n");
        stackAddress state = TOP(*redo);
        currentLoc = locationOf(&peta, SIMULATOR);
        SetLegend(&peta, currentLoc , CURRENT_LOC(state), SIMULATOR);
        currentTime = CURRENT_TIME(state);
        copyListLin(CURRENT_NOTIF(state), &listNotif);
        deleteQ(&listInventory);
        deleteQ(&listDelivery);
        copyInv(CURRENT_INVENTORY(state), &listInventory);
        copyDel(CURRENT_DELIVERY(state), &listDelivery);
        deleteAllKulkas(&listItemKulkas, &kulkas);
        copyKulkas(CURRENT_KULKAS(state), &kulkas, CURRENT_LIST_ITEM_KULKAS(state), &listItemKulkas);
        PopState(redo);
    }


void simUndo(List oldNotif){
    printf("========UNDO========\n");
    if(!isEmptyStack(undo)){
        pushRedo(oldNotif);
        undoState(&undo);
    }
    else{
        printf("Tidak ada state yang bisa di undo\n");
    }
}

void simRedo(List oldNotif){
    printf("========REDO========\n");
    if(!isEmptyStack(redo)){
        currentLoc = locationOf(&peta, SIMULATOR);
        List copyListNotif;
        copyListLin(oldNotif, &copyListNotif);
        Queue copyListInv, copyListDel;
        CreateQueue(&copyListInv);
        CreateQueue(&copyListDel);
        copyInv(listInventory, &copyListInv);
        copyDel(listDelivery, &copyListDel);
        Kulkas kulkasCopy;
        createKulkas(&kulkasCopy);
        ListItemKulkas listItemCopy;
        createListItemKulkas(&listItemCopy);
        copyKulkas(kulkas, &kulkasCopy, listItemKulkas ,&listItemCopy);
        List copylistNotifUndo;
        copyListLin(listNotifUndo, &copylistNotifUndo);
        PushState(&undo, currentLoc, currentTime, copyListNotif, copyListInv, copyListDel, kulkasCopy, listItemCopy, copylistNotifUndo);
        redoState(&redo);
    }
    else{
        printf("Tidak ada state yang bisa di redo\n");
    }
}