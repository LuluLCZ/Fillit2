# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llacaze <llacaze@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 11:29:27 by llacaze           #+#    #+#              #
#    Updated: 2017/11/20 20:14:40 by llacaze          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =fillit

CC = gcc

OPTIONS = -c

CFLAGS = -Wall -Wextra -Werror

RM = rm -fv

SRC = ft_buf_to_tab.c		\
	  ft_check_valid.c		\
	  ft_read_valid.c		\
	  ft_check_tetri.c		\
	  ft_main.c				\
	  ft_map.c				\
	  ft_print_error.c		\
	  ft_solve.c			\
	  ft_coordonnees.c		\
	  ft_print_map.c

OBJ=$(SRC:.c=.o)

HEAD_DIR = includes/libft/

all: $(NAME)

$(NAME): $(OBJ) Makefile
	$(CC) $(CFLAGS) $(OPTIONS) $(SRC)
	(cd $(HEAD_DIR) && $(MAKE) libft.a)
	$(CC) $(OBJ) includes/libft/libft.a -o $(NAME)

clean:
	$(RM) $(OBJ)
	(cd $(HEAD_DIR) && $(MAKE) $@)

fclean:
	(cd $(HEAD_DIR) && $(MAKE) $@)
	$(RM) $(OBJ)
	$(RM) $(NAME)

re: fclean all

.PHONY : all clean fclean re
