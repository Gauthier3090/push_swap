/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 00:09:41 by gpladet           #+#    #+#             */
/*   Updated: 2021/05/10 16:47:56 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../libft/include/libft.h"
# include "limits.h"

# define TRUE 1
# define FALSE 0

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
** read.c
*/
int							getinput(char **line);
int							list_operations(char *line,
								t_double_linked_list *list_a,
								t_double_linked_list *list_b);
int							sorted_list(t_double_linked_list *list_a,
								t_double_linked_list *list_b);

/*
** utils.c
*/
long						ft_atol(const char *str);
int							ft_strcmp(const char *s1, const char *s2);
int							ft_whitespace(const char c);
char						*ft_strcpy(char *dest, char *src);
void						*ft_realloc(void *ptr, size_t size);

#endif
