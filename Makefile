# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alex <alex@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/13 09:24:28 by atabarea          #+#    #+#              #
#    Updated: 2025/04/16 12:13:58 by alex             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = push_swap.c ./src/organizer.c ./src/arguments_valid.c ./src/struct_init.c\
 	./src/reverse_rotate.c ./src/rotate.c ./src/push_to.c ./src/free_stacks.c\
	./src/stack_init_from_strings.c ./src/stack_init.c ./src/stack_pop.c\
	./src/stack_push.c ./src/swap.c ./src/sort_three.c ./src/char_search.c\
	./src/ft_atoi_long.c ./src/ft_split.c ./src/ft_calloc.c\
	./src/ft_bzero.c ./src/ft_isdigit.c ./src/check_max_min.c\
	./src/ksort_algorithm.c ./src/ft_strlen.c ./src/k_sort_utils.c
OBJ = $(SRC:.c=.o)
INCLUDE = push_swap.h
all: $(NAME)

$(NAME): $(OBJ)
%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re