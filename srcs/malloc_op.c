/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:18:49 by bince             #+#    #+#             */
/*   Updated: 2023/08/23 13:18:50 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	**malloc_dp(int size)
{
	int	**dynamic_table;

	dynamic_table = malloc(sizeof(int *) * size);
	if (!dynamic_table)
	{
		free(dynamic_table);
		exit(EXIT_FAILURE);
	}
	return (dynamic_table);
}

int	*malloc_dpi(int size)
{
	int	*dynamic_table;

	dynamic_table = malloc(sizeof(int) * size);
	if (!dynamic_table)
	{
		free(dynamic_table);
		exit(EXIT_FAILURE);
	}
	return (dynamic_table);
}
