/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 15:51:39 by gpladet           #+#    #+#             */
/*   Updated: 2021/05/05 17:51:42 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../libft/include/libft.h"
# include "limits.h"

# define TRUE 1
# define FALSE 0
# define ERROR_CALLOC "Dynamic allocation has failed"

typedef struct s_double_linked_list_node
{
	int									value;
	struct s_double_linked_list_node 	*next;
	struct s_double_linked_list_node 	*prev;
}				t_double_linked_list_node;


typedef struct	s_double_linked_list
{
	int									count;
	struct	s_double_linked_list_node 	*current;
	
}				t_double_linked_list;

