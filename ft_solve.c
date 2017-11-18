/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 11:09:03 by llacaze           #+#    #+#             */
/*   Updated: 2017/11/18 14:55:43 by llacaze          ###   ########.fr       */
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
		//write(1, "ntm\n", 4);
		if (map[pt[i].y + r][pt[i].x + o] == '.')
		{
			write(1, "pas ntm\n", 8);
			i++;
			//n++;
		}
	}
	if (i == 4)
		return (i);
	return (0);
}

/*char	**ft_solve(char **map, int *tetrimino, int map_size)
{
	int		i;
	int		r;
	int		o;

	i = 0;
	r = -1;
	o = -1;
	while (r++ < map_size)
	{
		while (o++ < map_size)
		{
			if (ft_check_available(map, l_coord[tetrimino[0]].coordonnees.point, r, o) == 4)
			{
				ft_place(map, tetrimino, l_coord[tetrimino[0]].coordonnees.point);
			}
		}
	}
	return (map);
}*/

char	**ft_test(char **map, int *tetrimino, int nb_tetri)
{
	//int		i;
	int		k;

	k = 0;
	while (k < nb_tetri)
	{
		ft_place(map, l_coord[tetrimino[0]].coordonnees.point, k);
		tetrimino++;
		k++;
	}
	return (map);
}
