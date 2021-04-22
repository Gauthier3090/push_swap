/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 16:30:18 by gpladet           #+#    #+#             */
/*   Updated: 2021/04/22 16:43:35 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_swap/header.h"

int	*push_array(int *array, int *size, int value)
{
	int	*new;
	int	i;
	int	j;

	(*size)++;
	new = calloc(*size, sizeof(int));
	if (!new)
		error_message(ERROR_CALLOC);
	i = 0;
	j = -1;
	while (++i < *size)
		new[i] = array[++j];
	new[0] = value;
	if (array)
		free(array);
	return (new);
}

int	*pop_array(int *array, int *size)
{
	int	*new;
	int	i;
	int	j;

	(*size)--;
	new = ft_calloc(*size, sizeof(int));
	if (!new)
		error_message(ERROR_CALLOC);
	i = -1;
	j = 0;
	while (++i < *size)
		new[i] = array[++j];
	free(array);
	return (new);
}

int	*copy_tab(int *tab, int size)
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
