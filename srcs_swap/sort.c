/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 14:28:41 by gpladet           #+#    #+#             */
/*   Updated: 2021/05/14 15:18:57 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_swap/header.h"

void	find_position(t_double_linked_list *list_b, t_double_linked_list_node *node)
{
	int	max;
	int	min;

	min = get_position_min(list_b, list_b->count);
	max = get_position_max(list_b, list_b->count);
	if (node->value > max)
	{
		while (list_b->current->value != max)
			reverse_or_rotate(list_b, max);
	}
	else if (node->value < min)
	{
		while (list_b->current->value != min)
			reverse_or_rotate(list_b, min);
	}
}

void	insert_sort(t_double_linked_list *list_b, t_double_linked_list *list_a)
{
	if (list_b->count == 0)
		push_b(list_a, list_b);
	else if (list_b->count == 1)
	{
		if (list_a->current->value > list_b->current->value)
			push_b(list_a, list_b);
		else
		{
			push_b(list_a, list_b);
			swap_b(list_b);
		}
	}
	else
	{
		find_position(list_b, list_a->current);
		push_b(list_a, list_b);
	}
}

void	reset_list_b(t_double_linked_list *list_b)
{
	int	max;

	max = get_position_max(list_b, list_b->count);
	while (list_b->current->value != max)
		reverse_or_rotate(list_b, max);
}

void	sort_list(t_double_linked_list *list_a, t_double_linked_list *list_b)
{
	insert_sort(list_b, list_a);
	insert_sort(list_b, list_a);
	insert_sort(list_b, list_a);
	reset_list_b(list_b);
	display_lists(list_a, list_b);
	free_list(list_a);
	free_list(list_b);
}
