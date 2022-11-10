/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:22:45 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/10 13:31:00 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Necessary for size_t
#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*ch1;
	const unsigned char	*ch2;

	ch1 = s1;
	ch2 = s2;
	i = 0;
	while (i < n)
	{
		if (ch1[i] != ch2[i])
			return (ch1[i] - ch2[i]);
		i++;
	}
	return (0);
}
