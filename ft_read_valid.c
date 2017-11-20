/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <llacaze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:42:18 by llacaze           #+#    #+#             */
/*   Updated: 2017/11/20 21:01:31 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"
//#include "../../Projets/Libft/ft_strlen.c"
//#include "../../Projets/Libft/ft_strsub.c"
//#include "Libft/ft_strnew.c"
#include "includes/libft/libft.h"

char		*ft_buf_to_str(int fd)
{
	char	*str;
	int		reead;

	if (!(str = ft_strnew(SIZE_BUFF)))
			return (NULL);
	if (!(reead = read(fd, str, SIZE_BUFF) >= 0))
	{
		free(str);
		ft_error();
	}
	return (str);
}

void		ft_check_sharpoints(char *str)
{
	size_t		n;
	int		i;
	int		count_sharp;
	int		count_dots;
	size_t	p;

	p = ft_strlen(str);
	write(1, "u", 1);
	n = -1;
	while (n++ < p)
	{
		printf("%zu", ft_strlen(str));
		write(1, "l", 1);
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
		printf("%d", count_sharp);
		if (count_sharp != 4 || count_dots != 12)
			ft_error();
		i += 21;
	}
}

void			ft_check_nl(char *str)
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
			write(1, "s", 1);
			k = n + i;
			if (!SHPT(str[k]) || !SHPT(str[k + 1]) || !SHPT(str[k + 2]) 
								|| !SHPT(str[k + 3]) || !NL(str[k + 4]))
				ft_error();
			i += 5;
		}
		n += 21;
	}
}

void		ft_check_all(char *str)
{
	int		i;

	i = 0;
	if (str[ft_strlen(str) - 2] != '#' && str[ft_strlen(str) - 2] != '.')
		ft_error();
	printf("%s", str);
	ft_check_sharpoints(str);
	write(1, "ld", 2);
	ft_check_nl(str);
	//while (str[i])
	//{
	//	write(1, "o", 1);
	//	if (!SHPTNL(str[i]))
	//	{
	//		write(1, "p", 1);
	//		ft_error();
	//	}
	//	i++;
	//}
}
/*
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
*/
