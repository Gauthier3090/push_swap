/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:11:20 by gpladet           #+#    #+#             */
/*   Updated: 2021/04/22 18:40:33 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_checker/header.h"

int 	check_int(char **tab)
{
	long	number;
	int		i;

	i = -1;
	while (tab[++i])
	{
		number = ft_atol(tab[i]);
		if (number < INT_MIN || number > INT_MAX)
			return (FALSE);
	}
	return (TRUE);
}

int	check_duplicate(char **tab, int i, int j)
{
	int		tmp;
	long	number;
	long	number2;

	tmp = j;
	while (tab[++i])
	{
		j = tmp;
		while (tab[++j])
		{
			if (i != j)
			{
				number = ft_atol(tab[i]);
				number2 = ft_atol(tab[j]);
				if (number == number2)
					return (FALSE);
			}
		}
	}
	return (TRUE);
}

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

int	check_args(char **argv)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	i = 0;
	while (argv[++i])
	{
		tab = ft_split(argv[i], ' ');
		if (!tab)
			error_message(ERROR_CALLOC);
		j = -1;
		while (tab[++j])
		{
			k = -1;
			while (tab[j][++k])
			{
				if (tab[j][k] == '-' || tab[j][k] == '+')
					k++;
				if (!ft_isdigit(tab[j][k]))
					return (FALSE);
				if (!(check_int(tab)))
					return (FALSE);
			}
		}
		free_tab(tab);
	}
	if (!(check_duplicate(argv, 0, 0)))
		return (FALSE);
	return (TRUE);
}
