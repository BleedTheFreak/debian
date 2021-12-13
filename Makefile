# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytaya <ytaya@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/13 14:37:56 by ytaya             #+#    #+#              #
#    Updated: 2021/12/13 21:48:38 by ytaya            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

mlx = -lmlx -framework OpenGL -framework AppKit
NAME = so_long
LIB = libft/libft.a
GNL = gnl/get_next_line.c
CFLAGS = -Wall -Wextra -Werror
SRCS = ./src/so_long.c \
		./src/so_long_checker.c \
		./src/so_long_error.c \
		./src/so_long_hooks.c \
		./src/so_long_read.c

all: $(NAME) $(SRCS)

$(NAME):$(LIB)
	gcc $(CFLAGS) $(SRCS) $(mlx) $(LIB) $(GNL) -o $(NAME)
$(LIB):
	make -C ./libft
	make clean -C ./libft
clean:
	rm -rf $(NAME)
fclean: clean
	rm -rf $(LIB)
	make fclean -C ./libft
re : fclean all