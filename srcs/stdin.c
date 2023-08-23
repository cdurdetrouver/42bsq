/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gbazart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 11:52:39 by gbazart           #+#    #+#             */
/*   Updated: 2023/08/23 13:45:29 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_realloc(char *src, int size)
{
	char *new_str;

	new_str = malloc(size * sizeof(char));
	new_str = ft_strcpy(new_str, src);
	free(src);
	return (new_str);
}

char 	*ft_standard_intput(void)
{
	char	c;
	char 	*dest;
	int 	size;
	int		i;

	i = 0;
	size = 10;
	dest = malloc(size * sizeof(char));
	while (read(STDIN_FILENO, &c, 1) > 0)
	{
		dest[i] = c;
		if (i >= size - 1)
		{
			size += 20;
			dest = ft_realloc(dest, size);
			if (!dest)
				exit(EXIT_FAILURE);
		}
		i++;
	}
	return (dest);
}

