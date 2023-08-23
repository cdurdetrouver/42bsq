# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbazart <gbazart@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/20 15:21:52 by gbazart           #+#    #+#              #
#    Updated: 2023/08/23 14:59:39 by gbazart          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
FLAGS = -Wextra -Werror -Wall
HEADER = ./includes
FILES = *.c
FILES_PATH = srcs/
INPUT = file/map
X = 10000
Y = 10000
DENSITY = 50

all: $(NAME)

$(NAME):
	# norminette -R CheckDefine $(FILES_PATH)$(FILES) $(HEADER)/*.h
	cc $(FLAGS) $(FILES_PATH)$(FILES) -I $(HEADER) -o $(NAME)
	./$(NAME) < $(INPUT)

memory:
	cc $(FLAGS) $(FILES_PATH)$(FILES) -I $(HEADER) -o $(NAME)
	valgrind ./$(NAME) $(INPUT)

map:
	rm -f file/map
	./file/map_generator.pl $(X) $(Y) $(DENSITY) >> file/map
	./file/map_generator.pl $(X) $(Y) $(DENSITY) >> file/map2

clean:
	echo test

fclean:
	rm -f $(NAME)

re: fclean all
