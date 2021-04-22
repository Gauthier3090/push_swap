/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 14:06:08 by gpladet           #+#    #+#             */
/*   Updated: 2021/04/22 19:12:02 by gpladet          ###   ########.fr       */
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

void	bubble_sort_value(int *array, int value)
{
	int	sorted;
	int	tmp;
	int	size;
	int	i;

	sorted = FALSE;
	size = value;
	while (!sorted)
	{
		sorted = TRUE;
		value = size;
		i = -1;
		while (--value)
		{
			++i;
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

void	sort_median_stack_b(t_data *data, int size, int median)
{
	while (--size)
	{
		if (data->array_b[0] > median)
		{
			ft_push(&(data->array_a), &(data->array_b), &(data->length_a), &(data->length_b));
			ft_putendl_fd("pa", 1);
		}
		else
		{
			ft_rotate(data->array_b, data->length_b);
			ft_putendl_fd("rb", 1);
		}
	}
}

void	sort_stack_b(t_data *data)
{
	int	*copy;
	int	index;
	int	median;

	while (data->length_b)
	{
		if (data->length_b == 1)
		{
			ft_push(&(data->array_a), &(data->array_b), &(data->length_a), &(data->length_b));
			ft_putendl_fd("pa", 1);
		}
		else if (data->length_b == 2)
		{
			if (data->array_b[0] < data->array_b[1])
			{
				ft_swap(data->array_b, data->length_b);
				ft_putendl_fd("sb", 1);
			}
			ft_push(&(data->array_a), &(data->array_b), &(data->length_a), &(data->length_b));
			ft_push(&(data->array_a), &(data->array_b), &(data->length_a), &(data->length_b));
			ft_putendl_fd("pa", 1);
			ft_putendl_fd("pa", 1);
		}
		else
		{
			copy = copy_tab(data->array_b, data->length_b);
			bubble_sort(copy, data->length_b);
			index = get_index_median(data->length_b);
			median = get_value_median(copy, index);
			sort_median_stack_b(data, data->length_b + 1, median);
			free(copy);
		}
	}
}

void	push_stack_median_b(t_data *data, int *tab_median, int size)
{
	int	i;
	int	*copy;
	int	index;
	int	median;

	i = -1;
	while (size)
	{
		i++;
		if (tab_median[i] == 1)
		{
			ft_push(&(data->array_a), &(data->array_b), &(data->length_a), &(data->length_b));
			ft_putendl_fd("pa", 1);
		}
		else if (tab_median[i] == 2)
		{
			if (data->array_b[0] < data->array_b[1])
			{
				ft_swap(data->array_b, data->length_b);
				ft_putendl_fd("sb", 1);
			}
			ft_push(&(data->array_a), &(data->array_b), &(data->length_a), &(data->length_b));
			ft_push(&(data->array_a), &(data->array_b), &(data->length_a), &(data->length_b));
			ft_putendl_fd("pa", 1);
			ft_putendl_fd("pa", 1);
		}
		else
		{
			copy = copy_tab(data->array_b, data->length_b);
			bubble_sort_value(copy, tab_median[i] - 1);
			index = get_index_median(tab_median[i]);
			median = get_value_median(copy, index);
			sort_median_stack_b(data, tab_median[i] + 1, median);
			free(copy);
		}
		size--;
	}
	if (data->length_b)
		sort_stack_b(data);
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
		tab_median = push_array(tab_median, &size, index);
		push_stack_median_a(data, median);
		free(copy);
	}
	if (data->array_a[0] > data->array_a[1])
	{
		ft_swap(data->array_a, data->length_a);
		ft_putendl_fd("sa", 1);
	}
	push_stack_median_b(data, tab_median, size);
	free(tab_median);
}
