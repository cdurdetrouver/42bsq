# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbazart <gbazart@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/20 15:21:52 by gbazart           #+#    #+#              #
#    Updated: 2023/08/21 14:18:58 by gbazart          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
FLAGS = -Wextra -Werror -Wall
HEADER = ./includes
FILES = *.c
FILES_PATH = srcs/
INPUT = file/test file/test2
X = 10
Y = 10
DESINTY = 2

all: $(NAME)

$(NAME):
	# norminette -R CheckDefine $(FILES_PATH)$(FILES) $(HEADER)/*.h
	cc $(FLAGS) $(FILES_PATH)$(FILES) -I $(HEADER) -o $(NAME)
	./$(NAME) $(INPUT)

memory:
	cc $(FLAGS) $(FILES_PATH)$(FILES) -I $(HEADER) -o $(NAME)
	valgrind ./$(NAME) $(INPUT)

map:
	rm -f file/test
	./file/map_generator.pl $(X) $(Y) $(DESINTY) >> file/test
	./file/map_generator.pl $(X) $(Y) $(DESINTY) >> file/test2

clean:
	rm -f $(NAME)

re: clean all
