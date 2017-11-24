/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <llacaze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:45:06 by llacaze           #+#    #+#             */
/*   Updated: 2017/11/24 23:22:57 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_header.h"

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
	ft_check_all(str);
	ret = ft_split(str);
	free(str);
	tetrimino = ft_tetriminos(ret, nb_tetri);
	free(ret);
	//ret = ft_solve_end(tetrimino, nb_tetri);
	ft_print_map(tetrimino, nb_tetri);
	close (fd);
	//free(ret);
	return (0);
}
