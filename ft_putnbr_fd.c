/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:17:26 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/08 17:24:51 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

// Recursive
static void	st_nbrput_fd(int nb, int fd)
{
	int		one_less_digit;
	char	nb_as_char;

	one_less_digit = nb / 10;
	if (one_less_digit > 0)
	{
		st_nbrput_fd(one_less_digit, fd);
	}
	nb_as_char = '0' + (nb % 10);
	write(fd, &nb_as_char, 1);
}

// First, the two special cases:
// - min int
// - zero
// Then, nbrput() handles the rest
void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		write(fd, "-", 1);
	}
	st_nbrput_fd(n, fd);
}
