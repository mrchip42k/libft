/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kill_or_die.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:57:33 by ametzen           #+#    #+#             */
/*   Updated: 2023/03/25 16:01:50 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	kill_or_die(int sig, pid_t pid)
{
	if (kill(pid, sig) != 0)
		ft_error_exit("Failed to send signal.");
}
