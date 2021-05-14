/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_5_or_less.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 21:00:18 by gpladet           #+#    #+#             */
/*   Updated: 2021/05/15 00:02:04 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_swap/header.h"

void	solve_2(t_double_linked_list *list_a)
{
	if (list_a->current->value > list_a->current->next->value)
		swap_a(list_a);
}

void	solve_3(t_double_linked_list *list_a)
{
	int	max;

	max = get_max_value(list_a->current, list_a->count);
	while (list_a->current->prev->value != max)
		reverse_rotate_a(list_a);
	if (list_a->current->value > list_a->current->next->value)
		swap_a(list_a);
}

void	solve_4(t_double_linked_list *list_a, t_double_linked_list *list_b)
{
	int	min;

	min = get_min_value(list_a->current, list_a->count);
	reverse_or_rotate(list_a, min, TRUE);
	push_b(list_a, list_b);
	solve_3(list_a);
	push_a(list_a, list_b);
}

void	solve_5(t_double_linked_list *list_a, t_double_linked_list *list_b)
{
	int		median;
	int		length;
	int		i;

	median = find_median(list_a, 2);
	length = list_a->count;
	i = 0;
	while (i < length)
	{
		if (list_a->current->value < median)
			push_b(list_a, list_b);
		else
			rotate_a(list_a);
		i += 1;
	}
	solve_3(list_a);
	if (list_b->current->value < list_b->current->next->value)
		swap_b(list_b);
	push_a(list_a, list_b);
	push_a(list_a, list_b);
}

void	solve_5_or_less(t_double_linked_list *list_a,
			t_double_linked_list *list_b)
{
	if (list_a->count == 2)
		solve_2(list_a);
	else if (list_a->count == 3)
		solve_3(list_a);
	else if (list_a->count == 4)
		solve_4(list_a, list_b);
	else if (list_a->count == 5)
		solve_5(list_a, list_b);
}
