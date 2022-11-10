/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:44:57 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/10 17:06:35 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Similar to ft_memcpy.
// Goes from right to left, skips the special case check and does not return.
static void	st_copy_left(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = len;
	while (i > 0)
	{
		i--;
		((char *)dst)[i] = ((char *)src)[i];
	}
}

// If (src) and (dst) are equal, do nothing.
// If (src) is before (dst), copy right to left.
// If (src) is after  (dst), copy left to right.
// This makes it so we never overwrite bytes that still
//  need to be read for future iterations during memmove's copy.
// This also happens to not need memcpy's special case, since it skips if the
//  two pointers are equal, regardless if they're null or not.
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (src < dst)
		st_copy_left(dst, src, len);
	else if (src > dst)
		ft_memcpy(dst, src, len);
	return (dst);
}
