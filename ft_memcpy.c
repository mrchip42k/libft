/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:25:44 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/09 18:49:21 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Necessary for size_t
#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*p_dst;

	if (src == 0 && dst == 0)
		return (dst);
	p_dst = dst;
	i = 0;
	while (i < n)
	{
		*p_dst = *(i + (char *)src);
		p_dst++;
		i++;
	}
	return (dst);
}
