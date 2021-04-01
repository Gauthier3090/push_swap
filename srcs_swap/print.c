/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 21:12:48 by gpladet           #+#    #+#             */
/*   Updated: 2021/04/01 17:50:20 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_checker/header.h"

void	error_message(char *message)
{
	ft_putstr_fd("Error: ", 1);
	ft_putendl_fd(message, 1);
	exit(EXIT_FAILURE);
}

void	display_stack(t_stack *a, t_stack *b)
{
	ft_putendl_fd("     PILE A\t\t\t      PILE B", 1);
	ft_putendl_fd("----------------\t\t-----------------", 1);
	while (a || b)
	{
		ft_putstr_fd("|\t", 1);
		if (a)
			ft_putnbr_fd(a->value, 1);
		ft_putstr_fd("\t|", 1);
		ft_putstr_fd("\t\t|\t ", 1);
		if (b)
			ft_putnbr_fd(b->value, 1);
		ft_putstr_fd("\t|", 1);
		ft_putendl_fd("----------------\t\t----------------", 1);
		if (a)
			a = a->next;
		if (b)
			b = b->next;
	}
}

void	display_tab_int(int *tab)
{
	int	i;
	int	size;

	i = -1;
	size = sizeof(*tab) / sizeof(tab[0]);
	while (++i < size)
	{
		ft_putnbr_fd(tab[i], 1);
		ft_putchar_fd(' ', 1);
	}
}