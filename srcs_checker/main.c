/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 00:09:21 by gpladet           #+#    #+#             */
/*   Updated: 2021/03/30 16:35:03 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_checker/header.h"

t_stack	*init_stack(t_stack *a, char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
		a = push_stack(a, ft_atoi(argv[i]));
	return (a);
}

int	ft_sorted_stack(t_stack *a, t_stack *b)
{
	if (b)
		return (FALSE);
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (FALSE);
		a = a->next;
	}
	return (TRUE);
}

int	execute_operations(char **argv, t_stack **a, t_stack **b)
{
	char	*line;
	int		ret;

	*a = init_stack(*a, argv);
	display_stack(*a, *b);
	ret = 1;
	while (ret)
	{
		ret = getinput(&line);
		if (ret == 0)
			break ;
		if (!(ft_operations(line, a, b)))
			return (FALSE);
		free(line);
		display_stack(*a, *b);
	}
	free(line);
	return (TRUE);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc > 1)
	{
		if (!check_args(argv))
			ft_putendl_fd("Error", 1);
		else
		{
			if (execute_operations(argv, &a, &b))
			{
				if (!(ft_sorted_stack(a, b)))
					ft_putendl_fd("KO", 1);
				else
					ft_putendl_fd("OK", 1);
			}
			a = free_stack(a);
			b = free_stack(b);
		}
	}
	return (EXIT_SUCCESS);
}
