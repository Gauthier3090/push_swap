/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:20:47 by gpladet           #+#    #+#             */
/*   Updated: 2019/10/18 10:00:13 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			length_dst;
	size_t			length_src;
	size_t			k;

	length_dst = 0;
	while (dst[length_dst] != '\0')
		length_dst++;
	k = 0;
	while (src[k] != '\0')
		k++;
	if (size <= length_dst)
		k += size;
	else
		k += length_dst;
	length_src = 0;
	while ((src[length_src] != '\0') && (length_dst + 1 < size))
	{
		dst[length_dst] = src[length_src];
		length_dst++;
		length_src++;
	}
	dst[length_dst] = '\0';
	return (k);
}
