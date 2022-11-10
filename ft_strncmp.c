/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:03:54 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/10 14:24:37 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Necessary for size_t
#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*u1;
	const unsigned char	*u2;
	size_t				i;

	u1 = (unsigned char *)s1;
	u2 = (unsigned char *)s2;
	i = 0;
	while (i < n && (u1[i] || u2[i]))
	{
		if (u1[i] != u2[i])
			return (u1[i] - u2[i]);
		i++;
	}
	return (0);
}
