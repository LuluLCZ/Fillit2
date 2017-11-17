/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <llacaze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:42:18 by llacaze           #+#    #+#             */
/*   Updated: 2017/11/17 12:30:41 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"
//#include "../../Projets/Libft/ft_strlen.c"
//#include "../../Projets/Libft/ft_strsub.c"
//#include "Libft/ft_strnew.c"
#include "Libft/libft.h"

char		*ft_buf_to_str(int fd)
{
	char	*str;
	int		reead;

	if (!(str = ft_strnew(SIZE_BUFF)))
			return (NULL);
	if (!(reead = read(fd, str, SIZE_BUFF) >= 0))
	{
		free(str);
		write(1, "Trop de tetri", 13);
		exit(EXIT_FAILURE);
	}
	return (str);
}

int			ft_check_sharpoints(char *str)
{
	size_t		n;
	int		i;
	int		count_sharp;
	int		count_dots;

	n = -1;
	while (n++ < ft_strlen(str))
	{
		i = -1;
		count_sharp = 0;
		count_dots = 0;
		while (i++ < 19)
		{
			if (str[i + n] == '#')
				count_sharp++;
			if (str[i + n] == '.')
				count_dots++;
		}
		if (count_sharp != 4 || count_dots != 4)
			return (FALSE);
		i += 21;
	}
	return (TRUE);
}

int			ft_check_nl(char *str)
{
	int		i;
	size_t		n;
	int		k;

	n = 0;
	while (n < ft_strlen(str))
	{
		i = 0;
		while (i <= 15)
		{
			k = n + i;
			if (!SHPT(str[k]) || !SHPT(str[k + 1]) || !SHPT(str[k + 2]) 
								|| !SHPT(str[k + 3]) || !NL(str[k + 4]))
				return (FALSE);
			i += 5;
		}
		n += 21;
	}
	return (TRUE);
}

int			ft_check_all(char *str)
{
	int		i;

	i = 0;
	if (ft_check_sharpoints(str) == FALSE)
		return (FALSE);
	if (ft_check_nl(str) == FALSE)
		return (FALSE);
	while (str[i])
	{
		if (!SHPTNL(str[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int		main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	char	**ret;
	char	*str;
	char	**new_ret;
	int		fd;
	int		index;
	int		i;
	int		nb_tetri;


	i = 0;
	index = 0;
	fd = open(av[1], O_RDONLY);

	str = ft_buf_to_str(fd);
	nb_tetri = (ft_strlen(str) + 1) / 21;
	i = ft_check_all(str);
	if (i == TRUE)
	{
		write(1, "p", 1);
		return (0);
	}
	//printf("%d", nb_tetri);
	ret = ft_str_to_tab(str);
	new_ret = ft_str_split_nl(ret);
	//i = ft_valid_tetri_check(new_ret, nb_tetri);
	//i = ft_tab_check_tetri(ret);
	//if (i == 0)
	//{
	//	write(1, "o", 1);
	//	exit(EXIT_FAILURE);
	//}

	//new_ret = ft_split_dots(new_ret);
	//ft_erreurs(new_ret);
	//while (ret[index])
	//{
	//	printf("%s", ret[index]);
	//	printf("%s\n", new_ret[index]);
	//	index++;
	//}
	return (0);
}
