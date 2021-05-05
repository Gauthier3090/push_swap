/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 17:51:59 by gpladet           #+#    #+#             */
/*   Updated: 2021/05/06 01:28:58 by gpladet          ###   ########.fr       */
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
	if (list->count == 0)
	{
		list->current = new_node;
		new_node->prev = list->current;
		new_node->next = list->current;
	}
	else
	{
		new_node->prev = list->current;
		new_node->next = list->current->prev;
		list->current = new_node;
	}
	list->count++;
}

void	free_list(t_double_linked_list *list)
{
	t_double_linked_list	*tmp;

	tmp = list;
	while (tmp->current)
	{
		tmp->current = list->current->next;
		free(list->current);
		list->current = NULL;
	}
	free(list);
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
		printf("%d\n", list->current->value);
		printf("%d\n", list->current->next->next->next->value);
		printf("%d\n", list->current->prev->value);
		printf("%d\n", list->current->prev->prev->prev->value);
		free_list(list);
		free(node);
	}
}
