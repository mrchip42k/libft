/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:12:43 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/08 18:33:49 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

char *ft_itoa(int n)
{
	char	*new_string;
	int		len;

	len = st_calc_len(n);
	new_string = malloc(len + 1);
	if (new_string == 0)
		return (0);
	
	new_string[len] = '\0';
	return (new_string);
}