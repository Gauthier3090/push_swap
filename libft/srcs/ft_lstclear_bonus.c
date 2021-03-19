/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 10:28:41 by gpladet           #+#    #+#             */
/*   Updated: 2019/10/18 15:36:24 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*list;
	t_list	*tmp;

	if (!lst)
		return ;
	list = *lst;
	tmp = NULL;
	if (!list || !del)
		return ;
	while (list != NULL)
	{
		if (list->next)
			tmp = list->next;
		else
			tmp = NULL;
		ft_lstdelone(list, del);
		list = tmp;
	}
	*lst = NULL;
}
