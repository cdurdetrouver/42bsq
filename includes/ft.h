/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gbazart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:20:46 by gbazart           #+#    #+#             */
/*   Updated: 2023/08/20 23:41:40 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# define _GNU_SOURCE
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct ft_array
{
	int		size;
	char	**array;
	char	fill[3];
}			ft_array;

void		ft_putstr(char *str);
int			ft_write(char *filename);
char		*ft_put_in_char(char *filename);
char		**ft_split(char *str, char *charset);
ft_array	ft_split_in_tab(char *filename);
void		ft_show_tab(ft_array src);
void		ft_putchar(char c);
ft_array	ft_get_fill_and_size(char **src);
int			ft_atoi(char *str);
int			ft_strlen(char *str);

#endif