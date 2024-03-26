#include "menger.h"

/**
 * check_char - Checks space for block.
 * @column: Is the column.
 * @row: Is the row.
 *
 * Return: # or space.
 */

char check_char(int column, int row)
{
    return (column && row ? (column % 3 == 1 && row % 3 == 1 ? ' ' : '#') : '#');
}

/**
 * menger - Function that draws a 2D Menger Sponge.
 * @level: Is the level of the Menger Sponge to draw.
 *
 * Return: Void.
 */

void menger(int level)
{
    int size, i, j;

    size = pow(3, level);
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
            printf("%c", check_char(i, j));
        printf("\n");
    }
}
