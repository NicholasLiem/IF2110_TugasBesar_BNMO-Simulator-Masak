# Tubes_Alstrukdat
## How to compile?
1. Be on root folder (\Tubes_Alstrukdat)
2. Do this gcc -I. src/ADT/implementation/*.c {1 file with main function} -o bin/{{MAIN_FILENAME}}. This will include and compile all header files on ADT.
3. Run your executeable from bin ./bin/{{MAIN_FILENAME}}

Example:
- gcc -I. tests/stackdriver.c src/ADT/implementation/*.c -o bin/testStack
- ./bin/testStack
- gcc -I. tests/wordmachinedriver.c src/ADT/implementation/*.c -o bin/testWordMachine
- ./bin/testWordMachine