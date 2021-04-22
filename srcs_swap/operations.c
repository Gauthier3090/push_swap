/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 21:18:34 by gpladet           #+#    #+#             */
/*   Updated: 2021/04/22 16:30:57 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_swap/header.h"

void	ft_swap(int	*array, int size)
{
	int	tmp;

	if (!array || size <= 1)
		return ;
	tmp = array[0];
	array[0] = array[1];
	array[1] = tmp;
}

void	ft_push(int **dest, int **src, int *length_dest, int *length_src)
{
	if (!*src || *length_src == 0)
		return ;
	*dest = push_array(*dest, length_dest, (*src)[0]);
	*src = pop_array(*src, length_src);
}

void	ft_rotate(int *array, int size)
{
	int	tmp;
	int	i;

	if (!array || size <= 1)
		return ;
	tmp = array[0];
	i = -1;
	while (++i < size - 1)
		array[i] = array[i + 1];
	array[i] = tmp;
}

void	ft_reverse_rotate(int *array, int size)
{
	int	tmp;

	if (!array || size <= 1)
		return ;
	if (size == 2)
	{
		ft_swap(array, size);
		return ;
	}
	tmp = array[size - 1];
	while (--size)
		array[size] = array[size - 1];
	array[size] = tmp;
}
