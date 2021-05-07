/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 17:51:59 by gpladet           #+#    #+#             */
/*   Updated: 2021/05/07 22:12:20 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_swap/header.h"

char	**split_arg_env(char **argv)
{
	char	*env;

	argv[0] = ft_strjoin(argv[0], " ");
	if (!argv[0])
		exit(EXIT_FAILURE);
	env = ft_strjoin(argv[0], argv[1]);
	if (!env)
		exit(EXIT_FAILURE);
	argv = ft_split(env, ' ');
	if (!argv)
		exit(EXIT_FAILURE);
	free(env);
	return (argv);
}

int	main(int argc, char **argv)
{
	t_double_linked_list		*list;
	t_double_linked_list_node	*node;
	int							i;

	if (argc > 1)
	{
		if (argc == 2)
			argv = split_arg_env(argv);
		list = new_list();
		i = 0;
		while (argv[++i])
		{
			node = new_node(argv[i]);
			insert(list, node);
		}
		display_list_prev(list);
		ft_putchar_fd('\n', 1);
		display_list_next(list);
		free_list(list);
	}
}
