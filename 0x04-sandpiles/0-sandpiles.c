#include "sandpiles.h"


/**
 * sum_grids -  Compute the sum of two grids
 * @grid1: grid 1
 * @grid2: grid 2
 * Return: void
 */
void sum_grids(int grid1[3][3], int grid2[3][3])
{
	int i = 0, j = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}
}

/**
 * is_unstable - check if a grid is unstable
 * @grid: grid
 * Return: 1 if grid is unstable, otherwise 0
 */
int is_unstable(int grid[3][3])
{
	int i = 0, j = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				return (1);
			}
		}
	}

	return (0);
}

/**
 * print_grid - prints a grid
 * @grid: grid
 * Return: void
 */
void print_grid(int grid[3][3])
{
	int i = 0, j = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%i", grid[i][j]);
			if (j < 2)
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}

/**
 * stabillize_grid - performs grid transformation to stabillize it
 * @grid: grid
 * Return: void
 */
void stabillize_grid(int grid[3][3])
{
	int i = 0, j = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				grid[i][j] -= 4;
				/* Up */
				if (i > 0)
				{
					grid[i - 1][j] += 1;
				}
				/* Right */
				if (j < 2)
				{
					grid[i][j + 1] += 1;
				}
				/* Down */
				if (i < 2)
				{
					grid[i + 1][j] += 1;
				}
				/* Left */
				if (j > 0)
				{
					grid[i][j - 1] += 1;
				}
			}
		}
	}
}

/**
 * sandpiles_sum - performs a sum of fractal numbers
 * @grid1: first fractal number
 * @grid2: second fractal number
 * Return: void
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	sum_grids(grid1, grid2);

	while (is_unstable(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		stabillize_grid(grid1);
	}
}

