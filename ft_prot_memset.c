/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prot_memset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:06:34 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/14 13:42:55 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_prot_memset(void *b, int c, size_t len)
{
	if (b == NULL)
		return (NULL);
	return (ft_memset(b, c, len));
}
