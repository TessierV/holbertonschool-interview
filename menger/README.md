# 2D Menger Sponge

## Description
The Menger sponge is a fractal structure that extends the concept of the one-dimensional Cantor set and two-dimensional Sierpinski carpet to three dimensions. It is named after Karl Menger, who first described it in 1926.

This program draws a 2D representation of the Menger sponge based on the provided level. It uses the '#' character to represent filled blocks and space character (' ') to represent empty space.

## Script Test

```gcc -Wall -Wextra -Werror -pedantic -o 0-menger 0-menger.c 0-main.c -lm```

```#include <stdio.h>
#include <stdlib.h>

#include "menger.h"

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
    int level;

    if (ac < 2)
    {
        fprintf(stderr, "Usage: %s level\n", av[0]);
        return (EXIT_FAILURE);
    }

    level = atoi(av[1]);
    menger(level);

    return (EXIT_SUCCESS);
}
```
