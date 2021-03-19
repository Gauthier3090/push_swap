/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 00:09:21 by gpladet           #+#    #+#             */
/*   Updated: 2021/03/19 13:53:20 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

t_stack		*push_stack(t_stack	*stack, int value)
{
	t_stack	*element;

	if (!(element = ft_calloc(1, sizeof(t_stack))))
		return (NULL);
	element->value = value;
	element->next = stack;
	return (element);
}

void		print_stack(t_stack *stack)
{
	int	i;

	i = -1;
	while (stack->next)
	{
		ft_putnbr_fd(stack->value, 1);
		ft_putchar_fd('\n', 1);
		stack = stack->next;
	}
}

int			check_args(char	**argv)
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
	int		i;

	if (argc > 0)
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
					return (EXIT_FAILURE);
			}
			print_stack(a);
		}
	}
	getchar();
	return (EXIT_SUCCESS);
}
