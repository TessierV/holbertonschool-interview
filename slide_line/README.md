![image](https://github.com/TessierV/holbertonschool-interview/assets/113889290/d3363ec8-8d02-44b4-94eb-1d72e19a323e)

# Overview

This project implements the mechanics of the 2048 game for a single horizontal line. The goal is to be able to slide and merge numbers on this line in either left or right directions. Identical numbers, if contiguous or separated by zeros, should be merged.

# Task

The slide_line function allows sliding and merging an array of integers in a given direction.
Function prototype: ``int slide_line(int *line, size_t size, int direction)``;
The direction can be either SLIDE_LEFT or SLIDE_RIGHT.
The function returns 1 upon success and 0 upon failure.
Macros SLIDE_LEFT and SLIDE_RIGHT are defined in slide_line.h.
Style and compilation constraints are specified in the general requirements.

## Script Test

``` 0-main.c
#include <stdlib.h>
#include <stdio.h>

#include "slide_line.h"

#define LINE_SIZE   32

/**
 * print_array - Prints out an array of integer, followed by a new line
 *
 * @array: Pointer to the array of integer to be printed
 * @size: Number of elements in @array
 */
static void print_array(int const *array, size_t size)
{
    size_t i;

    printf("Line: ");
    for (i = 0; i < size; i++)
        printf("%s%d", i > 0 ? ", " : "", array[i]);
    printf("\n");
}

/**
 * main - Entry point
 *
 * @ac: Arguments counter
 * @av: Arguments vector
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int ac, char **av)
{
    int line[LINE_SIZE];
    int direction;
    size_t i, size;

    if (ac < 3)
    {
        fprintf(stderr, "Usage: %s <R/L> <n1> [n2...]\n", av[0]);
        return (EXIT_FAILURE);
    }

    /* Command line arguments to array of int */
    size = ac - 2;
    if (size > LINE_SIZE)
        size = LINE_SIZE;
    for (i = 0; i < size; i++)
        line[i] = atoi(av[i + 2]);

    /* Print the array */
    print_array(line, size);

    /* Parse direction */
    switch (*(av[1]))
    {
    case 'L':
        direction = SLIDE_LEFT;
        printf("Slide to the left\n");
        break;
    case 'R':
        direction = SLIDE_RIGHT;
        printf("Slide to the right\n");
        break;
    default:
        fprintf(stderr, "Unknown direction '%c'. Please use 'L' or 'R'", *(av[1]));
        return (EXIT_FAILURE);
    }

    /* Slide and merge */
    if (!slide_line(line, size, direction))
    {
        fprintf(stderr, "Failed to slide and merge line\n");
        return (EXIT_FAILURE);
    }

    /* Print the array */
    print_array(line, size);

    return (EXIT_SUCCESS);
}
```

## Compile

``gcc -Wall -Wextra -Werror -pedantic -o 0-slide_line 0-main.c 0-slide_line.c`

## Test

``alex@~/slide_line$ ./0-slide_line L 2 2 0 0
Line: 2, 2, 0, 0
Slide to the left
Line: 4, 0, 0, 0``

<br/><hr>
<p align="right">Holberton TOULOUSE</p>
