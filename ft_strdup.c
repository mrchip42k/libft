/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:57:36 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/11 09:46:56 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Deliberately setting errno = ENOMEM; is not needed since malloc() already
//  does it.

char	*ft_strdup(const char *s1)
{
	char	*new_string;
	size_t	len;

	len = ft_strlen(s1);
	new_string = malloc(len + 1);
	if (new_string)
	{
		ft_memcpy(new_string, s1, len + 1);
	}
	return (new_string);
}
