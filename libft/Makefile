# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytaya <ytaya@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/13 14:38:22 by ytaya             #+#    #+#              #
#    Updated: 2021/12/13 14:38:24 by ytaya            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
AR = ar
NAME = libft.a
flags = -Wall -Wextra -Werror
SRCS = ft_split.c ft_strlen.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strdup.c ft_substr.c ft_strjoin.c

OBJSRC = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJSRC)

%.o : %.c
	$(CC) $(flags) -c $< -o $@
	$(AR) rc $(NAME) $@

clean: 
	rm -rf  $(OBJSRC)

fclean: clean
	rm -rf $(NAME)

re: fclean all
