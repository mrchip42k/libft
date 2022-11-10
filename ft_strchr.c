/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:41:48 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/10 17:07:06 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	converted_c;
	size_t	i;

	converted_c = c;
	i = 0;
	if (converted_c == '\0')
	{
		while (s[i])
			i++;
		return ((void *)&s[i]);
	}
	else
	{
		while (s[i])
		{
			if (converted_c == s[i])
				return ((void *)&s[i]);
			i++;
		}
		return (0);
	}
}
