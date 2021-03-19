/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 11:57:11 by gpladet           #+#    #+#             */
/*   Updated: 2019/10/16 11:44:46 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*word;

	i = 0;
	word = (char *)s;
	while (word[i] != '\0')
	{
		if (word[i] == c)
			return (&word[i]);
		i++;
	}
	if (word[i] == c)
		return (&word[i]);
	return (NULL);
}
