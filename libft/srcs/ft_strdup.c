/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:16:31 by gpladet           #+#    #+#             */
/*   Updated: 2019/10/22 12:39:49 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		size_malloc;
	char	*word_duplicate;

	size_malloc = (int)ft_strlen(s1);
	word_duplicate = ft_calloc(size_malloc + 1, sizeof(char));
	if (word_duplicate == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		word_duplicate[i] = (char)s1[i];
		i++;
	}
	word_duplicate[i] = '\0';
	return (word_duplicate);
}
