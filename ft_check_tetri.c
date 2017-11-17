/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <llacaze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:17:38 by llacaze           #+#    #+#             */
/*   Updated: 2017/11/17 16:34:09 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

char		*ft_line_to_blocks(char **map)
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

char		**ft_tetriminos(char **map, int nb_tetri)
{
	int		c;
	char	**map_coord;
	char	*conv_map;
	
	c = 0;
	while (c < nb_tetri)
	{
		map_coord = &(map[c * 4])
		while (ft_check_line(*map_coord))
			ft_move_up(map_coord);
		while (ft_check_column(map_coord))
			ft_move_left(map_coord);
		conv_map = ft_line_to_blocks(map_coord);
	}
	return (map_coord);
}