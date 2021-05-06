/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 17:51:59 by gpladet           #+#    #+#             */
/*   Updated: 2021/05/06 17:16:39 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_swap/header.h"

void	error_message(char *message)
{
	ft_putendl_fd(message, 1);
	exit(EXIT_FAILURE);
}

t_double_linked_list	*new_list(void)
{
	t_double_linked_list	*list;

	list = ft_calloc(1, sizeof(t_double_linked_list));
	if (!list)
		error_message(ERROR_CALLOC);
	return (list);
}

t_double_linked_list_node	*new_node(char *value)
{
	t_double_linked_list_node	*new_node;

	new_node = ft_calloc(1, sizeof(t_double_linked_list_node));
	if (!new_node)
		error_message(ERROR_CALLOC);
	new_node->value = ft_atoi(value);
	return (new_node);
}

void	insert(t_double_linked_list *list, t_double_linked_list_node *new_node)
{
	int	i;

	if (list->count == 0)
		list->current = new_node;
	else if (list->count == 1)
	{
		new_node->prev = list->current;
		new_node->next = list->current;
		list->current->prev = new_node;
		list->current->next = new_node;
		list->current = new_node;
	}
	else
	{
		new_node->prev = list->current;
		list->current->next = new_node;
		i = -1;
		while (++i < list->count -1)
			list->current = list->current->prev;
		new_node->next = list->current;
		list->current->prev = new_node;
		list->current = new_node;
	}
	list->count++;
}

void	free_list(t_double_linked_list *list)
{
	int	i;

	i = -1;
	while (++i < list->count - 1)
	{
		list->current = list->current->next;
		free(list->current->prev);
	}
	free(list->current);
	free(list);
}

void 	display_list(t_double_linked_list *list)
{
	int	i;

	i = -1;
	while (++i < list->count)
	{
		ft_putnbr_fd(list->current->value, 1);
		ft_putchar_fd('\n', 1);
		list->current = list->current->prev;
	}
}

int	main(int argc, char **argv)
{
	t_double_linked_list		*list;
	t_double_linked_list_node	*node;
	int							i;

	if (argc > 1)
	{
		node = NULL;
		list = new_list();
		i = 0;
		while (argv[++i])
		{
			node = new_node(argv[i]);
			insert(list, node);
		}
		display_list(list);
		free_list(list);
	}
}
