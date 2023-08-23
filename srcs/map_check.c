/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:18:58 by bince             #+#    #+#             */
/*   Updated: 2023/08/23 13:18:59 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int check_fill(t_array arr, char c)
{
	if (c == arr.fill[0] || c == arr.fill[1])
		return (1);
	return (0);
}
int check_map(t_array arr)
{
	int i;
	int j;

	i = 0;
	while (i < arr.size[1])
	{
		j = 0;
		while (j < arr.size[0])
		{
			if (check_fill(arr, arr.array[i][j]) == 0)
					return 0;
			j++;
		}
		i++;
	}
	return (1);
}
