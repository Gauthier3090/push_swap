/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 15:51:39 by gpladet           #+#    #+#             */
/*   Updated: 2021/05/14 23:59:48 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../libft/include/libft.h"
# include "limits.h"

# define TRUE 1
# define FALSE 0
# define CHUNK 50

typedef struct s_double_linked_list_node
{
	int									value;
	struct s_double_linked_list_node	*next;
	struct s_double_linked_list_node	*prev;
}				t_double_linked_list_node;

typedef struct s_double_linked_list
{
	int									count;
	struct s_double_linked_list_node	*current;
}				t_double_linked_list;

typedef struct s_quarter
{
	int									first;
	int									second;
	int									third;
	int									four;
}				t_quarter;

/*
** check.c
*/
int							check_args(char **argv);

/*
** display.c
*/
void						display_list_prev(t_double_linked_list *list);
void						display_list_next(t_double_linked_list *list);
void						display_lists(t_double_linked_list *list_a,
								t_double_linked_list *list_b);

/*
** list.c
*/
t_double_linked_list		*new_list(void);
t_double_linked_list_node	*new_node(char *value);
void						insert(t_double_linked_list *list,
								t_double_linked_list_node *new_node);
t_double_linked_list_node	*remove_first(t_double_linked_list *list);
void						free_list(t_double_linked_list *list);

/*
** median.c
*/
int							find_median(t_double_linked_list *list_a,
								int div_median);

/*
** operations_stack_a.c
*/
void						push_a(t_double_linked_list *list_a,
								t_double_linked_list *list_b);
void						swap_a(t_double_linked_list *list_a);
void						rotate_a(t_double_linked_list *list_a);
void						reverse_rotate_a(t_double_linked_list *list_a);

/*
** operations_stack_b.c
*/
void						push_b(t_double_linked_list *list_a,
								t_double_linked_list *list_b);
void						swap_b(t_double_linked_list *list_b);
void						rotate_b(t_double_linked_list *list_b);
void						reverse_rotate_b(t_double_linked_list *list_b);

/*
** operations.c
*/
void						swap(t_double_linked_list *list);
void						rotate(t_double_linked_list *list);
void						reverse_rotate(t_double_linked_list *list);
void						push(t_double_linked_list *src,
								t_double_linked_list *dst);

/*
** solve_5_or_less.c
*/
void						solve_5_or_less(t_double_linked_list *list_a,
								t_double_linked_list *list_b);

/*
** solve_100_or_less.c
*/
void						solve_100_or_less(t_double_linked_list *list_a,
								t_double_linked_list *list_b);

/*
** solve_others.c
*/
void						solve_others(t_double_linked_list *list_a,
								t_double_linked_list *list_b);

/*
** sort.c
*/
int							sorted_list(t_double_linked_list *list_a,
								t_double_linked_list *list_b);
int							get_min(int a, int b);
int							get_min_value(t_double_linked_list_node *node,
								int length);
int							get_max_value(t_double_linked_list_node *node,
								int length);
void						sort_list(t_double_linked_list *list_a,
								t_double_linked_list *list_b);

/*
** sort2.c
*/
void						reverse_or_rotate(t_double_linked_list *list,
								int value, int list_a);

#endif
