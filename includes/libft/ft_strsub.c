/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lulu <Lulu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 00:30:45 by llacaze           #+#    #+#             */
/*   Updated: 2017/11/07 16:12:55 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;

	i = 0;
	if (s)
	{
		if (!(s2 = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		while (i < len)
		{
			s2[i] = s[start];
			i++;
			start++;
		}
		s2[i] = '\0';
		return (s2);
	}
	return (NULL);
}
