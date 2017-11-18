/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <llacaze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:45:06 by llacaze           #+#    #+#             */
/*   Updated: 2017/11/18 19:56:01 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

//static char		*ft_buf_to_str(int fd);
//static char		**ft_str_to_tab(char *str);

t_pattern	l_pattern[19] = {
	{"###..#.........."},
	{"#...##..#......."},
	{".#..##...#......"},
	{".#..###........."},
	{"##..#...#......."},
	{"##...#...#......"},
	{"#...#...##......"},
	{".#...#..##......"},
	{"..#.###........."},
	{"###...#........."},
	{"#...###........."},
	{"###.#..........."},
	{".##.##.........."},
	{"#...##...#......"},
	{"##...##........."},
	{".#..##..#......."},
	{"##..##.........."},
	{"#...#...#...#..."},
	{"####............"}
};

char	**ft_split(char *str)
{
	char	**new_ret;

	new_ret = ft_strsplit(str, '\n');
	return (new_ret);
}

int		main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	char	**ret;
	char	*str;
	int		fd;
	int		*tetrimino;
	int		i;
	int		nb_tetri;

	i = 0;
	fd = open(av[1], O_RDONLY);
	str = ft_buf_to_str(fd);
	nb_tetri = (ft_strlen(str) + 1) / 21;
	i = ft_check_all(str);
	if (!(i == 1))
		ft_error();
	ret = ft_split(str);
	free(str);
	//write(1, "h", 1);
	close (fd);
	//write(1, "o", 1);
	tetrimino = ft_tetriminos(ret, nb_tetri);
	//write(1, "0", 1);
	ret = ft_generate_map(ft_size_map(nb_tetri, tetrimino));
	//write(1, "_", 1);
	//ft_place(ret, tetrimino);
	ret = ft_test(ret, tetrimino, nb_tetri, ft_size_map(nb_tetri, tetrimino));
	//printf("%d", *index);
	//i = ft_tab_check_tetri(ret);
	i = 0;
	while (ret[i])
	{
		printf("%s\n", ret[i]);
		//printf("%s\n", new_ret[index]);
		i++;
	}
	close (fd);
	free(ret);
	return (0);
}
