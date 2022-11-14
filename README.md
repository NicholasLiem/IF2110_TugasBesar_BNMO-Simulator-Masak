# IF2110_TugasBesar_BNMO-Simulator-Masak
## How to compile?
1. Be on root folder  
   ```bash
    pwd
    {PARENT_FOLDER}\IF2110_TugasBesar_BNMO-Simulator-Masak
    ```
2. Enter this command
    ```bash
    gcc -std=c17 -I. src/ADT/implementation/*.c  -o bin/{{MAIN_FILENAME}} {MAIN_FILE} 
    ```
    This will include and compile all header files on ADT.
3. Run your executeable from bin  
    ```bash
    ./bin/{{MAIN_FILENAME}}
    ```

Example:
```bash
gcc -std=c17 -I. src/ADT/implementation/*.c -o bin/testStack tests/stackdriver.c
./bin/testStack
 ```
 ```bash
 gcc -std=c17 -I. src/ADT/implementation/*.c -o bin/testWordMachine tests/wordmachinedriver.c
 ./bin/testWordMachine
```
