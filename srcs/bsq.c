/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gbazart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:25:03 by gbazart           #+#    #+#             */
/*   Updated: 2023/08/20 21:12:03 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_put_in_char(char *filename)
{
	int fd;
	int length;
	char buffer[25];

	length = 1;
	fd = open(filename, O_RDONLY);
	while (length > 0)
	{
		length = read(fd, buffer, 25);
		write(1, buffer, length);
	}
	close(fd);
	return (1);
}
