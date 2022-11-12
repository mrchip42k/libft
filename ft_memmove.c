/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:44:57 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/12 17:01:56 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
		ft_memcpy_left(dst, src, len);
	else if (src > dst)
		ft_memcpy(dst, src, len);
	return (dst);
}
