/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 22:11:21 by gpladet           #+#    #+#             */
/*   Updated: 2021/05/07 22:25:22 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_swap/header.h"

void	display_list_prev(t_double_linked_list *list)
{
	int							i;
	t_double_linked_list_node	*tmp;

	tmp = list->current;
	i = 0;
	while (i < list->count)
	{
		ft_putnbr_fd(tmp->value, 1);
		ft_putchar_fd('\n', 1);
		tmp = tmp->prev;
		i++;
	}
}

void	display_list_next(t_double_linked_list *list)
{
	int							i;
	t_double_linked_list_node	*tmp;

	tmp = list->current;
	i = 0;
	while (i < list->count)
	{
		ft_putnbr_fd(tmp->value, 1);
		ft_putchar_fd('\n', 1);
		tmp = tmp->next;
		i++;
	}
}
