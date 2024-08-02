#!/usr/bin/python3
"""Island perimeter"""

def island_perimeter(grid):
    """returns the perimeter of the island described in grid"""
    if not grid:
        return 0

    perimeter = 0
    rows = len(grid)
    for row in range(rows):
        cols = len(grid[row])
        for col in range(cols):
            if grid[row][col] == 1:
                if row == 0 or grid[row - 1][col] == 0:
                    perimeter += 1
                if col == 0 or grid[row][col - 1] == 0:
                    perimeter += 1
                if row == rows - 1 or grid[row + 1][col] == 0:
                    perimeter += 1
                if col == cols - 1 or grid[row][col + 1] == 0:
                    perimeter += 1
    return perimeter
