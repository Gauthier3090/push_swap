/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 21:12:48 by gpladet           #+#    #+#             */
/*   Updated: 2021/04/21 17:28:49 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_swap/header.h"

void	error_message(char *message)
{
	ft_putendl_fd(message, 1);
	exit(EXIT_FAILURE);
}

void	display_arrays(t_data *data)
{
	int	i;
	int	j;
	int	length_a;
	int	length_b;

	i = -1;
	j = -1;
	length_a = data->length_a;
	length_b = data->length_b;
	ft_putendl_fd("     PILE A\t\t\t      PILE B", 1);
	ft_putendl_fd("----------------\t\t-----------------", 1);
	while (length_a || length_b)
	{
		ft_putstr_fd("|\t", 1);
		if (length_a && data->array_a)
			ft_putnbr_fd(data->array_a[++i], 1);
		ft_putstr_fd("\t|", 1);
		ft_putstr_fd("\t\t|\t ", 1);
		if (length_b && data->array_b)
			ft_putnbr_fd(data->array_b[++j], 1);
		ft_putstr_fd("\t|", 1);
		ft_putendl_fd("----------------\t\t----------------", 1);
		if (length_a)
			length_a--;
		if (length_b)
			length_b--;
	}
}
