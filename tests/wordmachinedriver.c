#include "src/ADT/headers/wordmachine.h"
#include "stdio.h"

int main() {
    while (true) {
        STARTCOMMAND();
        while(!endWord) {
            printWord(currentWord);
            printf(" ");
            ADVCOMMAND();
        }
        printf("\n");
        RESETCOMMAND();
    }
}