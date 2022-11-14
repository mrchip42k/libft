/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prot_strlcat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:43:19 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/14 12:57:21 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_prot_strlcat(char *dst, const char *src, size_t dstsize)
{
	if (src == NULL)
		return (ft_prot_strlen(dst));
	return (ft_strlcat(dst, src, dstsize));
}
