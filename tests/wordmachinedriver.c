#include "src/ADT/headers/wordmachine.h"
#include "stdio.h"

int main() {
    printf("hi");
    Word temp;
    Word baru;
    Word time = intToWord(192);
    printf("ok");
    printWord(time);
    copyWord(&temp, time);
    appendWord(&baru, temp);
    setWord(&temp, " hari ");
    appendWord(&baru, temp);
    printWord(baru);
    // while (true) {
    //     STARTCOMMAND();
    //     while(!endWord) {
    //         printWord(currentWord);
    //         printf(" ");
    //         ADVCOMMAND();
    //     }
    //     printf("\n");
    //     RESETCOMMAND();
    // }
}