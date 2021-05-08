/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 22:07:58 by gpladet           #+#    #+#             */
/*   Updated: 2021/05/08 14:35:04 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_swap/header.h"

void	swap(t_double_linked_list *list)
{
	int	value;

	value = list->current->value;
	list->current->value = list->current->next->value;
	list->current->next->value = value;
}

void	rotate(t_double_linked_list *list)
{
	list->current = list->current->next;
}

void	reverse_rotate(t_double_linked_list *list)
{
	list->current = list->current->prev;
}

void	push(t_double_linked_list *src, t_double_linked_list *dst)
{
	insert(dst, remove_first(src));
}
