/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 08:51:56 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/10 17:07:15 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_string;
	size_t	len1;
	size_t	len2;
	size_t	i;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new_string = malloc(len1 + len2 + 1);
	if (new_string)
	{
		i = 0;
		while (i < len1)
		{
			new_string[i] = s1[i];
			i++;
		}
		i = 0;
		while (i < len2)
		{
			new_string[len1 + i] = s2[i];
			i++;
		}
		new_string[len1 + len2] = '\0';
	}
	return (new_string);
}
