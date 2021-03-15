/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 00:09:41 by gpladet           #+#    #+#             */
/*   Updated: 2021/03/16 00:28:06 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../libft/include/libft.h"
# include "get_next_line.h"

# define TRUE 1
# define FALSE 0
# define ERROR_CALLOC "Dynamic allocation has failed"

typedef struct		s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

/*
** operations.c
*/
t_stack				*ft_swap(t_stack *stack);
void				ft_push(t_stack **dest, t_stack **src);

/*
** print.c
*/
void				error_message(char *message);
void				display_stack(t_stack *a, t_stack *b);

/*
** stack.c
*/
t_stack				*free_stack(t_stack *stack);
t_stack				*push_stack(t_stack *stack, int value);
t_stack				*pop_stack(t_stack *stack);
void				print_stack(t_stack *stack);
int					ft_strlen_stack(t_stack *stack);

#endif
