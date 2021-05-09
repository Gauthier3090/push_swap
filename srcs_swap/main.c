/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 17:51:59 by gpladet           #+#    #+#             */
/*   Updated: 2021/05/09 15:02:53 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_swap/header.h"

// Faire une fonction qui trouve le chiffre le plus petit de la stack A
// Mettre le plus petit chiffre en tete de liste de A
// Push le plus petit chiffre dans la liste B
// Garder les deux plus grands nombres dans la liste A
// Remettre la liste de B dans la liste A
// Choisir s'il faut faire un rotate ou un reverse rotate
// Mettre le chiffre le plus petit dans la stack B
// Repeter l'operation

void	free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	**split_arg_env(char **argv)
{
	char	*env;
	char	*tmp;

	tmp = ft_strjoin(argv[0], " ");
	if (!tmp)
		exit(EXIT_FAILURE);
	env = ft_strjoin(tmp, argv[1]);
	free(tmp);
	if (!env)
		exit(EXIT_FAILURE);
	argv = ft_split(env, ' ');
	if (!argv)
		exit(EXIT_FAILURE);
	free(env);
	return (argv);
}

int	create_numbers(int argc, char ***argv)
{
	int	is_malloc;

	is_malloc = FALSE;
	if (argc == 2)
	{
		*argv = split_arg_env(*argv);
		is_malloc = TRUE;
	}
	if (!(check_args(*argv)))
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		if (is_malloc)
			free_tab(*argv);
		exit(EXIT_FAILURE);
	}
	return (is_malloc);
}

int	main(int argc, char **argv)
{
	t_double_linked_list		*list_a;
	t_double_linked_list		*list_b;
	t_double_linked_list_node	*node;
	int							i;
	int							is_malloc;

	if (argc <= 1)
		return (0);
	is_malloc = create_numbers(argc, &argv);
	list_a = new_list();
	list_b = new_list();
	i = 0;
	while (argv[i])
		i += 1;
	i -= 1;
	while (i)
	{
		node = new_node(argv[i]);
		insert(list_a, node);
		i -= 1;
	}
	display_list_next(list_a);
	ft_putchar_fd('\n', 1);
	display_list_next(list_b);
	free_list(list_a);
	free_list(list_b);
	if (is_malloc)
		free_tab(argv);
}
