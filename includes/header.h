/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 00:09:41 by gpladet           #+#    #+#             */
/*   Updated: 2021/03/15 22:06:50 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../libft/include/libft.h"
# include "get_next_line.h"

# define TRUE 1
# define FALSE 0

typedef struct		s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

/*
** stack.c
*/
t_stack				*free_stack(t_stack *stack);
t_stack				*push_stack(t_stack *stack, int value);
void				print_stack(t_stack *stack);

#endif
