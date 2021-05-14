/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 14:28:41 by gpladet           #+#    #+#             */
/*   Updated: 2021/05/14 17:14:07 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_swap/header.h"

void	find_position(t_double_linked_list *list_b, t_double_linked_list_node *node)
{
	int	max;
	int	min;

	min = get_min_value(list_b->current, list_b->count);
	max = get_max_value(list_b->current, list_b->count);
	if (node->value > max)
	{
		printf("NEW MAX\n");
		while (list_b->current->prev->value != max)
			reverse_or_rotate(list_b, max, FALSE);
	}
	else if (node->value < min)
	{
		printf("NEW MIN\n");
		while (list_b->current->value != min)
			reverse_or_rotate(list_b, min, FALSE);
	}
	else
	{
		printf("OTHER\n");
		printf("## %d\n", list_b->current->value);
		printf("## %d\n", node->value);
		while (list_b->current->value < node->value)
		{
			rotate_b(list_b);
			printf("## %d\n", list_b->current->value);
		}
	}
}

void	insert_sort(t_double_linked_list *list_b, t_double_linked_list *list_a)
{
	printf("\n");
	display_lists(list_a, list_b);
	printf("NODE A : %d\n", list_a->current->value);
	if (list_b->count == 0)
		push_b(list_a, list_b);
	else if (list_b->count == 1)
	{
		push_b(list_a, list_b);
		if (list_b->current->value > list_b->current->next->value)
			swap_b(list_b);
	}
	else
	{
		find_position(list_b, list_a->current);
		push_b(list_a, list_b);
	}
}

void	reset_list_b(t_double_linked_list *list_b)
{
	int	min;

	min = get_min_value(list_b->current, list_b->count);
	while (list_b->current->value != min)
		reverse_or_rotate(list_b, min, FALSE);
}

void	sort_insert_chunk(t_double_linked_list *list_a, t_double_linked_list *list_b)
{
	t_chunk	chunk;
	int		min;	

	chunk.head = list_a->current;
	chunk.remaining = get_min(CHUNK, list_a->count);
	while (chunk.remaining)
	{
		min = get_min_value(chunk.head, chunk.remaining);
		reverse_or_rotate(list_a, min, TRUE);
		if (chunk.head == list_a->current)
			chunk.head = chunk.head->next;
		chunk.remaining -= 1;
		insert_sort(list_b, list_a);
	}
	reset_list_b(list_b);
}

void	sort_list(t_double_linked_list *list_a, t_double_linked_list *list_b)
{
	sort_insert_chunk(list_a, list_b);
	//while (list_a->count)
		//insert_sort(list_b, list_a);
	printf("\n");
	display_lists(list_a, list_b);
	free_list(list_a);
	free_list(list_b);
}
