# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llacaze <llacaze@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 11:29:27 by llacaze           #+#    #+#              #
#    Updated: 2017/11/20 19:45:12 by llacaze          ###   ########.fr        #
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
	  Libft/ft_strcmp.c		\
	  ft_map.c				\
	  ft_print_error.c		\
	  ft_solve.c			\
	  ft_coordonnees.c		\
	  ft_print_map.c		\
	  Libft/ft_putstr.c		\
	  Libft/ft_putchar.c

vpath %.c ./Libft/
vpath %.o ./Libft/
OBJ=$(SRC:.c=.o)

HEAD_DIR = ./Libft/

all: $(NAME)

$(NAME): $(OBJ) Makefile
	$(CC) $(CFLAGS) $(OPTIONS) $(SRC)
	$(CC) -o $(NAME) $(OBJ)



clean:
	$(RM) $(OBJ)
	(cd $(HEAD_DIR) && $(MAKE) $@)

fclean: clean
	$(RM) $(NAME)
	(cd $(HEAD_DIR) && $(MAKE) $@)

re: fclean all

.PHONY : all clean fclean re
