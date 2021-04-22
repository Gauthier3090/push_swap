/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 14:06:08 by gpladet           #+#    #+#             */
/*   Updated: 2021/04/22 16:44:22 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_swap/header.h"

int	is_sorted(int *array, int size)
{
	int	i;

	i = -1;
	while (++i < size - 1)
	{
		if (array[i] > array[i + 1])
			return (FALSE);
	}
	return (TRUE);
}

void	bubble_sort(int	*array, int size)
{
	int	sorted;
	int	tmp;
	int	i;

	sorted = FALSE;
	while (!sorted)
	{
		sorted = TRUE;
		i = -1;
		while (++i < size - 1)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				sorted = FALSE;
			}
		}
	}
}

int		get_index_median(int size)
{
	return (size / 2);
}

int		get_value_median(int *array, int index_median)
{
	int	i;

	i = 0;
	while (index_median)
	{
		i++;
		index_median--;
	}
	return (array[i]);
}

void	push_stack_median_a(t_data *data, int median)
{
	int	size;
	int	i;

	size = data->length_a - 1;
	i = -1;
	while (++i < size)
	{
		if (data->array_a[0] < median)
		{
			ft_push(&(data->array_b), &(data->array_a), &(data->length_b), &(data->length_a));
			ft_putendl_fd("pb", 1);
		}
		else
		{
			ft_rotate(data->array_a, data->length_a);
			ft_putendl_fd("ra", 1);
		}
	}
}

void	sort_array(t_data *data)
{
	int	*copy;
	int	*tab_median;
	int	index;
	int	median;
	int	size;

	if (is_sorted(data->array_a, data->length_a))
		return ;
	size = 0;
	tab_median = NULL;
	while (data->length_a != 2)
	{
		copy = copy_tab(data->array_a, data->length_a);
		bubble_sort(copy, data->length_a);
		index = get_index_median(data->length_a);
		median = get_value_median(copy, index);
		tab_median = push_array(tab_median, &size, median);
		push_stack_median_a(data, median);
		free(copy);
	}
	if (data->array_a[0] > data->array_a[1])
	{
		ft_swap(data->array_a, data->length_a);
		ft_putendl_fd("sa", 1);
	}
	free(tab_median);
}
