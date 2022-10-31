#include "src/ADT/headers/time.h"
#include "src/Helper/headers/configParser.h"
#include "stdio.h"

int main(){
    ListMakanan listMakanan;
    CreateListMakanan(&listMakanan);
    loadConfigMakanan(&listMakanan);
    displayListMakanan(listMakanan);
    printf("Length dari list makanan: %d", lengthListMakanan(listMakanan));
}