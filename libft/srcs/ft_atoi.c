/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:55:06 by gpladet           #+#    #+#             */
/*   Updated: 2021/03/25 15:33:17 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_isspace(char c)
{
	if ((c != '\0') && ((c == '\t') || (c == '\n')
			|| (c == '\v') || (c == '\f')
			|| (c == '\r') || (c == ' ')))
		return (1);
	return (0);
}

static int	check_long_value(int sign, unsigned int result)
{
	if (sign == -1 && result > 2147483648)
		return (0);
	if (sign == 1 && result > 2147483647)
		return (-1);
	return (sign * (int)result);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned int	result;

	i = 0;
	result = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]))
		{
			result = result * 10 + (str[i] - '0');
			i++;
		}
		else
			break ;
	}
	return (check_long_value(sign, result));
}
