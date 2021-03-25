/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 00:09:21 by gpladet           #+#    #+#             */
/*   Updated: 2021/03/25 14:22:07 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

t_stack	*init_stack(t_stack *a, char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
		a = push_stack(a, ft_atoi(argv[i]));
	return (a);
}

void	execute_operations(char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;
	int		ret;

	a = NULL;
	b = NULL;
	a = init_stack(a, argv);
	display_stack(a, b);
	ret = 1;
	while (ret)
	{
		ret = getinput(&line);
		ft_putnbr_fd(ret, 1);
		if (ret == 0)
			break ;
		ft_operations(line, &a, &b);
		free(line);
		display_stack(a, b);
	}
	a = free_stack(a);
	b = free_stack(b);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		if (!check_args(argv))
			ft_putendl_fd("Error", 1);
		else
			execute_operations(argv);
	}
	return (EXIT_SUCCESS);
}
