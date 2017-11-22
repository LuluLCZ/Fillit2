/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <llacaze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 18:41:43 by llacaze           #+#    #+#             */
/*   Updated: 2017/11/21 17:21:34 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int		ft_size_map(int nb_tetri, int *tetrimino)
{
	int		i;
	int		map_size;

	i = -1;
	map_size = g_map[tetrimino[0]].map_need;
	while (i++ < nb_tetri)
	{
		//ici on verfie quelle est la taille de map min pour le 
		//plus grand tetrimino present qu on nous a donne.
		if (g_map[tetrimino[i]].map_need > map_size)
			map_size = g_map[tetrimino[i]].map_need;
	}
		//lorsque l on a plusieurs tetrimino il nous faut un plus grand carre
		//donc on prend le nousmbre de tetriminos *4 (savoir le nombre de 
		//sharp qu il y aura, et on check si c'est plus grand que la map^2 
		//puisque l on doit faire un carre on a un perimetre de x^2
	while (nb_tetri * 4 >= map_size * map_size)
		map_size++;
	return (map_size - 1);
}

char	**ft_generate_map(int size)
{
	char	**new_map;
	int		x;
	int		y;

	y = 0;
	if (!(new_map = (char **)malloc(sizeof(char *) * size + 1)))
		return (NULL);
	while (y < size)
	{
		if(!(new_map[y] = (char *)malloc(sizeof(char) * size + 1)))
			return (NULL);
		x = 0;
		while (x < size)
		{
			new_map[y][x] = '.';
			x++;
		}
		new_map[y][x] = '\0';
		y++;
	}
	new_map[y] = NULL;
	return (new_map);
}

void		ft_place(char **map, t_point pt[4], int tetri_nb, t_point ok)
{
	int		k;

	k = 0;
	while (k < 4)
	{
		//write(1, "p", 1);
		map[ok.y + pt[k].y][ok.x + pt[k].x] = 'A' + tetri_nb;
		k++;
	}
}

void		ft_delete(char **map, t_point pt[4], t_point ok)
{
	int		k;

	k = 0;
	while (k < 4)
	{
		map[ok.y + pt[k].y][ok.x + pt[k].x] = '.';
		k++;
	}
}
/*char	**ft_place(char **map)
{
	
}*/
/*
int		main(int ac, char **av)
{
	int		i;
	char	**ret;
	int	index;

	index = 0;
	i = ft_size_map;
	ret = ft_generate_map(ft_size_map(nb_tetri, ));
	while (ret[index])
	{
		printf("%s\n", ret[index]);
		index++;
	}
	return (0);
}*/
