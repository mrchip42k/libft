/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prot_memchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:53:30 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/14 12:57:03 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_prot_memchr(const void *s, int c, size_t n)
{
	if (s == NULL || n == 0)
		return (NULL);
	return (ft_memchr(s, c, n));
}
