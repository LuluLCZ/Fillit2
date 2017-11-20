/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <llacaze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 10:41:51 by llacaze           #+#    #+#             */
/*   Updated: 2017/11/20 21:03:35 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"
#include "includes/libft/libft.h"

int		ft_check_line(char *line)
{
	int		count;

	count = 1;
	while (*line++)
	{
		if (*line != '.')
			count = 0;
	}
	return (count);
}

int		ft_check_column(char **map)
{
	int		count;
	int		ret;

	ret = 1;
	count = 4;
	while (count--)
	{
		if (map[count][0] != '.')
			ret = 0;
	}
	return (ret);
}

void	ft_move_up(char **map)
{
	char	*tmp;
	int		line_pos;

	line_pos = 0;
	tmp = map[0];
	while (line_pos < 3)
	{
		map[line_pos] = map[line_pos + 1];
		line_pos++;
	}
	map[line_pos] = tmp;
}

void	ft_move_left(char **map)
{
	int		row_pos;
	int		line_pos;

	line_pos = 0;
	row_pos = 0;
	while (row_pos < 3)
	{
		while (line_pos <= 3)
		{
			map[line_pos][row_pos] = map[line_pos][row_pos + 1];
			line_pos++;
		}
		line_pos = 0;
		row_pos++;
	}
	while (line_pos <= 3)
	{
		//ici on est a la fin de la ligne il nous suffit de descendre et rajouter des points en fin 
		//de chaque ligne pour pouvoir refaire le carré;
		map[line_pos++][row_pos] = '.';
	}
}
