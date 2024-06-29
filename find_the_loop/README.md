# Find the loop

## Description

This project involves writing a C function that detects the presence of a loop in a singly linked list. The function returns the address of the node where the loop starts, or NULL if there is no loop.

1. **Compile the Program:**

   - Run the following command to compile the program:
     ```sh
     gcc -Wall -pedantic -Werror -Wextra 0-main.c 0-find_loop.c -L. -lloop -o main
     ```

2. **Run the Program:**
   - Use the following command to run the program with example arguments:
     ```sh
     ./main
     ```
   - This should output:
     `sh
     [0x13700f0] 1024
[0x13700d0] 402
[0x13700b0] 98
[0x1370090] 4
[0x1370070] 3
[0x1370050] 2
[0x1370030] 1
[0x1370010] 0
[0x1370560] 1024
[0x1370540] 402
[0x1370010] 98
[0x1370030] 7
[0x1370050] 6
[0x1370070] 5
[0x1370090] 4
[0x13700b0] 3
[0x13700d0] 2
[0x13700f0] 1
[0x1370110] 0
-> [0x1370030] 7
Loop starts at [0x1370030] 7
     `
