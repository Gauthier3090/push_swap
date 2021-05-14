/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 14:28:41 by gpladet           #+#    #+#             */
/*   Updated: 2021/05/14 23:26:18 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_swap/header.h"

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
	if (list_a->count <= 5)
		solve_5_or_less(list_a, list_b);
	else if (list_a->count <= 100)
		solve_100_or_less(list_a, list_b);
	else if (list_a->count > 100)
		solve_others(list_a, list_b);
	free_list(list_a);
	free_list(list_b);
}
