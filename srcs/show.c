/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gbazart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 09:29:40 by gbazart           #+#    #+#             */
/*   Updated: 2023/08/21 11:30:01 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_show_tab(ft_array src)
{
	int i;
	int j;

	i = 0;
	while (i < src.size)
	{
		j = 0;
		while (src.array[i][j] != -1)
		{
			if (src.array[i][j] == 0)
				ft_putchar(src.fill[0]);
			else if (src.array[i][j] == 1)
				ft_putchar(src.fill[1]);
			else if (src.array[i][j] == 2)
				ft_putchar(src.fill[2]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}