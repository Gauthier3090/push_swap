/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 15:52:33 by gpladet           #+#    #+#             */
/*   Updated: 2021/04/20 17:03:52 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_swap/header.h"

t_stack	*init_stack(t_stack *a, char **argv, int i)
{
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

void	print_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		ft_putendl_fd(tab[i], 1);
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
		if (!check_args(argv))
			error_message("Error");
		if (argc == 2)
		{
			tab = ft_split(argv[1], ' ');
			if (!check_duplicate(tab))
				error_message("Error");
			a = init_stack(a, tab, -1);
			free_tab(tab);
		}
		else
			a = init_stack(a, argv, 0);
		sort_stack(&a, &b);
		a = free_stack(a);
		b = free_stack(b);
	}
	return (EXIT_SUCCESS);
}
