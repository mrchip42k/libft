/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:33:04 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/10 13:40:06 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Necessary for size_t
#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ch_s;
	unsigned char		ch_c;
	size_t				i;

	ch_s = s;
	ch_c = c;
	i = 0;
	while (i < n)
	{
		if (ch_s[i] == ch_c)
			return ((void *)&ch_s[i]);
		i++;
	}
	return (0);
}
