/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 14:43:25 by gpladet           #+#    #+#             */
/*   Updated: 2021/04/20 16:36:19 by gpladet          ###   ########.fr       */
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
	int		tmp;

	element = stack;
	sorted = FALSE;
	tmp = size;
	while (!sorted)
	{
		stack = element;
		size = tmp;
		sorted = TRUE;
		while (--size)
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

void	bubble_sort_stack(t_stack *stack)
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

int	get_index_median(int size)
{
	return (size / 2);
}

int	get_value_median(t_stack *stack, int index_median)
{
	while (index_median)
	{
		stack = stack->next;
		index_median--;
	}
	return (stack->value);
}

void	push_stack_median_a(t_stack **a, t_stack **b, int median)
{
	int	size;

	size = ft_strlen_stack(*a) + 1;
	while (--size)
	{
		if ((*a)->value < median)
		{
			ft_push(b, a);
			ft_putendl_fd("pb", 1);
		}
		else
		{
			ft_rotate(*a);
			ft_putendl_fd("ra", 1);
		}
	}
}

void	reverse_rotate_stack_b(t_stack *b, int reverse)
{
	while (--reverse)
	{
		ft_reverse_rotate(b);
		ft_putendl_fd("rrb", 1);
	}
}

void	sort_median_stack_b(t_stack **a, t_stack **b, int size, int median)
{
	int	reverse;

	reverse = 0;
	while (--size)
	{
		if ((*b)->value > median)
		{
			ft_push(a, b);
			ft_putendl_fd("pa", 1);
		}
		else
		{
			ft_rotate(*b);
			ft_putendl_fd("rb", 1);
			reverse++;
		}
	}
	reverse_rotate_stack_b(*b, reverse + 1);
}

void	sort_stack_b(t_stack **a, t_stack **b)
{
	t_stack	*element;
	int		index;
	int		median;

	while (ft_strlen_stack(*b))
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
			ft_push(a, b);
			ft_putendl_fd("pa", 1);
			ft_putendl_fd("pa", 1);
		}
		else
		{
			element = duplicate_stack(*b);
			bubble_sort_stack(element);
			index = get_index_median(ft_strlen_stack(element));
			median = get_value_median(element, index);
			sort_median_stack_b(a, b, ft_strlen_stack(*b) + 1, median);
			element = free_stack(element);
		}
	}
}

void	push_stack_median_b(t_stack **a, t_stack **b, t_stack *tab_median)
{
	t_stack	*tmp;
	t_stack	*element;
	int		index;
	int		median;

	while (tab_median)
	{
		if (tab_median->value == 1)
		{
			ft_push(a, b);
			ft_putendl_fd("pa", 1);
		}
		else if (tab_median->value == 2)
		{
			if ((*b)->value < (*b)->next->value)
			{
				ft_swap(*b);
				ft_putendl_fd("sb", 1);
			}
			ft_push(a, b);
			ft_push(a, b);
			ft_putendl_fd("pa", 1);
			ft_putendl_fd("pa", 1);
		}
		else
		{
			tmp = duplicate_stack(*b);
			element = duplicate_stack(tmp);
			bubble_sort(element, tab_median->value);
			index = get_index_median(tab_median->value);
			median = get_value_median(element, index);
			sort_median_stack_b(a, b, tab_median->value + 1, median);
			tmp = free_stack(tmp);
			element = free_stack(element);
		}
		tab_median = tab_median->next;
	}
	if (*b)
		sort_stack_b(a, b);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	t_stack	*element;
	int		index;
	int		median;
	t_stack	*tab_median;

	if (sorted_stack(*a))
		return ;
	tab_median = NULL;
	while (ft_strlen_stack(*a) != 2)
	{
		element = duplicate_stack(*a);
		bubble_sort_stack(element);
		index = get_index_median(ft_strlen_stack(element));
		median = get_value_median(element, index);
		tab_median = push_stack(tab_median, index);
		push_stack_median_a(a, b, median);
		element = free_stack(element);
	}
	if ((*a)->value > (*a)->next->value)
	{
		ft_swap(*a);
		ft_putendl_fd("sa", 1);
	}
	push_stack_median_b(a, b, tab_median);
	tab_median = free_stack(tab_median);
}
