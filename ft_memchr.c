/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:33:04 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/10 17:06:22 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*converted_s;
	unsigned char		converted_c;
	size_t				i;

	converted_s = s;
	converted_c = c;
	i = 0;
	while (i < n)
	{
		if (converted_s[i] == converted_c)
			return ((void *)&converted_s[i]);
		i++;
	}
	return (0);
}
