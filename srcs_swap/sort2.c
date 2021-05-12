/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 14:28:41 by gpladet           #+#    #+#             */
/*   Updated: 2021/05/12 18:46:42 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_swap/header.h"

int	get_position_max(t_double_linked_list *list, int length)
{
	int							max;
	int							i;
	t_double_linked_list_node	*tmp;

	tmp = list->current;
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

void	sort_begin_list(t_double_linked_list *list_a,
			t_double_linked_list *list_b)
{
	int	position;
	int	nb_rotate;
	int	length;

	if (CHUNK > list_a->count)
		length = list_a->count;
	else
		length = CHUNK;
	while (length)
	{
		nb_rotate = 0;
		position = get_position_min(list_a, length);
		while (list_a->current->value != position)
		{
			nb_rotate += 1;
			rotate(list_a);
			ft_putendl_fd("ra", 1);
		}
		push(list_a, list_b);
		ft_putendl_fd("pb", 1);
		while (nb_rotate)
		{
			reverse_rotate(list_a);
			ft_putendl_fd("rra", 1);
			nb_rotate -= 1;
		}
		length -= 1;
	}
}

void	parse_number(t_double_linked_list *list_a, t_double_linked_list *list_b)
{
	int							i;
	int							j;
	int							position_nb;
	t_double_linked_list_node	*tmp;

	while (list_a->count)
	{
		i = 0;
		tmp = list_b->current;
		position_nb = get_position_max(list_b, list_b->count);
		while (i < list_a->current->value)
		{
			j = 0;
			while (j < list_b->count)
			{
				if (i == tmp->value)
					position_nb = tmp->value;
				tmp = tmp->next;
				j += 1;
			}
			i += 1;
		}
		operations(list_b, position_nb);
		push(list_a, list_b);
		ft_putendl_fd("pb", 1);
	}
}

void	sort_list_chunk(t_double_linked_list *list_a,
			t_double_linked_list *list_b)
{
	int	position_max;

	sort_begin_list(list_a, list_b);
	parse_number(list_a, list_b);
	position_max = get_position_max(list_b, list_b->count);
	operations(list_b, position_max);
	while (list_b->count)
	{
		push(list_b, list_a);
		ft_putendl_fd("pa", 1);
	}
	free_list(list_a);
	free_list(list_b);
}
