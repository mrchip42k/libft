/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:11:14 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/10 17:06:00 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*new_mem;
	size_t	total_bytes;

	total_bytes = count * size;
	new_mem = malloc(total_bytes);
	if (new_mem)
		ft_memset(new_mem, 0, total_bytes);
	return (new_mem);
}
