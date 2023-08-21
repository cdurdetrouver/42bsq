# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbazart <gbazart@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/20 15:21:52 by gbazart           #+#    #+#              #
#    Updated: 2023/08/21 11:27:23 by gbazart          ###   ########.fr        #
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
INPUT4 = file/example_file4

all: $(NAME)

$(NAME):
	# norminette -R CheckDefine $(FILES_PATH)$(FILES) $(HEADER)/*.h
	cc $(FLAGS) $(FILES_PATH)$(FILES) -I $(HEADER) -o $(NAME)
	./$(NAME) $(INPUT)

memory:
	cc $(FLAGS) $(FILES_PATH)$(FILES) -I $(HEADER) -o $(NAME)
	valgrind ./$(NAME) $(INPUT)

test:
	./$(NAME) $(INPUT) $(INPUT2) $(INPUT3) $(INPUT4)

clean:
	rm -f $(NAME)

re: clean all