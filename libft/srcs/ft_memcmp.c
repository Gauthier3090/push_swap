/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 10:44:40 by gpladet           #+#    #+#             */
/*   Updated: 2021/03/25 15:42:44 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*word1;
	unsigned const char	*word2;
	size_t				i;

	word1 = (unsigned const char *)s1;
	word2 = (unsigned const char *)s2;
	i = 0;
	while (i < n)
	{
		if (word1[i] != word2[i])
			return (word1[i] - word2[i]);
		i++;
	}
	return (0);
}
