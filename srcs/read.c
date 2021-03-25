/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:59:36 by gpladet           #+#    #+#             */
/*   Updated: 2021/03/25 15:02:23 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	getinput(char **line)
{
	int		ret;
	int		i;
	int		count;
	char	buffer;

	buffer = 0;
	*line = ft_calloc(2, sizeof(char));
	if (!(*line))
		error_message(ERROR_CALLOC);
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

int	ft_operations_more(char *line, t_stack **a, t_stack **b)
{
	if (!(ft_strcmp("rr", line)))
	{
		ft_rotate(*a);
		ft_rotate(*b);
		return (TRUE);
	}
	else if (!(ft_strcmp("rra", line)))
	{
		ft_reverse_rotate(*a);
		return (TRUE);
	}
	else if (!(ft_strcmp("rrb", line)))
	{
		ft_reverse_rotate(*b);
		return (TRUE);
	}
	else if (!(ft_strcmp("rrr", line)))
	{
		ft_reverse_rotate(*a);
		ft_reverse_rotate(*b);
		return (TRUE);
	}
	return (FALSE);
}

int	ft_operations(char *line, t_stack **a, t_stack **b)
{
	if (!ft_strcmp("sa", line))
		ft_swap(*a);
	else if (!ft_strcmp("sb", line))
		ft_swap(*b);
	else if (!ft_strcmp("ss", line))
	{
		ft_swap(*a);
		ft_swap(*b);
	}
	else if (!ft_strcmp("pa", line))
		ft_push(a, b);
	else if (!ft_strcmp("pb", line))
		ft_push(b, a);
	else if (!(ft_strcmp("ra", line)))
		ft_rotate(*a);
	else if (!(ft_strcmp("rb", line)))
		ft_rotate(*b);
	else if (ft_operations_more(line, a, b))
		return (TRUE);
	else
	{
		ft_putendl_fd("Error", 1);
		return (FALSE);
	}
	return (TRUE);
}
