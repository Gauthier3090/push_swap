/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 21:18:34 by gpladet           #+#    #+#             */
/*   Updated: 2021/03/16 00:27:46 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		ft_swap_value(t_stack *stack)
{
	stack = stack->next;
	return (stack->value);
}

t_stack	*ft_swap(t_stack *stack)
{
	int		tmp;

	if (!stack || ft_strlen_stack(stack) == 1)
		return ;
	tmp = stack->value;
	stack->value = ft_swap_value(stack);
	stack = stack->next;
	stack->value = tmp;
	return (stack);
}

void	ft_push(t_stack **dest, t_stack **src)
{
	if (!*src)
		return ;
	*dest = push_stack(*dest, (*src)->value);
	*src = pop_stack(*src);
}
