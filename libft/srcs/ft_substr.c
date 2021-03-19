/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 10:28:18 by gpladet           #+#    #+#             */
/*   Updated: 2019/10/23 15:06:53 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*word;

	if (s == NULL)
		return (NULL);
	i = 0;
	if (start > (unsigned int)ft_strlen(s))
	{
		if (!(word = ft_calloc(1, sizeof(char))))
			return (NULL);
		return (word);
	}
	if (!(word = ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	while ((i < len) && (s[start] != '\0'))
	{
		word[i] = s[start];
		start++;
		i++;
	}
	return (word);
}
