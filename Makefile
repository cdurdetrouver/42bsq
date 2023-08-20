# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbazart <gbazart@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/20 15:21:52 by gbazart           #+#    #+#              #
#    Updated: 2023/08/20 18:47:40 by gbazart          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
FLAGS = -Wextra -Werror -Wall
HEADER = ./includes
FILES = *.c
FILES_PATH = srcs/
INPUT = file/example_file
INPUT2 = file/example_file2
INPUT3 = file/example_file3

all: $(NAME)

$(NAME):
	# norminette -R CheckDefine $(FILES_PATH)$(FILES) $(HEADER)/*.h
	cc $(FLAGS) $(FILES_PATH)$(FILES) -I $(HEADER) -o $(NAME)
	./$(NAME) $(INPUT)

test:
	./$(NAME) $(INPUT)
	./$(NAME) $(INPUT2)
	./$(NAME) $(INPUT3)

clean:
	rm -f $(NAME)

re: clean all