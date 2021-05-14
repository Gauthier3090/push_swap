/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_stack_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 15:18:21 by gpladet           #+#    #+#             */
/*   Updated: 2021/05/14 13:48:25 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_swap/header.h"

void	push_b(t_double_linked_list *list_a, t_double_linked_list *list_b)
{
	push(list_a, list_b);
	ft_putendl_fd("pb", 1);
}

void	swap_b(t_double_linked_list *list_b)
{
	swap(list_b);
	ft_putendl_fd("sb", 1);
}

void	rotate_b(t_double_linked_list *list_b)
{
	rotate(list_b);
	ft_putendl_fd("rb", 1);
}

void	reverse_rotate_b(t_double_linked_list *list_b)
{
	reverse_rotate(list_b);
	ft_putendl_fd("rrb", 1);
}
