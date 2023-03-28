/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:10:06 by ametzen           #+#    #+#             */
/*   Updated: 2023/03/25 16:16:44 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_error(const char *msg)
{
	if (msg != NULL)
	{
		ft_putstr_fd("Error: ", STDERR_FILENO);
		ft_putendl_fd((char *)msg, STDERR_FILENO);
	}
	else
	{
		ft_putstr_fd("Unknown error.\n", STDERR_FILENO);
	}
}

void	ft_error_exit(const char *msg)
{
	print_error(msg);
	exit(1);
}
