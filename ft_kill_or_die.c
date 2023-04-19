/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kill_or_die.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:57:33 by ametzen           #+#    #+#             */
/*   Updated: 2023/03/31 18:23:16 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*g_err1 = "Tried to send a signal to a non positive PID. \
Refusing, exiting instead.";

void	kill_or_die(pid_t pid, int sig)
{
	if (kill(pid, sig) != 0)
		ft_error_exit("Failed to send signal.");
}

void	kill_single_or_die(pid_t pid, int sig)
{
	if (pid <= 0)
		ft_error_exit(g_err1);
	if (kill(pid, sig) != 0)
		ft_error_exit("Failed to send signal.");
}

int	kill1(pid_t pid, int sig)
{
	if (pid <= 0)
		ft_error_exit(g_err1);
	return (kill(pid, sig) != 0);
}
