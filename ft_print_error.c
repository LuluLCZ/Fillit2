/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 10:33:27 by llacaze           #+#    #+#             */
/*   Updated: 2017/11/18 12:58:15 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_header.h"

void	ft_usage(void)
{
	write(1, "usage: ./fillit target_file", 27);
	exit(EXIT_FAILURE);
}

void	ft_error(void)
{
	write(1, "error\n", 6);
	exit(EXIT_FAILURE);
}
