/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 14:28:41 by gpladet           #+#    #+#             */
/*   Updated: 2021/05/15 00:00:25 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_swap/header.h"

int	sorted_list(t_double_linked_list *list_a, t_double_linked_list *list_b)
{
	t_double_linked_list_node	*tmp;
	int							i;

	if (list_b->count != 0)
		return (FALSE);
	tmp = list_a->current->next;
	i = 0;
	while (i < list_a->count)
	{
		if (list_a->current->value > tmp->value)
			return (FALSE);
		i += 1;
		tmp = tmp->next;
	}
	return (TRUE);
}

int	get_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	get_min_value(t_double_linked_list_node *node, int length)
{
	int							min;
	int							i;
	t_double_linked_list_node	*tmp;

	tmp = node;
	min = INT_MAX;
	i = 0;
	while (i < length)
	{
		if (min > tmp->value)
			min = tmp->value;
		tmp = tmp->next;
		i += 1;
	}
	return (min);
}

int	get_max_value(t_double_linked_list_node *node, int length)
{
	int							max;
	int							i;
	t_double_linked_list_node	*tmp;

	tmp = node;
	max = INT_MIN;
	i = 0;
	while (i < length)
	{
		if (max < tmp->value)
			max = tmp->value;
		tmp = tmp->next;
		i += 1;
	}
	return (max);
}

void	sort_list(t_double_linked_list *list_a, t_double_linked_list *list_b)
{
	if (!sorted_list(list_a, list_b))
	{
		if (list_a->count <= 5)
			solve_5_or_less(list_a, list_b);
		else if (list_a->count <= 100)
			solve_100_or_less(list_a, list_b);
		else if (list_a->count > 100)
			solve_others(list_a, list_b);
	}
	free_list(list_a);
	free_list(list_b);
}
