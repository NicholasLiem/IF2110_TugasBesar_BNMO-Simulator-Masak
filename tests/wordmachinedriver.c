#include "src/ADT/headers/wordmachine.h"
#include "stdio.h"

int main() {
    STARTWORD();
    while (endWord != true) {
        printWord(currentWord);
        printf(" ");
        ADVWORD();
    }
}