/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gbazart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:12:10 by gbazart           #+#    #+#             */
/*   Updated: 2023/08/20 23:44:06 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	main(int argc, char **argv)
{
	int		i;
	ft_array	array;

	i = 1;
	while (argv[i] && argc > 1)
	{
		array = ft_split_in_tab(argv[i]);
		i++;
	}
	ft_show_tab(array);
	return (0);
}
