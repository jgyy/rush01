/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegoh <jegoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 09:43:13 by jegoh             #+#    #+#             */
/*   Updated: 2024/10/12 09:45:20 by jegoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# include <unistd.h>
# include <stdlib.h>

# define GRID_SIZE 4

int		solve_puzzle(int grid[GRID_SIZE][GRID_SIZE], int *input);
void	print_grid(int grid[GRID_SIZE][GRID_SIZE]);
int		is_valid_placement(int grid[GRID_SIZE][GRID_SIZE], int row, int col, int num);
int		check_view_conditions(int grid[GRID_SIZE][GRID_SIZE], int *input);

#endif
