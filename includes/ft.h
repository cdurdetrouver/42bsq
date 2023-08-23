/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gbazart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:20:46 by gbazart           #+#    #+#             */
/*   Updated: 2023/08/23 14:55:32 by gbazart          ###   ########.fr       */
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
	int		size[2];
	char	**array;
	char	fill[3];
}			t_array;

void		ft_putstr(char *str);
void		ft_putchar(char c);
int			ft_atoi(char *str);
void		ft_show_tab(t_array src);
int			ft_malloc_array(t_array *array, int fd);
int			ft_fill_array(int len, t_array *array, int fd);
void		read_file(int fd, char *filename);
int			create_array(t_array *array, int fd, char *filename);
char		*ft_strcpy(char *dest, char *src);
int			ft_strlen(char *str);
char		*ft_standard_intput(void);
char		**ft_split(char *str, char *charset);

#endif
