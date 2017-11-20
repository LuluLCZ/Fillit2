/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 11:09:03 by llacaze           #+#    #+#             */
/*   Updated: 2017/11/20 19:23:43 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int		ft_check_available(char **map, t_point pt[4], int r, int o)
{
	int		i;
	int		available;

	available = 0;
	i = 0;
	while (i < 4)
	{
		if (map[pt[i].y + r][pt[i].x + o] == '.')
			available++;
		i++;
	}
	if (available == 4)
		return (available);
	return (0);
}

int		ft_solve(char **map, int *tetrimino, int map_size, int tetri_nb, int nb_tetri)
{
	t_point	ok;
	int		r;
	int		o;

	r = -1;
	while (r++ < (map_size - l_map[tetrimino[tetri_nb]].ordo_need))
	{
		o = -1;
		while (o++ <= (map_size - l_map[tetrimino[tetri_nb]].abcisse_need))
		{
			if (ft_check_available(map, l_coord[tetrimino[tetri_nb]].coordonnees.point, r, o) == 4)
			{
				ok.y = r;
				ok.x = o;
				ft_place(map, l_coord[tetrimino[tetri_nb]].coordonnees.point, tetri_nb, ok);
				if (tetri_nb == nb_tetri - 1 || ft_solve(map, tetrimino, map_size, tetri_nb + 1, nb_tetri))
					return (1);
				else
				{
					ft_delete(map, l_coord[tetrimino[tetri_nb]].coordonnees.point, ok);
				}
			}
		}
	}
	return (0);
}

char	**ft_test(int *tetrimino, int nb_tetri, int map_size)
{
	int		i;
	int		k;
	char	**map;
	i = 0;
	k = 0;
	map = ft_generate_map(map_size);//{
	if (ft_solve(map, tetrimino, map_size, 0, nb_tetri) == 1)
		return (map);
	else
		return (ft_test(tetrimino, nb_tetri, map_size + 1));
	return (NULL);
}

char		**ft_solve_end(int *tetrimino, int nb_tetri)
{
	char	**map;
	int		map_size;

	map_size = ft_size_map(nb_tetri, tetrimino);
	map = ft_test(tetrimino, nb_tetri, map_size);
	return (map);
}
