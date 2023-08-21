/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gbazart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:25:03 by gbazart           #+#    #+#             */
/*   Updated: 2023/08/21 11:45:21 by gbazart          ###   ########.fr       */
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

ft_array	ft_put_in_array(char **src)
{
	ft_array	array;
	int			i;
	int			j;
	int			len;
	char		*temp;

	len = ft_strlen(src[0]);
	i = 2;
	while (i >= 0)
	{
		array.fill[i] = src[0][len - 1];
		len--;
		i--;
	}
	i = 0;
	temp = malloc(len * sizeof(char));
	while (i < len)
	{
		temp[i] = src[0][i];
		i++;
	}
	array.size = ft_atoi(temp);
	free(temp);
	array.array = malloc(array.size * sizeof(int *));
	i = 1;
	while (i < array.size + 1)
	{
		array.array[i - 1] = malloc((ft_strlen(src[i]) + 1) * sizeof(int));
		j = 0;
		while (src[i][j] != '\0')
		{
			if (src[i][j] == array.fill[0])
				array.array[i - 1][j] = 0;
			else if (src[i][j] == array.fill[1])
				array.array[i - 1][j] = 1;
			else
			{
				array.array = NULL;
				return (array);
			}
			j++;
		}
		array.array[i - 1][j] = -1;
		i++;
	}
	return (array);
}

int	ft_check(ft_array array)
{
	int	i;
	int	j;
	int len;
	int len2;

	j = 0;
	i = 0;
	len = 0;
	while (array.array[i][j] != -1)
	{
		len++;
		j++;
	}
	i++;
	while (i < array.size)
	{
		j = 0;
		len2 = 0;
		while (array.array[i][j] != -1)
		{

			if (array.array[i][j] != 1 && array.array[i][j] != -1 && array.array[i][j] != 0)
				return (0);
			len2++;
			j++;
		}
		if (len2 != len)
			return (0);
		i++;
	}
	return (1);
}

ft_array	ft_split_in_tab(char *filename)
{
	ft_array	array;
	char		**dest;
	char		*src;

	src = ft_put_in_char(filename);
	dest = ft_split(src, "\n");
	array = ft_put_in_array(dest);
	if (array.array == NULL || !ft_check(array))
	{
		array.array = NULL;
	}
	free(src);
	free(dest);
	return (array);
}
