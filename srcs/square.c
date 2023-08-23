/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 20:43:11 by bince             #+#    #+#             */
/*   Updated: 2023/08/21 20:43:13 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	is_sq_possible(int x, int y, int size[3], int **da)
{
	int	inside_obs;

	inside_obs = 0;
	if (x + size[0] > size[1] || y + size[0] > size[2])
		return (0);
	inside_obs += da[y + size[0] - 1][x + size[0] - 1];
	if (x > 0)
		inside_obs -= da[y + size[0] - 1][x - 1];
	if (y > 0)
		inside_obs -= da[y - 1][x + size[0] - 1];
	if (y > 0 && x > 0)
		inside_obs += da[y - 1][x - 1];
	if (inside_obs > 0)
	{
		return (0);
	}
	return (1);
}

void	place_square(t_array arr, int *best)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < best[2])
	{
		i = 0;
		while (i < best[2])
		{
			arr.array[best[1] + j][best[0] + i] = arr.fill[2];
			i++;
		}
		j++;
	}
}

void	largest_square(int i, int j, int *best, int **da)
{
	int	size[3];

	size[0] = best[2] + 1;
	size[1] = best[3];
	size[2] = best[4];
	while (1)
	{
		if (is_sq_possible(j, i, size, da))
		{
			best[0] = j;
			best[1] = i;
			best[2] = size[0];
			size[0] += 1;
		}
		else
			break ;
	}
}
