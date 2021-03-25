/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:41:17 by gpladet           #+#    #+#             */
/*   Updated: 2021/03/25 15:43:39 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *))
{
	t_list	*new;
	t_list	*tmp;

	new = NULL;
	tmp = NULL;
	if (!lst || !f)
		return (NULL);
	new = (t_list *)malloc(ft_lstsize(lst) * sizeof(t_list));
	if (new)
	{
		tmp = f(lst->content);
		new = tmp;
		lst = lst->next;
		while (lst)
		{
			tmp->next = f(lst->content);
			tmp = tmp->next;
			lst = lst->next;
		}
	}
	return (new);
}
