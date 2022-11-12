/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_left.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:02:10 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/12 17:05:30 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memcpy_left(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = len;
	while (i > 0)
	{
		i--;
		((char *)dst)[i] = ((char *)src)[i];
	}
}
