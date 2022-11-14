/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prot_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:10:20 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/14 12:57:11 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_prot_memcpy(void *dst, const void *src, size_t n)
{
	if (src == NULL || dst == NULL)
		return (dst);
	return (ft_memcpy(dst, src, n));
}
