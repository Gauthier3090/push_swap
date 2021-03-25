/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 21:18:34 by gpladet           #+#    #+#             */
/*   Updated: 2021/03/25 15:22:18 by gpladet          ###   ########.fr       */
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

int	*ft_tab_int(t_stack *stack)
{
	t_stack	*element;
	int		*tab;
	int		i;

	tab = ft_calloc(ft_strlen_stack(stack), sizeof(int));
	if (!tab)
		error_message(ERROR_CALLOC);
	i = -1;
	tab[++i] = stack->value;
	element = stack->next;
	while (element->next)
	{
		tab[++i] = element->value;
		element = element->next;
	}
	tab[++i] = element->value;
	stack->value = tab[i];
	return (tab);
}

void	ft_reverse_rotate(t_stack *stack)
{
	int		*tmp;
	int		i;

	if (!stack || ft_strlen_stack(stack) <= 1)
		return ;
	if (ft_strlen_stack(stack) == 2)
	{
		ft_swap(stack);
		return ;
	}
	tmp = ft_tab_int(stack);
	stack = stack->next;
	i = -1;
	while (++i < ft_strlen_stack(stack))
	{
		stack->value = tmp[i];
		stack = stack->next;
	}
	stack->value = tmp[i];
	free(tmp);
}
