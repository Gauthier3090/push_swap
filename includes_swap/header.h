/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 15:51:39 by gpladet           #+#    #+#             */
/*   Updated: 2021/04/21 15:26:45 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../libft/include/libft.h"
# include "limits.h"

# define TRUE 1
# define FALSE 0
# define ERROR_CALLOC "Dynamic allocation has failed"

typedef struct s_data
{
	int			*array_a;
	int			*array_b;
}					t_data;

/*
** check.c
*/
int					check_int(char **tab);
int					check_duplicate(char **tab, int i, int j);
int					check_args(char **argv);
void				free_tab(char **tab);

/*
** print.c
*/
void				error_message(char *message);
void				display_arrays(int *array_a, int *array_b);

/*
** utils.c
*/
long				ft_atol(const char *str);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_whitespace(const char c);
char				*ft_strcpy(char *dest, char *src);
void				*ft_realloc(void *ptr, size_t size);

