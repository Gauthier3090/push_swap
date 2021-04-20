/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 00:09:21 by gpladet           #+#    #+#             */
/*   Updated: 2021/04/20 17:06:23 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_checker/header.h"

t_stack	*init_stack(t_stack *a, char **argv, int i)
{
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

int	execute_operations(char **argv, t_stack **a, t_stack **b, int i)
{
	char	*line;
	int		ret;

	*a = init_stack(*a, argv, i);
	ret = 1;
	while (ret)
	{
		ret = getinput(&line);
		if (ret == 0)
			break ;
		if (!(ft_operations(line, a, b)))
			return (FALSE);
		free(line);
	}
	free(line);
	return (TRUE);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**tab;

	a = NULL;
	b = NULL;
	if (argc > 1)
	{
		if (argc == 2)
		{
			tab = ft_split(argv[1], ' ');
			if (!tab)
				error_message(ERROR_CALLOC);
			if (!check_args(tab))
				error_message("Error");
			if (execute_operations(tab, &a, &b, -1))
			{
				if (!(ft_sorted_stack(a, b)))
					ft_putendl_fd("KO", 1);
				else
					ft_putendl_fd("OK", 1);
			}
			a = free_stack(a);
			b = free_stack(b);
			return (EXIT_SUCCESS);
		}
		if (!check_args(argv))
			error_message("Error");
		else
		{
			if (execute_operations(argv, &a, &b, 0))
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
