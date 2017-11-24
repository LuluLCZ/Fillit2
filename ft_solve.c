/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 11:09:03 by llacaze           #+#    #+#             */
/*   Updated: 2017/11/23 13:52:43 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_header.h"

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

int		ft_solve(char **map, int *tetrimino, t_nb info, int tetri_nb)
{
	t_point	ok;
	int		r;
	int		o;

	r = -1;
	while (r++ < (info.map_size - g_map[tetrimino[tetri_nb]].ordo_need))
	{
		o = -1;
		while (o++ <= (info.map_size - g_map[tetrimino[tetri_nb]].abcisse_need))
		{
			if (ft_check_available(map, g_coord[tetrimino[tetri_nb]].coordonnees.point, r, o) == 4)
			{
				ok.y = r;
				ok.x = o;
				ft_place(map, g_coord[tetrimino[tetri_nb]].coordonnees.point, tetri_nb, ok);
//				while (i < map_size)
//				{
//					printf("%s\n", map[i]);
//					i++;
//				}
				if (tetri_nb == info.nb_tetri - 1 || ft_solve(map, tetrimino, info, tetri_nb + 1))
					return (1);
				else
				{
					ft_delete(map, g_coord[tetrimino[tetri_nb]].coordonnees.point, ok);
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
	t_nb	info;

	info.map_size = map_size;
	info.nb_tetri = nb_tetri;
	i = 0;
	k = 0;
	map = ft_generate_map(map_size);//{
	if (ft_solve(map, tetrimino, info, 0) == 1)
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
