/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 21:44:03 by gpladet           #+#    #+#             */
/*   Updated: 2021/03/15 22:01:59 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static int		display_line_complement(char **s1, int i)
{
	char	*tmp;

	if ((*s1)[i])
	{
		if (!(tmp = ft_strdup(&(*s1)[i + 1])))
			return (-1);
		free(*s1);
		if (!(*s1 = ft_strdup(tmp)))
			return (-1);
		free(tmp);
		return (1);
	}
	else
	{
		if (s1 != NULL)
			free(*s1);
		return (0);
	}
}

static int		display_line(char **line, char **s1)
{
	int		i;

	i = 0;
	if ((*s1)[i])
	{
		while ((*s1)[i] != '\0' && (*s1)[i] != '\n')
			i++;
		if (!(*line = ft_substr(*s1, 0, i)))
			return (-1);
		return (display_line_complement(s1, i));
	}
	else
		return (0);
}

static int		return_value_line(int fd, char **s1, char **line, int ret)
{
	if (ret < 0)
		return (-1);
	if (ret == 0 && s1[fd] == NULL)
	{
		if (!(*line = ft_strdup("")))
			return (-1);
		return (0);
	}
	else
		return (display_line(line, &s1[fd]));
}

int				add_value_static(int fd, char **s1,
				char buffer[BUFFER_SIZE + 1])
{
	char	*tmp;

	if (!(tmp = ft_strjoin(s1[fd], buffer)))
		return (-1);
	free(s1[fd]);
	if (!(s1[fd] = ft_strdup(tmp)))
		return (-1);
	free(tmp);
	return (2);
}

int				get_next_line(int fd, char **line)
{
	static char	*s1[FD_SIZE];
	char		buffer[BUFFER_SIZE + 1];
	int			ret;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || fd > FD_SIZE)
		return (-1);
	ret = 0;
	while ((ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if (!s1[fd])
		{
			if (!(s1[fd] = ft_strdup(buffer)))
				return (-1);
		}
		else
		{
			if (add_value_static(fd, s1, buffer) == -1)
				return (-1);
		}
		if (ft_strchr(s1[fd], '\n'))
			break ;
	}
	return (return_value_line(fd, s1, line, ret));
}
