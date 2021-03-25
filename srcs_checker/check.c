/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:11:20 by gpladet           #+#    #+#             */
/*   Updated: 2021/03/25 15:22:05 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_checker/header.h"

int 	check_int(char **argv)
{
	long	number;
	int		i;

	i = 0;
	while (argv[++i])
	{
		number = ft_atol(argv[i]);
		if (number < INT_MIN || number > INT_MAX)
			return (FALSE);
	}
	return (TRUE);
}

int	check_duplicate(char **argv)
{
	int		i;
	int		j;
	long	number;
	long	number2;

	i = 0;
	while (argv[++i])
	{
		j = 0;
		while (argv[++j])
		{
			if (i != j)
			{
				number = ft_atol(argv[i]);
				number2 = ft_atol(argv[j]);
				if (number == number2)
					return (FALSE);
			}
		}
	}
	return (TRUE);
}

int	check_args(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (argv[i][j] == '-' || argv[i][j] == '+')
				j++;
			if (!ft_isdigit(argv[i][j]))
				return (FALSE);
		}
	}
	if (!(check_int(argv)) || !(check_duplicate(argv)))
		return (FALSE);
	return (TRUE);
}