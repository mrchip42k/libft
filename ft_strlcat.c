/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:00:58 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/13 10:22:25 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	src_i;

	src_len = ft_strlen(src);
	dst_len = ft_prot_strlen(dst);
	if (dstsize == 0 || dstsize < dst_len)
		return (dstsize + src_len);
	src_i = 0;
	while (src_i < src_len && ((dst_len + src_i) < (dstsize - 1)))
	{
		dst[dst_len + src_i] = src[src_i];
		src_i++;
	}
	dst[dst_len + src_i] = '\0';
	return (dst_len + src_len);
}
