/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gbazart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:30:35 by gbazart           #+#    #+#             */
/*   Updated: 2023/08/23 14:50:53 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_next_sep(int ind, const char *str, char *charset)
{
	int	count;
	int	j;

	count = 0;
	while (str[ind])
	{
		j = 0;
		while (charset[j])
		{
			if (charset[j] == str[ind])
			{
				return (count);
			}
			j++;
		}
		count++;
		ind++;
	}
	if (str[ind] == '\0')
		return (count);
	return (0);
}

int	count_words(const char *str, char *c)
{
	int	i;
	int	j;
	int	trigger;
	int	last;

	i = 0;
	j = 0;
	trigger = 1;
	last = 0;
	while (str[i])
	{
		j = 0;
		while (c[j])
		{
			if (c[j] == str[i] && last != 1)
			{
				trigger++;
				last = 0;
			}
			j++;
		}
		last++;
		i++;
	}
	return (trigger);
}

char	**ft_split(char *str, char *charset)
{
	char	**dest;
	int		i;
	int		j;
	int		k;
	int		len;

	dest = malloc(count_words(str, charset) * sizeof(char *));
	i = 0;
	k = 0;
	while (str[i])
	{
		len = ft_next_sep(i, str, charset);
		dest[k] = malloc(sizeof(char) * (len + 1));
		j = 0;
		if (len > 0)
		{
			while (j < len)
				dest[k][j++] = str[i++];
			dest[k++][j] = '\0';
		}
		if (str[i] != '\0')
			i++;
	}
	return (dest);
}
