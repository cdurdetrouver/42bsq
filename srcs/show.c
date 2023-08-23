/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gbazart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 09:29:40 by gbazart           #+#    #+#             */
/*   Updated: 2023/08/23 11:09:08 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_show_tab(t_array src)
{
	int	i;

	i = 0;
	while (i < src.size[1] - 1)
	{
		ft_putstr(src.array[i]);
		ft_putchar('\n');
		i++;
	}
	ft_putstr(src.array[i]);
	ft_putchar('\n');
}
