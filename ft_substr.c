/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:12:11 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/10 17:08:05 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	st_calc_length(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	real_length;

	i = 0;
	real_length = 0;
	while (1)
	{
		if (s[i] == '\0' || real_length == len)
			return (real_length);
		if (i >= start)
			real_length++;
		if (real_length == len)
			return (real_length);
		i++;
	}
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new_str;
	size_t			real_length;
	unsigned int	i;

	real_length = st_calc_length(s, start, len);
	new_str = malloc(real_length + 1);
	if (new_str != 0)
	{
		i = 0;
		while (i < real_length)
		{
			new_str[i] = s[start + i];
			i++;
		}
		new_str[real_length] = '\0';
	}
	return (new_str);
}
