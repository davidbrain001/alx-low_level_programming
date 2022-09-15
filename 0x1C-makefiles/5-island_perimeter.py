#!/usr/bin/python3
"""This module defines the island_perimeter function"""


def island_perimeter(grid):
    """
    Returns the perimeter of the island
    args:
        grid: list of list of integers
    Returns:
        The perimeter of the island defined in grid
    """

    total = 0

    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j] == 1:
                if i == 0 or grid[i - 1][j] == 0:
                    total += 1
                if j == 0 or grid[i][j - 1] == 0:
                    total += 1
                if i == len(grid) - 1 or grid[i + 1][j] == 0:
                    total += 1
                if j == len(grid[i]) - 1 or grid[i][j + 1] == 0:
                    total += 1
    return total
