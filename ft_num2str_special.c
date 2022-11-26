/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num2str_special.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:24:00 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/26 18:05:40 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	st_predict_length_funny(size_t base_len)
{
	size_t			result;
	unsigned long	n;

	n = 0x7fffffffffffffff;
	result = 1;
	while (n > 0)
	{
		n /= base_len;
		result++;
	}
	return (result);
}

// Special case. Handles minimum long, since that can't be flipped to positive.
// -9223372036854775807
char	*ft_n2s_base_funnynumber(const char *base, size_t base_len)
{
	char			*result;
	size_t			size;
	unsigned long	n;
	size_t			i;

	n = 0x7fffffffffffffff;
	size = st_predict_length_funny(base_len);
	result = malloc(size + 1);
	if (result == NULL)
		return (NULL);
	result[0] = '-';
	i = size - 1;
	while (n > 0)
	{
		result[i] = base[n % base_len];
		n /= base_len;
		i--;
	}
	return (result);
}

// Special case. Handles 0, so the logic downstream never has to deal with it.
char	*ft_n2s_base_zero(const char *base)
{
	char	*zero;

	zero = malloc(2);
	if (zero == NULL)
		return (NULL);
	zero[0] = base[0];
	zero[1] = '\0';
	return (zero);
}
