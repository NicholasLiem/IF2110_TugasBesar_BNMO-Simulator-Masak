#include "src/ADT/headers/stack.h"
#include "stdio.h"

int main() {
    Stack stack1;
    CreateEmpty(&stack1);
    Push(&stack1, 3);
    int output;
    Pop(&stack1, &output);
    printf("%d", output);
}