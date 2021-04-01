/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 14:43:25 by gpladet           #+#    #+#             */
/*   Updated: 2021/04/01 18:15:36 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_swap/header.h"

int	sorted_stack(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (FALSE);
		stack = stack->next;
	}
	return (TRUE);
}

t_stack	*duplicate_stack(t_stack *src)
{
	t_stack *dest;

	dest = NULL;
	while (src)
	{
		dest = push_stack(dest, src->value);
		src = src->next;
	}
	return (dest);
}

void	bubble_sort(t_stack *stack, int size)
{
	t_stack	*element;
	int		temp;
	int		sorted;

	element = stack;
	sorted = FALSE;
	while (!sorted)
	{
		stack = element;
		sorted = TRUE;
		while (size)
		{
			if (stack->value > stack->next->value)
			{
				temp = stack->value;
				stack->value = stack->next->value;
				stack->next->value = temp;
				sorted = FALSE;
			}
			stack = stack->next;
			size--;
		}
	}
}

int	get_index_median(t_stack *stack)
{
	return (ft_strlen_stack(stack) / 2);
}

int	get_value_median(t_stack *stack, int index_median)
{
	while (--index_median)
		stack = stack->next;
	return (stack->value);
}

void	push_stack_median_a(t_stack **a, t_stack **b, int median)
{
	int	size;

	size = ft_strlen_stack(*a) + 1;
	while (--size)
	{
		if ((*a)->value <= median)
		{
			ft_push(b, a);
			ft_putendl_fd("pb", 1);
		}
		else if ((*a)->value >= median)
		{
			ft_rotate(*a);
			ft_putendl_fd("ra", 1);
		}
	}
}

void	push_stack_median_b(t_stack **a, t_stack **b)
{
	if (ft_strlen_stack(*b) == 1)
	{
		ft_push(a, b);
		ft_putendl_fd("pa", 1);
	}
	else if (ft_strlen_stack(*b) == 2)
	{
		if ((*b)->value < (*b)->next->value)
		{
			ft_rotate(*b);
			ft_putendl_fd("rb", 1);
		}
		ft_push(a, b);
		ft_putendl_fd("pa", 1);
		ft_push(a, b);
		ft_putendl_fd("pa", 1);
	}
}

int	*add_tab(int *tab, int value)
{
	int	size;

	if (!tab)
	{
		tab = ft_calloc(1, sizeof(int));
		if (!tab)
			error_message(ERROR_CALLOC);
		tab[0] = value;
	}
	else
	{
		size = sizeof(*tab) / sizeof(tab[0]);
		tab = ft_realloc(tab, size + 1);
		tab[size + 1] = value;
	}
	return (tab);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	t_stack	*element;
	int		median;
	int		index_median;
	int		*tab_median;

	if (sorted_stack(*a))
		return ;
	tab_median = NULL;
	while (ft_strlen_stack(*a) > 2)
	{
		element = duplicate_stack(*a);
		bubble_sort(element, ft_strlen_stack(element));
		index_median = get_index_median(element);
		median = get_value_median(element, index_median + 1);
		tab_median = add_tab(tab_median, index_median + 1);
		push_stack_median_a(a, b, median);
		element = free_stack(element);
	}
	if (ft_strlen_stack(*a) == 2)
	{
		if ((*a)->value > (*a)->next->value)
		{
			ft_swap(*a);
			ft_putendl_fd("sa", 1);
		}
	}
	push_stack_median_b(a, b);
	display_stack(*a, *b);
}
