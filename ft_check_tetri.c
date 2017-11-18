/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <llacaze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:17:38 by llacaze           #+#    #+#             */
/*   Updated: 2017/11/18 19:14:33 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

char		*ft_tab_to_blocks(char **map)
{
	char	*new_str;
	int		count;

	count = 0;
	new_str = ft_memalloc(17);
	while (count <= 3)
	{
		ft_strcpy(&new_str[count * 4], (char *)map[count]);
		//on copie line par line dans une string pour avoir le tetrimino en ligne sans les newlines
		count++;
	}
	return (new_str);
}

void	ft_check_tetri(char *new_str, int c, int *this_tetri)
{
	int		i;

	i = 0;
	while (i < 19)
	{
		if (ft_strcmp(l_pattern[i].pattern, new_str) == 0)
		{
			this_tetri[c] = i;
			break;
		}
		i++;
	}
	if (i == 19)
		ft_error();
}

int		*ft_tetriminos(char **map, int nb_tetri)
{
	int		c;
	int		*this_tetri;
	char	**map_coord;
	char	*conv_map;
	
	c = 0;
	if (!(this_tetri = (int *)malloc(sizeof(int) * (576 * 2))))
		return (NULL);
	while (c < nb_tetri)
	{
		map_coord = &(map[c * 4]);
		while (ft_check_line(*map_coord))
			ft_move_up(map_coord);
		while (ft_check_column(map_coord))
			ft_move_left(map_coord);
		conv_map = ft_tab_to_blocks(map_coord);
		ft_check_tetri(conv_map, c, this_tetri);
		c++;
	}
	return (this_tetri);
}
