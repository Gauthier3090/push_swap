/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 15:52:33 by gpladet           #+#    #+#             */
/*   Updated: 2021/04/21 17:55:03 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_swap/header.h"

int	ft_strlen_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	*init_array(char **tab, int i, int *length)
{
	int	j;
	int	*array;

	*length = ft_strlen_tab(tab) - 1;
	array = ft_calloc(*length, sizeof(int));
	if (!array)
		error_message(ERROR_CALLOC);
	j = -1;
	while (tab[++i])
		array[++j] = ft_atoi(tab[i]);
	return (array);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	char	**tab;

	if (argc > 1)
	{
		if (!check_args(argv))
			error_message("Error");
		data = ft_calloc(1, sizeof(t_data));
		if (!data)
			error_message(ERROR_CALLOC);
		if (argc == 2)
		{
			tab = ft_split(argv[1], ' ');
			if (!check_duplicate(tab, -1, -1))
				error_message("Error");
			data->array_a = init_array(tab, -1, &(data->length_a));
			free_tab(tab);
		}
		else
			data->array_a = init_array(argv, 0, &(data->length_a));
		display_arrays(data);
		ft_swap(data->array_a);
		display_arrays(data);
		ft_push(&(data->array_b), &(data->array_a), &(data->length_b), &(data->length_a));
		display_arrays(data);
		free(data->array_a);
		free(data->array_b);
		free(data);
	}
	return (EXIT_SUCCESS);
}
