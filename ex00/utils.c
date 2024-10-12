/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegoh <jegoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 09:43:47 by jegoh             #+#    #+#             */
/*   Updated: 2024/10/12 09:52:35 by jegoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	print_grid(int grid[GRID_SIZE][GRID_SIZE])
{
	int		i;
	int		j;
	char	c;

	for (i = 0; i < GRID_SIZE; i++)
	{
		for (j = 0; j < GRID_SIZE; j++)
		{
			c = grid[i][j] + '0';
			write(1, &c, 1);
			if (j < GRID_SIZE - 1)
				write(1, " ", 1);
		}
		write(1, "\n", 1);
	}
}

int	check_view(int *line, int view)
{
	int	i;
	int	visible;
	int	max_height;

	visible = 0;
	max_height = 0;
	for (i = 0; i < GRID_SIZE; i++)
	{
		if (line[i] > max_height)
		{
			visible++;
			max_height = line[i];
		}
	}
	return (visible == view);
}

int check_view_conditions(int grid[GRID_SIZE][GRID_SIZE], int *input)
{
    int i, j;
    int line[GRID_SIZE];

    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++)
            line[j] = grid[j][i];
        if (!check_view(line, input[i]))
            return 0;
    }
\
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++)
            line[j] = grid[GRID_SIZE - 1 - j][i];
        if (!check_view(line, input[i + GRID_SIZE]))
            return 0;
    }

    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++)
            line[j] = grid[i][j];
        if (!check_view(line, input[i + 2 * GRID_SIZE]))
            return 0;
    }

    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++)
            line[j] = grid[i][GRID_SIZE - 1 - j];
        if (!check_view(line, input[i + 3 * GRID_SIZE]))
            return 0;
    }

    return 1;
}
