/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_custom_atoi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:08:38 by ametzen           #+#    #+#             */
/*   Updated: 2023/03/28 15:51:38 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	custom_atoi_parsing(const char *str, long *result, long *sign)
{
	int		i;
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
		if (*result != (int) *result)
			return (0);
		i++;
	}
	return (i && has_read_any_digit);
}

int	ft_custom_atoi(const char *str, int *out)
{
	long	result;
	long	sign;
	int		parsing_return;

	if (str == NULL || out == NULL || str[0] == '\0')
		return (0);
	sign = 1;
	result = 0;
	parsing_return = custom_atoi_parsing(str, &result, &sign);
	if (parsing_return > 0)
		*out = result * sign;
	return (parsing_return);
}
