#include "sandpiles.h"

/**
 * sum_two_grid - sum of two grid
 * @grid1: sandpiles grid
 * @grid2: sandpiles grid second
 *
 * Return: void function
 */
static void sum_two_grid(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] = grid1[i][j] + grid2[i][j];
}

/**
 * print_grid - print a sandpiles
 * @grid: sandpiles grid
 *
 * Return: void function
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * check_sandpiles - checking if is a sandpiles
 * @grid: sandpiles grid
 *
 * Return: int
 */
static int check_sandpiles(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
				return (0);
	return (1);
}

/**
 * converting_into_sandpiles - convert the grid
 * @grid1: sandpiles grid
 *
 * Return: void function
 */
static void converting_into_sandpiles(int grid1[3][3])
{
	int i, j;
	int grid_count[3][3];

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid_count[i][j] = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				grid1[i][j] = grid1[i][j] - 4;
				if ((i - 1 >= 0) && (i - 1 < 3))
					grid_count[i - 1][j] += 1;
				if ((i + 1 >= 0) && (i + 1 < 3))
					grid_count[i + 1][j] += 1;
				if ((j - 1 >= 0) && (j - 1 < 3))
					grid_count[i][j - 1] += 1;
				if ((j + 1 >= 0) && (j + 1 < 3))
					grid_count[i][j + 1] += 1;
			}
		}
	}
	sum_two_grid(grid1, grid_count);
}

/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: sandpiles grid
 * @grid2: sandpiles grid
 *
 * Return: void function
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	sum_two_grid(grid1, grid2);
	while (!check_sandpiles(grid1))
	{
		print_grid(grid1);
		converting_into_sandpiles(grid1);
	};
}
