/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:12:43 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/10 17:06:15 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	st_calc_len(int n)
{
	int		len;
	long	ln;

	ln = n;
	len = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
	{
		len = 1;
		ln *= -1;
	}
	while (ln > 0)
	{
		len++;
		ln /= 10;
	}
	return (len);
}

// Expects a correctly allocated string,
// Modifies str; Does not null terminate.
// Only works with non-zero and positive long ints.
static void	st_itoa_mini(char *str, long ln)
{
	while (ln > 0)
	{
		*str = '0' + (ln % 10);
		ln /= 10;
		str--;
	}
}

char	*ft_itoa(int n)
{
	char	*new_string;
	int		len;
	long	ln;

	len = st_calc_len(n);
	new_string = malloc(len + 1);
	if (new_string == 0)
		return (0);
	ln = n;
	if (n == 0)
		new_string[0] = '0';
	else if (n < 0)
	{
		new_string[0] = '-';
		st_itoa_mini(&new_string[len - 1], ln * -1);
	}
	else
		st_itoa_mini(&new_string[len - 1], ln);
	new_string[len] = '\0';
	return (new_string);
}
