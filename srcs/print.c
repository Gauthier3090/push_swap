/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 21:12:48 by gpladet           #+#    #+#             */
/*   Updated: 2021/03/20 21:13:23 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	error_message(char *message)
{
	ft_putstr_fd("Error: ", 1);
	ft_putendl_fd(message, 1);
	exit(EXIT_FAILURE);
}
