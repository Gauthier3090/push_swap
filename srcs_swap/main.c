/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 17:51:59 by gpladet           #+#    #+#             */
/*   Updated: 2021/05/07 17:08:28 by gpladet          ###   ########.fr       */
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
	t_double_linked_list_node	*tmp_next;
	t_double_linked_list_node	*tmp_prev;

	if (list->count == 0)
	{
		list->current = new_node;
		list->current->prev = new_node;
		list->current->next = new_node;
	}
	/*else if (list->count == 1)
	{
		new_node->prev = list->current;
		new_node->next = list->current;
		list->current->prev = new_node;
		list->current->next = new_node;
		list->current = new_node;
	}*/
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

/*void	insert(t_double_linked_list *list, t_double_linked_list_node *new_node)
{
	int	i;

	if (list->count == 0)
	{
		list->current = new_node;
		list->current->prev = new_node;
		list->current->next = new_node;
	}
	else if (list->count == 1)
	{
		new_node->prev = list->current;
		new_node->next = list->current;
		list->current->prev = new_node;
		list->current = new_node;
	}
	else
	{
		new_node->prev = list->current;
		list->current->next = new_node;
		i = -1;
		while (++i < list->count - 1)
			list->current = list->current->prev;
		new_node->next = list->current;
		list->current->prev = new_node;
		list->current = new_node;
	}
	list->count++;
}*/

void	swap(t_double_linked_list *list)
{
	int	value;

	if (list->count == 1)
		return ;
	value = list->current->value;
	list->current->value = list->current->prev->value;
	list->current->prev->value = value;
}

void	rotate(t_double_linked_list *list)
{
	list->current = list->current->prev;
}

void	reverse_rotate(t_double_linked_list *list)
{
	list->current = list->current->next;
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

void	display_list_prev(t_double_linked_list *list)
{
	int							i;
	t_double_linked_list_node	*tmp;

	i = -1;
	tmp = list->current;
	while (++i < list->count)
	{
		ft_putnbr_fd(tmp->value, 1);
		ft_putchar_fd('\n', 1);
		tmp = tmp->prev;
	}
}

void	display_list_next(t_double_linked_list *list)
{
	int							i;
	t_double_linked_list_node	*tmp;

	i = -1;
	tmp = list->current;
	while (++i < list->count)
	{
		ft_putnbr_fd(tmp->value, 1);
		ft_putchar_fd('\n', 1);
		tmp = tmp->next;
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
			ft_putchar_fd('\n', 1);
			display_list_next(list);
		}
		display_list_prev(list);
		ft_putchar_fd('\n', 1);
		display_list_next(list);
		//free_list(list);
	}
}
