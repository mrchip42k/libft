/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:44:57 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/10 10:33:45 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Necessary for size_t
#include <stddef.h>
#include "libft.h" //TODO: am i still using this?

// TODO: am i still using this? else delete the others
static void	*st_memcpy_left(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*p_dst;

	if (src == 0 && dst == 0)
		return (dst);
	p_dst = dst;
	p_dst += n - 1;
	i = 0;
	while (i >= 0)
	{
		*p_dst = *(i + (char *)src);
		p_dst--;
		i--;
	}
	return (dst);
}

// static void	st_copy_left(void *dst, const void *src, size_t len)
// {
// 	size_t	i;

// 	i = len - 1;
// 	while (i >= 0)
// 	{
// 		((char *)dst)[i] = ((char *)src)[i];
// 		i--;
// 	}
// }

// // Similar to ft_memcpy TODO: is this redundant? If not, specify the difference
// static void	st_copy_right(void *dst, const void *src, size_t len)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < len)
// 	{
// 		((char *)dst)[i] = ((char *)src)[i];
// 		i++;
// 	}
// }

// If (src) and (dst) are equal, do nothing.
// If (src) is before (dst), copy right to left.
// If (src) is after  (dst), copy left to right.
// This makes it so we never overwrite bytes that still
//  need to be read for future iterations during memmove's copy.
// This also happens to not memcpy's special case, since it skips if the two
//  pointers are equal, even if they're not null.
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (src < dst)
		// st_copy_left(dst, src, len);
		st_memcpy_left(dst, src, len);
	else if (src > dst)
		// st_copy_right(dst, src, len);
		ft_memcpy(dst, src, len);
	return (dst);
}
