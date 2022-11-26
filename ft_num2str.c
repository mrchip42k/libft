/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num2str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:12:34 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/26 17:34:56 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_n2s_base_funnynumber(const char *base, size_t base_len);
char	*ft_n2s_base_zero(const char *base);

static size_t	st_predict_length(long n, size_t base_len)
{
	size_t	result;

	result = 0;
	if (n < 0)
	{
		result++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= base_len;
		result++;
	}
	return (result);
}

// (n) is not 0
static void	st_convert(long n, char *str, const char *base, size_t str_len)
{
	size_t	i;
	size_t	base_len;

	base_len = ft_strlen(base);
	i = str_len - 1;
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		str[i] = base[n % base_len];
		n /= base_len;
		i--;
	}
}

// (n) is not 0, or min long; base exists and is longer than 1
static char	*st_n2s_base_unprotected(long n, const char *base,
				size_t base_len)
{
	char	*result;
	size_t	result_len;

	result_len = st_predict_length(n, base_len);
	if (result_len == 0)
		return (NULL);
	result = malloc(result_len + 1);
	if (result == NULL)
		return (NULL);
	if (n < 0)
		result[0] = '-';
	st_convert(n, result, base, result_len);
	result[result_len] = '\0';
	return (result);
}

char	*ft_num2str_base(long n, const char *base)
{
	size_t	base_len;

	if (base == NULL)
		return (NULL);
	base_len = ft_prot_strlen(base);
	if (base_len <= 1)
		return (NULL);
	if (n == 0)
		return (ft_n2s_base_zero(base));
	if (n == -9223372036854775807)
		return (ft_n2s_base_funnynumber(base, base_len));
	return (st_n2s_base_unprotected(n, base, base_len));
}

char	*ft_num2str(long n)
{
	return (ft_num2str_base(n, "0123456789"));
}
