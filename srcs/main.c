/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 00:09:21 by gpladet           #+#    #+#             */
/*   Updated: 2021/03/20 22:39:43 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] && s2[i]) && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int		check_args(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (FALSE);
		}
	}
	return (TRUE);
}

t_stack	*init_stack(t_stack *a, char **argv)
{
	int	i;

	if (!(a = ft_calloc(1, sizeof(t_stack))))
		error_message(ERROR_CALLOC);
	i = 0;
	while (argv[++i])
		a = push_stack(a, ft_atoi(argv[i]));
	return (a);
}

int		main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	a = NULL;
	b = NULL;
	if (argc > 1)
	{
		if (!check_args(argv))
			error_message(ERROR_CALLOC);
		else
		{
			a = init_stack(a, argv);
			if (!(b = ft_calloc(1, sizeof(t_stack))))
				error_message(ERROR_CALLOC);
		}
		while (get_next_line(0, &line))
		{
			if (!ft_strcmp("sa", line))
				ft_swap(a);
			if (!ft_strcmp("sb", line))
				ft_swap(b);
			free(line);
		}
		a = free_stack(a);
	}
	return (EXIT_SUCCESS);
}
