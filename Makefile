# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcrestey <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/28 19:58:31 by rcrestey          #+#    #+#              #
#    Updated: 2019/03/17 13:32:18 by niogden          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -Wextra -Wall -Werror

SRC =	src/main.c \
		src/ft_checker.c \
		src/list.c \
		src/bresenham.c \
		src/dessin.c \
	    src/window.c

OBJ =	main.o \
		ft_checker.o \
		list.o \
		bresenham.o \
		dessin.o \
	    window.o

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@gcc $(FLAGS) -o fdf -I /usr/local/include  -L libft/ -lft -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit $^

%.o : src/%.c include/fdf.h
	gcc $(FLAGS) -I include/ -c $< -o $@

clean:
	@make clean -C libft
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re lib
