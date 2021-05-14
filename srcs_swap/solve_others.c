/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_others.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 22:22:06 by gpladet           #+#    #+#             */
/*   Updated: 2021/05/14 23:37:04 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_swap/header.h"

void	solve_quarter_first(int	quarter, t_double_linked_list *list_a,
			t_double_linked_list *list_b)
{
	int	length;
	int	j;
	int	max;

	j = 0;
	length = list_a->count;
	while (j < length)
	{
		if (list_a->current->value > quarter)
			push_b(list_a, list_b);
		else
			rotate_a(list_a);
		j += 1;
	}
	while (list_b->count)
	{
		max = get_max_value(list_b->current, list_b->count);
		reverse_or_rotate(list_b, max, FALSE);
		push_a(list_a, list_b);
	}
}

void	solve_quarter(t_double_linked_list *list_a,
			t_double_linked_list *list_b, int quarter, int quarter2)
{
	int	j;
	int	length;
	int	max;

	length = list_a->count;
	j = 0;
	while (j < length)
	{
		if (list_a->current->value <= quarter
			&& list_a->current->value >= quarter2)
			push_b(list_a, list_b);
		else
			rotate_a(list_a);
		j += 1;
	}
	while (list_b->count)
	{
		max = get_max_value(list_b->current, list_b->count);
		reverse_or_rotate(list_b, max, FALSE);
		push_a(list_a, list_b);
	}
}

void	solve_others(t_double_linked_list *list_a, t_double_linked_list *list_b)
{
	t_quarter	quarter;
	int			length;
	int			i;
	int			max;

	length = list_a->count;
	quarter.first = (find_median(list_a, 2) / 4) * 7;
	quarter.second = (find_median(list_a, 2) / 4) * 5;
	quarter.third = (find_median(list_a, 2) / 4) * 3;
	quarter.four = find_median(list_a, 4) / 2;
	solve_quarter_first(quarter.first, list_a, list_b);
	i = 0;
	while (i < 4)
	{
		if (i == 0)
			solve_quarter(list_a, list_b, quarter.first, quarter.second);
		if (i == 1)
			solve_quarter(list_a, list_b, quarter.second, quarter.third);
		if (i == 2)
			solve_quarter(list_a, list_b, quarter.third, quarter.four);
		if (i == 3)
			solve_quarter(list_a, list_b, quarter.four, INT_MIN);
		i += 1;
	}
}
