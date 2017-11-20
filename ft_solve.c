/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 11:09:03 by llacaze           #+#    #+#             */
/*   Updated: 2017/11/20 13:34:32 by llacaze          ###   ########.fr       */
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
		//write(1, "p", 1);
		//write(1, "ntm\n", 4);
		if (map[pt[i].y + r][pt[i].x + o] == '.')
		{
			//write(1, "pas ntm\n", 8);
			available++;
		}
		i++;
	}
	if (available == 4)
		return (available);
	return (0);
}

int		ft_solve(char **map, int *tetrimino, int map_size, int tetri_nb, int nb_tetri)
{
	t_point	ok;
	int		i;
	int		r;
	int		o;

	i = 0;
	r = -1;
	while (r++ < (map_size - l_map[tetrimino[tetri_nb]].ordo_need))
	{
	//printf("%d", map_size);
		o = -1;
//		write(1, "l", 1);
		while (o++ < (map_size - l_map[tetrimino[tetri_nb]].abcisse_need))
		{
//			write(1, "k", 1);
			if (ft_check_available(map, l_coord[tetrimino[tetri_nb]].coordonnees.point, r, o) == 4)
			{
				//write(1, "u", 1);
				ok.y = r;
				ok.x = o;
					//printf("%s", map[o]);
				ft_place(map, l_coord[tetrimino[tetri_nb]].coordonnees.point, tetri_nb, ok);
				
				if (tetri_nb == nb_tetri - 1 || ft_solve(map, tetrimino, map_size, tetri_nb + 1, nb_tetri))
					return (1);
				else
				{
				//	write(1, "p", 1);
					ft_delete(map, l_coord[tetrimino[tetri_nb]].coordonnees.point, ok);
				//	write(1, "pute", 4);
				}
			}
		//		write(1, "k", 1);
			
			//else
			//	return (1);
		}
//		write(1, "5", 1);
	}
//	write(1, "9", 1);
	return (0);
}

char	**ft_test(int *tetrimino, int nb_tetri, int map_size)
{
	int		i;
	int		k;
	char	**map;
	i = 0;
	k = 0;
//	i = ft_size_map(nb_tetri, tetrimino);
	//while (k < nb_tetri)
		map = ft_generate_map(map_size);//{
		//ft_place(map, l_coord[tetrimino[0]].coordonnees.point, k);
		if (ft_solve(map, tetrimino, map_size, 0, nb_tetri) == 1)
		{
		//	write(1, "i", 1);
			return (map);
		}
		else
		{
//			write(1, ";", 1);
	//		new_map = ft_generate_map(map_size + 1);
//			write(1, "l", 1);
			//while (i < map_size)
			//{
		//		printf("%s", map[i]);
		//		i++;
		//	}
			return (ft_test(tetrimino, nb_tetri, map_size + 1));
				
		}
		write(1, "2", 1);
//		k++;
//	}
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
