/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gbazart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:39:39 by gbazart           #+#    #+#             */
/*   Updated: 2023/08/22 22:32:51 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	create_array2(char *dest, int len, t_array *array)
{
	char	*temp;
	int		i;

	i = -1;
	if (dest[len - 2] == dest[len - 3] || dest[len - 2] == dest[len - 4]
		|| dest[len - 3] == dest[len - 4])
		return (1);
	array->fill[2] = dest[len - 2];
	array->fill[1] = dest[len - 3];
	array->fill[0] = dest[len - 4];
	temp = malloc((len - 3) * sizeof(char));
	if (!temp)
		exit(EXIT_FAILURE);
	while (++i < len - 4)
		temp[i] = dest[i];
	temp[i] = 0;
	array->size[1] = ft_atoi(temp);
	if (array->size[1] < 1)
		return (1);
	free(temp);
	array->array = malloc(array->size[1] * sizeof(char *));
	if (!array->array)
		exit(EXIT_FAILURE);
	return (0);
}

int	create_array(t_array *array, int fd, char *filename)
{
	char	c;
	int		i;
	int		len;
	char	*dest;

	len = 0;
	i = 0;
	c = '\0';
	while (c != '\n' && read(fd, &c, 1) > 0)
		len++;
	close(fd);
	if (len < 4)
		return (EXIT_FAILURE);
	dest = malloc((len + 1) * sizeof(char));
	if (!dest)
		exit(EXIT_FAILURE);
	fd = open(filename, O_RDONLY);
	while (read(fd, &c, 1) > 0 && c != '\n')
		dest[i++] = c;
	dest[i] = '\0';
	if (create_array2(dest, len, array))
		return (1);
	free(dest);
	return (0);
}

int	ft_malloc_array(t_array *array, int fd)
{
	char	c;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (read(fd, &c, 1) > 0 && c != '\n')
		len++;
	while (i < array->size[1])
	{
		array->array[i] = malloc((len + 1) * sizeof(char));
		if (!array->array[i])
			exit(EXIT_FAILURE);
		i++;
	}
	array->size[0] = len;
	return (len);
}

void	read_file(int fd, char *filename)
{
	char	c;

	close(fd);
	fd = open(filename, O_RDONLY);
	c = '\0';
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n')
			break ;
	}
}

int	ft_fill_array(int len, t_array *array, int fd)
{
	char	*buffer;
	int		i;

	i = 0;
	buffer = malloc((len + 1) * sizeof(char));
	if (!buffer)
		exit(EXIT_FAILURE);
	while (read(fd, buffer, len + 1) > 0)
	{
		array->array[i] = ft_strcpy(array->array[i], buffer);
		if (buffer[len] == '\n')
			array->array[i][len] = '\0';
		else
			return (1);
		i++;
	}
	free(buffer);
	close(fd);
	return (0);
}
