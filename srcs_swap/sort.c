/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:47:08 by gpladet           #+#    #+#             */
/*   Updated: 2021/05/12 14:50:43 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_swap/header.h"

int	get_position_min(t_double_linked_list *list, int length)
{
	int							min;
	int							i;
	t_double_linked_list_node	*tmp;

	tmp = list->current;
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

void	execute_operations(t_double_linked_list *list,
			int pos_left, int pos_right, int min)
{
	if (pos_left == 0 && pos_right == 0)
		return ;
	if (pos_left > pos_right)
	{
		while (pos_right)
		{
			if (list->current->value != min)
			{
				rotate(list);
				ft_putendl_fd("ra", 1);
			}
			pos_right -= 1;
		}
	}
	else
	{
		while (pos_left)
		{
			reverse_rotate(list);
			ft_putendl_fd("rra", 1);
			pos_left -= 1;
		}
	}
}

void	operations(t_double_linked_list *list, int min)
{
	int							position_left;
	int							position_right;
	t_double_linked_list_node	*tmp_next;
	t_double_linked_list_node	*tmp_prev;

	tmp_prev = list->current;
	tmp_next = list->current;
	position_right = 0;
	while (tmp_next->value != min)
	{
		position_right += 1;
		tmp_next = tmp_next->next;
	}
	position_left = 0;
	while (tmp_prev->value != min)
	{
		position_left += 1;
		tmp_prev = tmp_prev->prev;
	}
	execute_operations(list, position_left, position_right, min);
}

void	sort_list(t_double_linked_list *list_a, t_double_linked_list *list_b)
{
	int	position;

	if (list_a->count >= 20)
	{
		sort_list_chunk(list_a, list_b);
		return ;
	}
	while (list_a->count != 2)
	{
		position = get_position_min(list_a, list_a->count);
		operations(list_a, position);
		push(list_a, list_b);
		ft_putendl_fd("pb", 1);
	}
	if (list_a->current->value > list_a->current->next->value)
	{
		swap(list_a);
		ft_putendl_fd("sa", 1);
	}
	while (list_b->count)
	{
		push(list_b, list_a);
		ft_putendl_fd("pa", 1);
	}
	free_list(list_a);
	free_list(list_b);
}
