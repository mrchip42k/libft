/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prot_strlcpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:35:00 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/14 12:57:26 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_prot_strlcpy(char *dst, const char *src, size_t dstsize)
{
	if (dst == NULL || src == NULL)
		return (ft_prot_strlen(src));
	return (ft_strlcpy(dst, src, dstsize));
}
