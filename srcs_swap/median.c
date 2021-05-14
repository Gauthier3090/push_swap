/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 21:20:52 by gpladet           #+#    #+#             */
/*   Updated: 2021/05/14 21:31:27 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_swap/header.h"

void	sort_array(long *array, int len)
{
	long	tmp;
	int		i;

	tmp = 0;
	i = 0;
	while (i < len - 1)
	{
		if (array[i] <= array[i + 1])
			i++;
		else
		{
			tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
			i = 0;
		}
	}
}

int	find_median(t_double_linked_list *list_a, int div_median)
{
	long						*array;
	int							i;
	int							median;
	t_double_linked_list_node	*tmp;

	array = (long *)ft_calloc((list_a->count + 1), sizeof(long));
	if (!array)
		exit(EXIT_FAILURE);
	i = 0;
	tmp = list_a->current;
	while (i < list_a->count)
	{
		array[i] = tmp->value;
		tmp = tmp->next;
		i += 1;
	}
	sort_array(array, list_a->count);
	median = array[list_a->count / div_median];
	free(array);
	return (median);
}
