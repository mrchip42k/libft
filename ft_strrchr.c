/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:50:52 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/10 13:58:52 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Necessary for size_t
#include <stddef.h>

// Scans left to right, remembers what it found.
// This could also be made by finding the first result scanning right to left.
// There is a difference:
// if (s) has string content AFTER a first terminator, this implementation only
//  acts on the first string.
// The right to left version would be able to find things in the
//  "hidden strings", which is probably undesirable, but potentially faster.
char	*ft_strrchr(const char *s, int c)
{
	char	converted_c;
	size_t	i;
	char	*last_result;

	converted_c = c;
	last_result = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == converted_c)
			last_result = (char *)&s[i];
		i++;
	}
	if (s[i] == converted_c)
		last_result = (char *)&s[i];
	return (last_result);
}
