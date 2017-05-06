#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tprysiaz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/17 18:06:03 by tprysiaz          #+#    #+#              #
#    Updated: 2017/04/24 19:46:24 by tprysiaz         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

PS_NAME = push_swap
CHECKER_NAME = checker
FLAGS = -Wall -Werror -Wextra -O3
PS_SRC = push_swap.c  size_count.c instructions.c alhorithm.c \
		func_for_push_swap.c read_arguments.c sort_3_elem.c \
		general_funcs.c get_next_line.c 
CHECKER_SRC = checker.c size_count.c instructions.c alhorithm.c \
		func_for_push_swap.c read_arguments.c sort_3_elem.c \
		general_funcs.c get_next_line.c 

PS_OBJ = $(patsubst %.c, %.o, $(PS_SRC))
CHECKER_OBJ = $(patsubst %.c, %.o, $(CHECKER_SRC))

all: $(PS_NAME) $(CHECKER_NAME)

$(PS_NAME): $(PS_OBJ)
	make -C ./libft
	clang $(FLAGS) -o $@ $(PS_SRC) libft/libft.a

$(CHECKER_NAME): $(CHECKER_OBJ)
	clang $(FLAGS) -o $@ $(CHECKER_SRC) libft/libft.a

%.o: %.c
	clang $(FLAGS) -I ./libft/ -o $@ -c $<

clean:
	rm -f $(PS_OBJ)
	rm -f $(CHECKER_OBJ) $(CHECKER_NAME)

fclean: clean
	make fclean -C ./libft
	rm -f $(PS_OBJ) $(PS_NAME)
	rm -f $(CHECKER_OBJ) $(CHECKER_NAME)

re: fclean all