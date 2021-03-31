/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 15:51:39 by gpladet           #+#    #+#             */
/*   Updated: 2021/03/31 16:48:48 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../libft/include/libft.h"
# include "limits.h"

# define TRUE 1
# define FALSE 0
# define ERROR_CALLOC "Dynamic allocation has failed"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

/*
** check.c
*/
int					check_int(char **argv);
int					check_duplicate(char **argv);
int					check_args(char **argv);

/*
** operations.c
*/
void				ft_swap(t_stack *stack);
void				ft_push(t_stack **dest, t_stack **src);
void				ft_rotate(t_stack *stack);
void				ft_reverse_rotate(t_stack *stack);

/*
** print.c
*/
void				error_message(char *message);
void				display_stack(t_stack *a, t_stack *b);

/*
** sort.c
*/
int					get_middle(t_stack *a);
void				sort_stack(t_stack **a, t_stack **b);

/*
** stack.c
*/
t_stack				*free_stack(t_stack *stack);
t_stack				*push_stack(t_stack *stack, int value);
t_stack				*pop_stack(t_stack *stack);
void				print_stack(t_stack *stack);
int					ft_strlen_stack(t_stack *stack);

/*
** utils.c
*/
long				ft_atol(const char *str);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_whitespace(const char c);
char				*ft_strcpy(char *dest, char *src);
void				*ft_realloc(void *ptr, size_t size);

