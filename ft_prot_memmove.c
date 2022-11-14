/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prot_memmove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:29:16 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/14 13:14:48 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_prot_memmove(void *dst, const void *src, size_t len)
{
	if (dst == NULL || src == NULL)
		return (dst);
	return (ft_memmove(dst, src, len));
}
