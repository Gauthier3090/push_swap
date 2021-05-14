/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 17:51:59 by gpladet           #+#    #+#             */
/*   Updated: 2021/05/13 15:29:32 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Faire une fonction qui trie les n premiers nombres de la liste (tete de liste plus petit nombre)
//Mettre la liste triee dans la stack B
//A partir du deuxieme chunk, se situe entre x et y et faire des reverse rotate et reverse
//Repeter l operation jusqu a ce que la stack A soit vide
//Remettre la stack B dans A

#include "../includes_swap/header.h"

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
	sort_list(list_a, list_b);
	if (is_malloc)
		free_tab(argv);
}
