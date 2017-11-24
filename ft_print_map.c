/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 19:14:20 by llacaze           #+#    #+#             */
/*   Updated: 2017/11/23 13:37:19 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_header.h"

void	ft_print_map(int *tetrimino, int nb_tetri)
{
	char	**map;
	int		i;
	
	i = 0;
	map = ft_solve_end(tetrimino, nb_tetri);
	while (map[i])
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
		i++;
	}
}
