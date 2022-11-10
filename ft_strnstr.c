/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:25:49 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/10 15:41:37 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Necessary for size_t
#include <stddef.h>

// We could also stop if there is not enough space to find the needle,
//  that would be done by precalculating lengths,
// might be slightly slower for small searches, and faster for very large needle
static char	*st_search(const char *haystack, const char *needle, size_t len)
{
	size_t	haystack_i;
	size_t	needle_i;
	size_t	last_find_idx;

	last_find_idx = 0;
	haystack_i = 0;
	needle_i = 0;
	while (haystack_i < len && haystack[haystack_i])
	{
		if (haystack[haystack_i] == needle[needle_i])
		{
			if (needle_i == 0)
				last_find_idx = haystack_i;
			needle_i++;
			if (needle[needle_i] == '\0')
				return ((char *)&haystack[last_find_idx]);
		}
		else
		{
			haystack_i -= needle_i;
			needle_i = 0;
		}
		haystack_i++;
	}
	return (0);
}

// (len) is the limit of (haystack), not (needle)
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (needle[0] == '\0')
		return ((char *)haystack);
	return (st_search(haystack, needle, len));
}
