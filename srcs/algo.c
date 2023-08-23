/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 20:37:58 by bince             #+#    #+#             */
/*   Updated: 2023/08/21 20:38:00 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		is_sq_possible(int x, int y, int size[3], int **da);
void	place_square(t_array arr, int *best);
void	largest_square(int i, int j, int *best, int **da);
int		**malloc_dp(int size);
int		*malloc_dpi(int size);
int		check_fill(t_array arr, char c);
int		check_map(t_array arr);

void	solve(int *best, int **da)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = 0;
	while (i < best[4])
	{
		j = 0;
		while (j < best[3])
		{
			largest_square(i, j, best, da);
			j++;
		}
		i++;
	}
}

int	d_value_gen(int **dynamic_table, int i, int j)
{
	int	d_value;

	d_value = 0;
	if (i > 0)
		d_value += dynamic_table[i - 1][j];
	if (j > 0)
		d_value += dynamic_table[i][j - 1];
	if (i > 0 && j > 0)
		d_value -= dynamic_table[i - 1][j - 1];
	return (d_value);
}

int	**create_dynamic_table(t_array arr)
{
	int	i;
	int	j;
	int	**dynamic_table;
	int	d_value;

	i = 0;
	j = 0;
	d_value = 0;
	dynamic_table = malloc_dp(arr.size[1]);
	while (i < arr.size[1])
	{
		j = 0;
		dynamic_table[i] = malloc_dpi(arr.size[0]);
		while (j < arr.size[0])
		{
			d_value = d_value_gen(dynamic_table, i, j);
			if (arr.array[i][j] == arr.fill[1])
				d_value++;
			dynamic_table[i][j] = d_value;
			j++;
		}
		i++;
	}
	return (dynamic_table);
}

int	fill_map(int x, int y, int **map)
{
	if (map[y][x] != 1)
	{
		map[y][x] = 1;
		return (1);
	}
	else
		return (-1);
}

t_array	algo(t_array arr)
{
	int	*best;
	int	**da;

	best = malloc(sizeof(int) * 5);
	best[0] = 0;
	best[1] = 0;
	best[2] = 0;
	best[3] = arr.size[0];
	best[4] = arr.size[1];
	da = create_dynamic_table(arr);
	solve(best, da);
	free(da);
	place_square(arr, best);
	free(best);
	return (arr);
}
