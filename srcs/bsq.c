/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gbazart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:25:03 by gbazart           #+#    #+#             */
/*   Updated: 2023/08/20 23:43:07 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_put_in_char(char *filename)
{
	int		fd;
	char	c;
	int		len;
	char	*dest;
	int		i;

	fd = open(filename, O_RDONLY);
	len = 0;
	while (read(fd, &c, 1) > 0)
		len++;
	close(fd);
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	fd = open(filename, O_RDONLY);
	i = 0;
	while (read(fd, &c, 1) > 0)
		dest[i++] = c;
	dest[i] = '\0';
	close(fd);
	return (dest);
}

void	ft_replace(ft_array *src)
{
	int i;
	int j;

	i = 0;
	j	= 0;
	while (i < src->size)
	{
		if (src->array[i][j] == src->fill[0])
			src->array[i][j] = '0';
		else if (src->array[i][j] == src->fill[1])
			src->array[i][j] = '1';
		j++;
	}
	i++;
}

ft_array	ft_get_fill_and_size(char **src)
{
	ft_array	array;

	if (ft_strlen(src[0]) == 5)
	{
		array.size = ft_atoi(&src[0][0]);
		array.fill[0] = src[0][1];
		array.fill[1] = src[0][2];
		array.fill[2] = src[0][3];
		array.array = &src[1];
	}
	else
	{
		array.array = NULL;
		return (array);
	}
	ft_replace(&array);
	return (array);
}

ft_array	ft_split_in_tab(char *filename)
{
	ft_array	array;
	char		**dest;
	char		*src;

	src = ft_put_in_char(filename);
	dest = ft_split(src, "\n");
	array = ft_get_fill_and_size(dest);
	free(src);
	return (array);
}

void	ft_show_tab(ft_array src)
{
	int i;
	int j;

	i = 1;
	while (i < src.size)
	{
		j = 0;
		while (src.array[i][j])
		{
			if (src.array[i][j] == 0)
				ft_putchar(src.fill[0]);
			else if (src.array[i][j] == 1)
				ft_putchar(src.fill[1]);
			else
				ft_putchar(src.fill[2]);
			j++;
		}
		ft_putchar('\n');
	}
}