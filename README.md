# Tubes_Alstrukdat

Tests:
- gcc -I. tests/stackdriver.c src/ADT/implementation/*.c -o bin/testStack
- gcc -I. tests/wordmachinedriver.c src/ADT/implementation/*.c -o bin/testWordMachine

How to compile:
- gcc -I. {ALL FILES WITH .c, 1 file with main function} -o bin/{{MAIN_FILENAME}}