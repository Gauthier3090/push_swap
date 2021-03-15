/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 00:09:21 by gpladet           #+#    #+#             */
/*   Updated: 2021/03/15 22:11:43 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int			check_args(char **argv)
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

int			main(int argc, char **argv)
{
	t_stack	*a;
	char	*line;
	int		i;

	if (argc > 1)
	{
		if (!check_args(argv))
			ft_putendl_fd("Error", 1);
		else
		{
			if (!(a = ft_calloc(1, sizeof(t_stack))))
				return (EXIT_FAILURE);
			i = 0;
			while (argv[++i])
			{
				if (!(a = push_stack(a, ft_atoi(argv[i]))))
				{
					a = free_stack(a);
					return (EXIT_FAILURE);
				}
			}
			print_stack(a);
			a = free_stack(a);
		}
		while (get_next_line(0, &line))
			free(line);
	}
	return (EXIT_SUCCESS);
}
