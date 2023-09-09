/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_secure_atol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:08:38 by ametzen           #+#    #+#             */
/*   Updated: 2023/09/09 17:23:30 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	custom_atoi_parsing(const char *str, long *result, long *sign)
{
	long	i;
	bool	has_read_any_digit;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	i++;
	if (str[i - 1] == '-')
		*sign = -1;
	else if (str[i - 1] != '+')
		i--;
	has_read_any_digit = false;
	while (str[i] && ft_isdigit(str[i]))
	{
		has_read_any_digit = true;
		*result *= 10;
		*result += str[i] - '0';
		if (*result != (long) *result)
			return (-1);
		i++;
	}
	if (has_read_any_digit)
		return (i);
	else
		return (-1);
}

bool	ft_secure_atol(const char *str, long *out)
{
	long	result;
	long	sign;
	long	parsing_return;

	if (str == NULL || out == NULL || str[0] == '\0')
		return (false);
	sign = 1;
	result = 0;
	parsing_return = custom_atoi_parsing(str, &result, &sign);
	if (parsing_return > 0
		&& ft_strlen(str) == (size_t)parsing_return)
	{
		*out = result * sign;
		return (true);
	}
	else
		return (false);
}
