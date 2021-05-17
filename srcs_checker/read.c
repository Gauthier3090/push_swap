/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:59:36 by gpladet           #+#    #+#             */
/*   Updated: 2021/05/15 11:33:14 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_checker/header.h"

int	getinput(char **line)
{
	int		ret;
	int		i;
	int		count;
	char	buffer;

	buffer = 0;
	*line = ft_calloc(2, sizeof(char));
	if (!(*line))
		exit(EXIT_FAILURE);
	i = -1;
	count = 1;
	ret = 0;
	while (ret > -1 && buffer != '\n')
	{
		ret = read(0, &buffer, 1);
		if (ret == 0)
			return (0);
		if (ret != 0 && buffer != 0 && buffer != '\n')
		{
			(*line)[++i] = buffer;
			count++;
			*line = ft_realloc(*line, count + 1);
		}
	}
	return (1);
}

int	list_operations_more(char *line, t_double_linked_list *list_a,
		t_double_linked_list *list_b)
{
	if (!ft_strcmp("rr", line))
	{
		rotate(list_a);
		rotate(list_b);
		return (TRUE);
	}
	else if (!ft_strcmp("rra", line))
	{
		reverse_rotate(list_a);
		return (TRUE);
	}
	else if (!ft_strcmp("rrb", line))
	{
		reverse_rotate(list_b);
		return (TRUE);
	}
	else if (!ft_strcmp("rrr", line))
	{
		reverse_rotate(list_a);
		reverse_rotate(list_b);
		return (TRUE);
	}
	return (FALSE);
}

int	list_operations(char *line, t_double_linked_list *list_a,
		t_double_linked_list *list_b)
{
	if (!ft_strcmp("sa", line))
		swap(list_a);
	else if (!ft_strcmp("sb", line))
		swap(list_b);
	else if (!ft_strcmp("ss", line))
	{
		swap(list_a);
		swap(list_b);
	}
	else if (!ft_strcmp("pa", line))
		push(list_b, list_a);
	else if (!ft_strcmp("pb", line))
		push(list_a, list_b);
	else if (!ft_strcmp("ra", line))
		rotate(list_a);
	else if (!ft_strcmp("rb", line))
		rotate(list_b);
	else if (list_operations_more(line, list_a, list_b))
		return (TRUE);
	else
		return (FALSE);
	return (TRUE);
}

int	sorted_list(t_double_linked_list *list_a, t_double_linked_list *list_b)
{
	t_double_linked_list_node	*tmp;
	int							i;

	if (list_b->count != 0)
	{
		ft_putendl_fd("KO", 1);
		return (FALSE);
	}
	tmp = list_a->current;
	i = 0;
	while (i < list_a->count - 1)
	{
		if (tmp->value > tmp->next->value)
		{
			ft_putendl_fd("KO", 1);
			return (FALSE);
		}
		i += 1;
		tmp = tmp->next;
	}
	ft_putendl_fd("OK", 1);
	return (TRUE);
}
