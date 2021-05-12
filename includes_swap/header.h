/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 15:51:39 by gpladet           #+#    #+#             */
/*   Updated: 2021/05/12 17:45:16 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../libft/include/libft.h"
# include "limits.h"

# define TRUE 1
# define FALSE 0
# define CHUNK 20

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
** operations.c
*/
void						swap(t_double_linked_list *list);
void						rotate(t_double_linked_list *list);
void						reverse_rotate(t_double_linked_list *list);
void						push(t_double_linked_list *src,
								t_double_linked_list *dst);

/*
** sort.c
*/
void						sort_list(t_double_linked_list *list_a,
								t_double_linked_list *list_b);
int							get_position_min(t_double_linked_list *list, int length);
void						operations(t_double_linked_list *list, int min);

/*
** sort2.c
*/
void						sort_list_chunk(t_double_linked_list *list_a,
								t_double_linked_list *list_b);

#endif
