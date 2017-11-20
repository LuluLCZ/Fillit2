/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <llacaze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 09:39:19 by Lulu              #+#    #+#             */
/*   Updated: 2017/11/07 16:13:27 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_strncat(char *base, const char *toadd, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (base[i])
		i++;
	while (n > 0 && toadd[j])
	{
		base[i] = toadd[j];
		i++;
		j++;
		n--;
	}
	base[i] = '\0';
	return (base);
}
