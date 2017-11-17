/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <llacaze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 18:41:43 by llacaze           #+#    #+#             */
/*   Updated: 2017/11/17 20:36:22 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

char	**ft_generate_map(int size)
{
	char	**new_map;
	int		x;
	int		y;

	y = 0;
	if (!(new_map = (char **)malloc(sizeof(char *) * 576000)))
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

/*char	**ft_place(char **map)
{
	
}*/

int		main(int ac, char **av)
{
	int		i;
	char	**ret;
	int	index;

	index = 0;
	i = 10;
	ret = ft_generate_map(i);
	while (ret[index])
	{
		printf("%s\n", ret[index]);
		index++;
	}
	return (0);
}