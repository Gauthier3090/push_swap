/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_100_or_less.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 21:54:26 by gpladet           #+#    #+#             */
/*   Updated: 2021/05/14 23:30:22 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_swap/header.h"

void	solve_median_above(t_double_linked_list *list_a,
			t_double_linked_list *list_b, int median, int length)
{
	int	i;
	int	max;

	i = 0;
	while (i < length)
	{
		if (list_a->current->value > median)
			push_b(list_a, list_b);
		else
			rotate_a(list_a);
		i += 1;
	}
	while (list_b->count)
	{
		max = get_max_value(list_b->current, list_b->count);
		reverse_or_rotate(list_b, max, FALSE);
		push_a(list_a, list_b);
	}
}

void	solve_100_or_less(t_double_linked_list *list_a,
			t_double_linked_list *list_b)
{
	int	median;
	int	length;
	int	i;
	int	max;

	median = find_median(list_a, 2);
	length = list_a->count;
	solve_median_above(list_a, list_b, median, length);
	i = 0;
	while (i < length)
	{
		if (list_a->current->value <= median)
			push_b(list_a, list_b);
		else
			rotate_a(list_a);
		i += 1;
	}
	while (list_b->count)
	{
		max = get_max_value(list_b->current, list_b->count);
		reverse_or_rotate(list_b, max, FALSE);
		push_a(list_a, list_b);
	}
}
