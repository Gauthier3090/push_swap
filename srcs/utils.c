/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:48:30 by gpladet           #+#    #+#             */
/*   Updated: 2021/03/25 14:29:53 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

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

int 	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] && s2[i]) && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_whitespace(const char c)
{
	if (c == ' ' || c == '\t' || c == '\r'
		|| c == '\n' || c == '\f' || c == '\v')
		return (TRUE);
	return (FALSE);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new;

	if (!ptr)
	{
		new = ft_calloc(size, sizeof(char));
		if (!new)
			error_message(ERROR_CALLOC);
		return (new);
	}
	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new = ft_calloc(size, sizeof(char));
	if (!new)
		error_message(ERROR_CALLOC);
	ft_strcpy(new, ptr);
	free(ptr);
	return (new);
}
