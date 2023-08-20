/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gbazart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:25:03 by gbazart           #+#    #+#             */
/*   Updated: 2023/08/20 19:05:18 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_put_in_char(char *filename)
{
	int fd;
	int length;
	char buffer[25];
	char *tab;
	int	k;

	length = 1;
	fd = open(filename, O_RDONLY);
	k = 0;
	tab = malloc(sizeof(char) * 500000);
	while (length > 0)
	{
		length = read(fd, buffer, 25);
		while (buffer[k] != 'z')
		{
			*tab = buffer[k];
			tab++;
		}
		write(1, buffer, length);
	}
	close(fd);
	return (1);
}
