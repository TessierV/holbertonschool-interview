
This project implements a function in C to detect the presence of a cycle in a singly linked list. The check_cycle function takes a pointer to the beginning of the list as input and returns 0 if the list has no cycle, and 1 if a cycle is detected.

## Overview
The implementation utilizes a linked list structure defined in lists.h, along with auxiliary functions to manipulate the list. It employs Floyd's algorithm, also known as the tortoise and hare algorithm, to efficiently detect the presence of a cycle in the linked list.

## Compilation and Execution

### To compile the project, use the following command:
`gcc -Wall -Werror -Wextra -pedantic 0-main.c 0-check_cycle.c 0-linked_lists.c -o cycle`

### Execute the compiled program with:
`./cycle`

<br/><hr>
<p align="right">Holberton TOULOUSE</p>
