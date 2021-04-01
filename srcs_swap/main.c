/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 15:52:33 by gpladet           #+#    #+#             */
/*   Updated: 2021/04/01 17:00:30 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_swap/header.h"

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
	int	min;

	if (b)
		return (FALSE);
	min = a->value;
	while (a->next)
	{
		if (min > a->value)
			return (FALSE);
		a = a->next;
	}
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
			a = init_stack(a, argv);
			sort_stack(&a, &b);
			a = free_stack(a);
			b = free_stack(b);
		}
	}
	return (EXIT_SUCCESS);
}
