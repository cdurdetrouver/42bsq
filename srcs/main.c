/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gbazart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:12:10 by gbazart           #+#    #+#             */
/*   Updated: 2023/08/23 14:59:14 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char 	*dest;
	t_array	array;

	i = 1;
	dest = NULL;
	if (argc == 1)
	{
		dest = ft_standard_intput();
		array = stdin_put_in_array(dest);
	}
	while (argv[i++] && argc > 1)
	{
		ft_put_in_array(&array, argv[1]);
		if (array.array == NULL)
			ft_putstr("map error\n");
		else
		{
			// algo(array);
			// ft_show_tab(array);
		}
		free(array.array);
		if (i < argc)
			ft_putchar('\n');
	}
	return (0);
}
