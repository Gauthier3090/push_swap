/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 22:09:08 by gpladet           #+#    #+#             */
/*   Updated: 2021/05/08 15:30:46 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_swap/header.h"

t_double_linked_list	*new_list(void)
{
	t_double_linked_list	*list;

	list = ft_calloc(1, sizeof(t_double_linked_list));
	if (!list)
		exit(EXIT_FAILURE);
	return (list);
}

t_double_linked_list_node	*new_node(char *value)
{
	t_double_linked_list_node	*new_node;

	new_node = ft_calloc(1, sizeof(t_double_linked_list_node));
	if (!new_node)
		exit(EXIT_FAILURE);
	new_node->value = ft_atoi(value);
	return (new_node);
}

void	insert(t_double_linked_list *list, t_double_linked_list_node *new_node)
{
	t_double_linked_list_node	*tmp_next;
	t_double_linked_list_node	*tmp_prev;

	if (list->count == 0)
	{
		list->current = new_node;
		list->current->prev = new_node;
		list->current->next = new_node;
	}
	else
	{
		tmp_next = list->current;
		tmp_prev = list->current->prev;
		new_node->prev = tmp_prev;
		new_node->next = tmp_next;
		tmp_next->prev = new_node;
		tmp_prev->next = new_node;
		list->current = new_node;
	}
	list->count++;
}

t_double_linked_list_node	*remove_first(t_double_linked_list *list)
{
	t_double_linked_list_node	*tmp;

	if (list->count == 0)
		return (NULL);
	else if (list->count == 1)
	{
		list->count--;
		return (list->current);
	}
	else
	{
		tmp = list->current;
		list->current->prev->prev = tmp->next;
		list->current->prev->next = tmp->next;
		list->current = tmp->next;
		list->current->prev = tmp->prev;
		tmp->prev = tmp;
		tmp->next = tmp;
		list->count--;
		return (tmp);
	}
}

void	free_list(t_double_linked_list *list)
{
	int							i;
	t_double_linked_list_node	*tmp;
	t_double_linked_list_node	*to_free;

	i = 0;
	tmp = list->current;
	while (i < list->count)
	{
		to_free = tmp;
		tmp = tmp->next;
		free(to_free);
		i++;
	}
	free(list);
}
