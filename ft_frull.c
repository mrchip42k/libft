/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frull.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:42:17 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/26 16:45:09 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_frull(void **ptr)
{
	if (ptr)
	{
		if (*ptr)
		{
			free(*ptr);
			*ptr = NULL;
		}
	}
	return (NULL);
}
