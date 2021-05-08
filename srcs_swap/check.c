/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:37:22 by gpladet           #+#    #+#             */
/*   Updated: 2021/05/08 16:28:57 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_swap/header.h"

int	ft_whitespace(const char c)
{
	if (c == ' ' || c == '\t' || c == '\r'
		|| c == '\n' || c == '\f' || c == '\v')
		return (TRUE);
	return (FALSE);
}

long	ft_atol(const char *str)
{
	size_t			i;
	unsigned long	ret;
	int				is_neg;

	is_neg = 0;
	i = 0;
	while (ft_whitespace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			is_neg = 1;
		i++;
	}
	ret = 0;
	while (ft_isdigit(str[i]))
		ret = ret * 10 + (str[i++] - '0');
	if (is_neg)
		ret = -ret;
	return (ret);
}

int	check_int(char *value)
{
	long	number;

	number = ft_atol(value);
	if (number < INT_MIN || number > INT_MAX)
		return (FALSE);
	return (TRUE);
}

int	check_duplicate(char **argv, int i, int j)
{
	int		tmp;
	long	number;
	long	number2;

	tmp = j;
	while (argv[i])
	{
		j = tmp;
		while (argv[j])
		{
			if (i != j)
			{
				number = ft_atol(argv[i]);
				number2 = ft_atol(argv[j]);
				if (number == number2)
					return (FALSE);
			}
			j++;
		}
		i++;
	}
	return (TRUE);
}

int	check_args(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (FALSE);
			j++;
		}
		if (!(check_int(argv[i])))
			return (FALSE);
		i++;
	}
	if (!(check_duplicate(argv, 1, 2)))
		return (FALSE);
	return (TRUE);
}
