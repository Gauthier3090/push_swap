/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 21:18:34 by gpladet           #+#    #+#             */
/*   Updated: 2021/03/24 15:42:52 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

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
	while (stack->next)
	{
		tmp = stack->value;
		stack->value = stack->next->value;
		stack->next->value = tmp;
		stack = stack->next;
	}
}

void	ft_reverse_rotate(t_stack *stack)
{
	int	i;
	int	tmp;

	if (!stack || ft_strlen_stack(stack) <= 1)
		return ;
	i = ft_strlen_stack(stack) - 1;
	tmp = stack[i].value;
	while (i > 0)
	{
		ft_putnbr_fd(stack[i].value, 1);
		ft_putnbr_fd(tmp, 1);
		stack[i].value = stack[i - 1].value;
		i--;
	}
	stack[i].value = tmp;
}
