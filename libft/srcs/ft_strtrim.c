/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:02:51 by gpladet           #+#    #+#             */
/*   Updated: 2021/03/25 15:35:56 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	front_trim(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	k = 0;
	while (s1[++i])
	{
		j = -1;
		k = 0;
		while (set[++j])
		{
			if (s1[i] == set[j])
				k++;
		}
		if (k == 0)
			break ;
	}
	return (i);
}

static int	back_trim(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = ft_strlen(s1);
	l = 0;
	while (--i > 0)
	{
		j = -1;
		k = 0;
		while (set[++j])
		{
			if (s1[i] == set[j])
				k++;
		}
		if (k == 0)
			break ;
		l++;
	}
	return (l);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*word;

	if ((!s1 && !set) || (!s1))
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	word = ft_substr(s1, front_trim(s1, set), ft_strlen(s1));
	if (!word)
		return (NULL);
	word = ft_substr(word, 0, ft_strlen(word) - back_trim(word, set));
	if (!word)
		return (NULL);
	return (word);
}
