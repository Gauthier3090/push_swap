/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 14:43:25 by gpladet           #+#    #+#             */
/*   Updated: 2021/04/01 17:00:53 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_checker/header.h"

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

void	bubble_sort(t_stack *stack)
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
		while (stack->next)
		{
			if (stack->value > stack->next->value)
			{
				temp = stack->value;
				stack->value = stack->next->value;
				stack->next->value = temp;
				sorted = FALSE;
			}
			stack = stack->next;
		}
	}
}

int	get_index_median(t_stack *stack)
{
	int	median;

	median = (ft_strlen_stack(stack) / 2) + 1;
	while (--median)
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

void	sort_stack(t_stack **a, t_stack **b)
{
	t_stack	*element;
	int		median;

	if (sorted_stack(*a))
		return ;
	while (ft_strlen_stack(*a) > 2)
	{
		element = duplicate_stack(*a);
		bubble_sort(element);
		median = get_index_median(element);
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
	display_stack(*a, *b);
}
