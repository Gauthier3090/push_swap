/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 21:12:48 by gpladet           #+#    #+#             */
/*   Updated: 2021/04/21 15:30:29 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_checker/header.h"

void	error_message(char *message)
{
	ft_putendl_fd(message, 1);
	exit(EXIT_FAILURE);
}

void	display_arrays(int *array_a, int *array_b)
{
	int	length_a;
	int	length_b;
	int	i;
	int	j;

	length_a = sizeof(array_a);
	length_b = sizeof(array_b);
	i = -1;
	j = -1;
	ft_putendl_fd("     PILE A\t\t\t      PILE B", 1);
	ft_putendl_fd("----------------\t\t-----------------", 1);
	while (length_a || length_b)
	{
		ft_putstr_fd("|\t", 1);
		if (length_a && array_a)
			ft_putnbr_fd(array_a[++i], 1);
		ft_putstr_fd("\t|", 1);
		ft_putstr_fd("\t\t|\t ", 1);
		if (length_b && array_b)
			ft_putnbr_fd(array_b[++j], 1);
		ft_putstr_fd("\t|", 1);
		ft_putendl_fd("----------------\t\t----------------", 1);
		if (length_a)
			length_a--;
		if (length_b)
			length_b--;
	}
}
