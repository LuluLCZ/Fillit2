/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf_to_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <llacaze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 12:29:58 by llacaze           #+#    #+#             */
/*   Updated: 2017/11/20 19:20:37 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

char		**ft_str_to_tab(char *str)
{
	size_t		i;
	size_t		j;
	size_t		k;
	char		**new_str;

	i = 0;
	k = 0;
	j = 0;
	if (!(new_str = (char **)malloc(sizeof(sizeof(char *) * (ft_strlen(str) + 13)))))
		return (NULL);
	if (str[ft_strlen(str) - 2] != '#' && str[ft_strlen(str) - 2] != '.')
		ft_error();
	while (str[i])
	{
	//	printf("%zu\n", i);
	//	write(1, "v", 1);
		new_str[j] = ft_strsub(str, i, 20);
		j++;
		i = i + 21;
	}
	//printf("%d\n", j);
	new_str[j] = NULL;
	return (new_str);
}

char		**ft_str_split_nl(char **tab)
{
	char	**new_tab;
	char	*str;
	size_t		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	j = 0;
	if (!(str = (char *)malloc(sizeof(char) * 50)))
		return (NULL);
	if (!(new_tab = (char **)malloc(sizeof(char *) * ft_strlen(str) + (27 * 21))))
		return (NULL);
	while (tab[j])
	{
		i = 0;
		k = 0;
		while (tab[j][i] != '\n' && tab[j][i] != '\0')
		{
			str[k] = tab[j][i];
			i++;
			k++;
			while (tab[j][i] == '\n')
				i++;
		}
		new_tab[j++] = ft_strsub(str, 0, ft_strlen(str) - 2);
	}
	free(str);
	return (new_tab);
}
