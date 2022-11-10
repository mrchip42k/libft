/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:25:44 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/10 17:06:30 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// https://github.com/alelievr/libft-unit-test wants me to add the first
//  if special case.
// I don't understand why this is a good behaviour, or why the function
//  can't also skip if either of them are null (|| instead of &&).
// Unless this behaviour comes from the original memcpy, and had to be carried
//  on for compatibility.
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (src == 0 && dst == 0)
		return (dst);
	i = 0;
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}
