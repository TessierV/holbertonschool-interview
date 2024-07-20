# Double Circular Linked List

## Overview
This repository contains functions to manipulate a double circular linked list, which is a linked list where each node points to both its previous and next nodes, and the last node points back to the first node, forming a circular structure. The project provides functionalities to add nodes either to the end or the beginning of the list.

## Project Structure
The project includes the following files:

- 0-add_node.c: Contains the functions to add nodes to the end or the beginning of the list.
- list.h: Header file that defines the structure of the nodes and the function prototypes.
- 0-main.c: Test file to demonstrate the functionalities of the list operations.

## Compilation
```gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-add_node.c -o double_circular_linked_list```

## Example Output
```
Added to the end:
Holberton
        ->prev: Engineer
        ->next: School
School
        ->prev: Holberton
        ->next: Full
Full
        ->prev: School
        ->next: Stack
Stack
        ->prev: Full
        ->next: Engineer
Engineer
        ->prev: Stack
        ->next: Holberton
Added to the beginning:
Engineer
        ->prev: Holberton
        ->next: Stack
Stack
        ->prev: Engineer
        ->next: Full
Full
        ->prev: Stack
        ->next: School
School
        ->prev: Full
        ->next: Holberton
Holberton
        ->prev: School
        ->next: Engineer
```