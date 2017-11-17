/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <llacaze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:42:34 by llacaze           #+#    #+#             */
/*   Updated: 2017/11/17 18:53:28 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEADER_H
# define FT_HEADER_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "../../Projets/Libft/libft.h"
# include "string.h"

# define S1 "#...#..##"
# define S2 "#...#...##"
# define S3 "##...#...#"
# define S4 "##..#...#"
# define S5 "#.###"
# define S6 "###...#"
# define S7 "##...##"
# define S8 "##.##"
# define S9 "#..##..#"
# define S10 "#...##...#"
# define S11 "##..##"
# define S12 "#...#...#...#"
# define S13 "####"

# define FALSE  0
# define TRUE  1
# define SIZE_BUFF 546
# define SHPT(a) (a == '#' || a == '.')
# define NL(a) (a == '\n')
# define SHPTNL(a) (a == '#' || a == '.' || a == '\n')

typedef struct          s_point
{
    int         x;
    int         y;
}                       t_point;

typedef struct          s_tetri
{
    t_point      point[4];
}                       t_tetri;

typedef struct          s_pattern
{
    char        *pattern;
    int         min_map_size;
    int         width;
    int         height;
    t_tetri     coord;
}                       t_pattern;

char		*ft_buf_to_str(int fd);
char		**ft_str_to_tab(char *str);
char		**ft_str_split_nl(char **tab);
char		*ft_strstr(const char *haystack, const char *needle);
void		ft_valid(int i, char valid[20][15]);
int			ft_valid_tetri_check(char **tab, int nb_tetri);
int			ft_check_sharpoints(char *str);
int			ft_check_nl(char *str);
int			ft_check_all(char *str);
int		    ft_check_line(char *line);
int		    ft_check_column(char **map);
void	    ft_move_up(char **map);
void	    ft_move_left(char **map);
void        ft_check_tetri(char *new_str, int c, int *this_tetri);
char        *ft_tab_to_blocks(char **map);
int         *ft_tetriminos(char **map, int nb_tetri);
extern const t_pattern g_pattern[19];

#endif
