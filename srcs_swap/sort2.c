/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:05:00 by gpladet           #+#    #+#             */
/*   Updated: 2021/05/14 23:27:16 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_swap/header.h"

void	execute_operations_b(t_double_linked_list *list_b, int nb_rotate,
			int nb_reverse, int value)
{
	if (nb_rotate == 0 && nb_reverse == 0)
		return ;
	if (nb_reverse > nb_rotate)
	{
		while (nb_rotate)
		{
			if (list_b->current->value != value)
				rotate_b(list_b);
			nb_rotate -= 1;
		}
	}
	else
	{
		while (nb_reverse)
		{
			if (list_b->current->value != value)
				reverse_rotate_b(list_b);
			nb_reverse -= 1;
		}
	}
}

void	execute_operations_a(t_double_linked_list *list_a, int nb_rotate,
			int nb_reverse, int value)
{
	if (nb_rotate == 0 && nb_reverse == 0)
		return ;
	if (nb_reverse > nb_rotate)
	{
		while (nb_rotate)
		{
			if (list_a->current->value != value)
				rotate_a(list_a);
			nb_rotate -= 1;
		}
	}
	else
	{
		while (nb_reverse)
		{
			if (list_a->current->value != value)
				reverse_rotate_a(list_a);
			nb_reverse -= 1;
		}
	}
}

void	reverse_or_rotate(t_double_linked_list *list, int value, int list_a)
{
	int							nb_reverse;
	int							nb_rotate;
	t_double_linked_list_node	*tmp_next;
	t_double_linked_list_node	*tmp_prev;

	tmp_prev = list->current;
	tmp_next = list->current;
	nb_rotate = 0;
	while (tmp_next->value != value)
	{
		nb_rotate += 1;
		tmp_next = tmp_next->next;
	}
	nb_reverse = 0;
	while (tmp_prev->value != value)
	{
		nb_reverse += 1;
		tmp_prev = tmp_prev->prev;
	}
	if (list_a)
		execute_operations_a(list, nb_rotate, nb_reverse, value);
	else
		execute_operations_b(list, nb_rotate, nb_reverse, value);
}
