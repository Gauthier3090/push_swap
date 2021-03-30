/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 22:03:55 by gpladet           #+#    #+#             */
/*   Updated: 2021/03/25 15:22:27 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_checker/header.h"

t_stack	*free_stack(t_stack *stack)
{
	t_stack	*element;

	if (!stack)
		return (NULL);
	element = stack->next;
	free(stack);
	return (free_stack(element));
}

t_stack	*push_stack(t_stack *stack, int value)
{
	t_stack	*element;

	element = ft_calloc(1, sizeof(t_stack));
	if (!element)
		error_message(ERROR_CALLOC);
	element->value = value;
	element->next = stack;
	return (element);
}

t_stack	*pop_stack(t_stack *stack)
{
	t_stack	*element;

	element = stack->next;
	free(stack);
	return (element);
}

void	print_stack(t_stack *stack)
{
	while (stack->next)
	{
		ft_putnbr_fd(stack->value, 1);
		ft_putchar_fd('\n', 1);
		stack = stack->next;
	}
}

int	ft_strlen_stack(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}
