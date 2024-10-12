/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegoh <jegoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 09:43:24 by jegoh             #+#    #+#             */
/*   Updated: 2024/10/12 09:53:21 by jegoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	main(int argc, char **argv)
{
	int	input[16];
	int	grid[GRID_SIZE][GRID_SIZE] = {{0}};
	int	i;

	if (argc != 2)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	i = 0;
	while (i < 16)
	{
		input[i] = argv[1][i * 2] - '0';
		if (input[i] < 1 || input[i] > 4)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		i++;
	}
    if (solve_puzzle(grid, input))
        print_grid(grid);
    else
    {
        write(2, "Error\n", 6);
        return 1;
    }
    return 0;
}
