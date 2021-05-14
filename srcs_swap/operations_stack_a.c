/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_stack_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 15:34:38 by gpladet           #+#    #+#             */
/*   Updated: 2021/05/14 13:49:02 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_swap/header.h"

void	push_a(t_double_linked_list *list_a, t_double_linked_list *list_b)
{
	push(list_b, list_a);
	ft_putendl_fd("pa", 1);
}

void	swap_a(t_double_linked_list *list_a)
{
	swap(list_a);
	ft_putendl_fd("sa", 1);
}

void	rotate_a(t_double_linked_list *list_a)
{
	rotate(list_a);
	ft_putendl_fd("ra", 1);
}

void	reverse_rotate_a(t_double_linked_list *list_a)
{
	reverse_rotate(list_a);
	ft_putendl_fd("rra", 1);
}
