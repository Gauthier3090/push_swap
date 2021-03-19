/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:46:45 by gpladet           #+#    #+#             */
/*   Updated: 2019/10/17 13:30:53 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnstr(const char *s1, const char *find, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*find)
		return ((char*)s1);
	i = 0;
	while (s1[i] != '\0' && i < len)
	{
		if (s1[i] == find[0])
		{
			j = 1;
			while ((find[j] != '\0') && (s1[i + j] == find[j])
				&& (i + j < len))
				j++;
			if (find[j] == '\0')
				return ((char*)&s1[i]);
		}
		i++;
	}
	return (0);
}
