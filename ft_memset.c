/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:01:44 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/11 09:46:33 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// why is (c) an int? we're writing single bytes anyways.

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*dest;

	dest = b;
	i = 0;
	while (i < len)
	{
		*dest = c;
		i++;
		dest++;
	}
	return (b);
}
