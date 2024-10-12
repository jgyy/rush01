/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegoh <jegoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 09:43:39 by jegoh             #+#    #+#             */
/*   Updated: 2024/10/12 09:47:31 by jegoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	find_empty_cell(int grid[GRID_SIZE][GRID_SIZE], int *row, int *col)
{
	for (*row = 0; *row < GRID_SIZE; (*row)++)
	{
		for (*col = 0; *col < GRID_SIZE; (*col)++)
		{
			if (grid[*row][*col] == 0)
				return (1);
		}
	}
	return (0);
}

int	solve_puzzle(int grid[GRID_SIZE][GRID_SIZE], int *input)
{
	int	row;
	int	col;
	int	num;

	if (!find_empty_cell(grid, &row, &col))
		return (check_view_conditions(grid, input));
	for (num = 1; num <= GRID_SIZE; num++)
	{
		if (is_valid_placement(grid, row, col, num))
		{
			grid[row][col] = num;
			if (solve_puzzle(grid, input))
				return (1);
			grid[row][col] = 0;
		}
	}
	return (0);
}

int	is_valid_placement(int grid[GRID_SIZE][GRID_SIZE], int row, int col, int num)
{
	int	i;

	for (i = 0; i < GRID_SIZE; i++)
	{
		if (grid[row][i] == num || grid[i][col] == num)
			return (0);
	}
	return (1);
}
