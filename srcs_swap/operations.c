/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 21:18:34 by gpladet           #+#    #+#             */
/*   Updated: 2021/04/21 17:58:22 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_swap/header.h"

void	ft_swap(int	*array)
{
	int	tmp;

	if (!array || sizeof(array) <= 1)
		return ;
	tmp = array[0];
	array[0] = array[1];
	array[1] = tmp;
}

int		*push_array(int *tab, int *size, int value)
{
	if (!tab)
	{
		*size = 1;
		tab = ft_calloc(*size, sizeof(int));
		if (!tab)
			error_message(ERROR_CALLOC);
		tab[0] = value;
	}
	else
	{
		ft_realloc(tab, (size_t)*size + 1);
		tab[*size - 1] = value;
		(*size)++;
	}
	return (tab);
}

int		*copy_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	*copy;

	copy = ft_calloc(size, sizeof(int));
	if (!copy)
		error_message(ERROR_CALLOC);
	i = -1;
	j = -1;
	while (++i < size)
		copy[++j] = tab[i];
	return (copy);
}

int		*pop_array(int *tab, int *size)
{
	int	*copy;
	int	i;
	int j;

	if (!tab)
		return (NULL);
	if (*size == 1)
	{
		free(tab);
		tab = NULL;
		*size = 0;
	}
	else
	{
		copy = copy_tab(tab, *size);
		free(tab);
		(*size)--;
		tab = ft_calloc(*size, sizeof(int));
		if (!tab)
			error_message(ERROR_CALLOC);
		i = -1;
		j = 0;
		while (++i < *size)
			tab[i] = copy[++j];
		free(copy);
	}
	return (tab);
}

void	ft_push(int **dest, int **src, int *length_dest, int *length_src)
{
	if (!*src)
		return ;
	*dest = push_array(*dest, length_dest, (*src)[0]);
	*src = pop_array(*src, length_src);
	
}
