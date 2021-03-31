/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 21:18:34 by gpladet           #+#    #+#             */
/*   Updated: 2021/03/31 16:40:08 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_checker/header.h"

void	ft_swap(t_stack *stack)
{
	int		tmp;

	if (!stack || ft_strlen_stack(stack) <= 1)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
}

void	ft_push(t_stack **dest, t_stack **src)
{
	if (!*src)
		return ;
	*dest = push_stack(*dest, (*src)->value);
	*src = pop_stack(*src);
}

void	ft_rotate(t_stack *stack)
{
	int	tmp;

	if (!stack || ft_strlen_stack(stack) <= 1)
		return ;
	tmp = stack->value;
	while (stack->next)
	{
		stack->value = stack->next->value;
		stack = stack->next;
	}
	stack->value = tmp;
}

void	ft_reverse_rotate(t_stack *stack)
{
	t_stack	*element;
	t_stack	*stack_size;
	int		*tmp;
	int		i;
	int		size;

	if (!stack || ft_strlen_stack(stack) <= 1)
		return ;
	if (ft_strlen_stack(stack) == 2)
	{
		ft_swap(stack);
		return ;
	}
	if (!(tmp = ft_calloc(ft_strlen_stack(stack), sizeof(int))))
		exit(EXIT_FAILURE);
	i = -1;
	tmp[++i] = stack->value;
	element = stack->next;
	stack_size = element->next;
	while (element->next)
	{
		tmp[++i] = element->value;
		element = element->next;
	}
	tmp[++i] = element->value;
	stack->value = tmp[i];
	size = ft_strlen_stack(stack_size);
	stack = stack->next;
	i = -1;
	while (++i < size)
	{
		stack->value = tmp[i];
		stack = stack->next;
	}
	stack->value = tmp[i];
	free(tmp);
}
