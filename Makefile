# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llacaze <llacaze@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 11:29:27 by llacaze           #+#    #+#              #
#    Updated: 2017/11/17 18:02:38 by llacaze          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

OPTIONS = -c

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = ft_buf_to_tab.c		\
	  ft_check_valid.c		\
	  ft_read_valid.c		\
	  Libft/ft_bzero.c		\
	  Libft/ft_strstr.c		\
	  Libft/ft_strcpy.c		\
	  Libft/ft_strsub.c		\
	  Libft/ft_strnew.c		\
	  Libft/ft_strlen.c		\
	  Libft/ft_strsplit.c	\
	  ft_check_tetri.c		\
	  ft_main.c				\
	  Libft/ft_memalloc.c	\
	  Libft/ft_strcmp.c

OBJ=$(SRC:.c=.o)



$NAME: $(OBJ) Makefile
	$(CC) $(CFLAGS) $(OPTIONS) $(SRC)
	$(CC) -o $(NAME) $(OBJ)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
