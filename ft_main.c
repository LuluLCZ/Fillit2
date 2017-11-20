/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <llacaze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:45:06 by llacaze           #+#    #+#             */
/*   Updated: 2017/11/20 20:54:42 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

char	**ft_split(char *str)
{
	char	**new_ret;

	new_ret = ft_strsplit(str, '\n');
	return (new_ret);
}

int		main(int ac, char **av)
{
	if (ac != 2)
		ft_usage();
	char	**ret;
	char	*str;
	int		fd;
	int		*tetrimino;
	int		nb_tetri;

	fd = open(av[1], O_RDONLY);
	str = ft_buf_to_str(fd);
	nb_tetri = (ft_strlen(str) + 1) / 21;
	write(1, ";", 1);
	printf("%s", str);
	ft_check_all(str);
	write(1, "p", 1);
	//ft_error();
	ret = ft_split(str);
	write(1, "l", 1);
	free(str);
	tetrimino = ft_tetriminos(ret, nb_tetri);
	write(1, "2", 1);
	free(ret);
	ret = ft_solve_end(tetrimino, nb_tetri);
	ft_print_map(tetrimino, nb_tetri);
	close (fd);
	free(ret);
	return (0);
}
