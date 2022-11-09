/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:56:47 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/09 14:36:41 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Necessary for malloc()
#include <stdlib.h>

// return 1 if (c) is one of (set), else return 0.
static int	st_is_trimmable(char c, char const *set)
{
	size_t	set_i;

	set_i = 0;
	while (set[set_i])
	{
		if (c == set[set_i])
			return (1);
		set_i++;
	}
	return (0);
}

static size_t	st_strlen(char const *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

// Index of first character that SHOULD NOT be trimmed,
// or index of null terminator if the string is entirely made of trimmable.
static size_t	st_find_start(char const *s1, char const *set)
{
	size_t	char_i;

	char_i = 0;
	while (s1[char_i])
	{
		if (!st_is_trimmable(s1[char_i], set))
			break ;
		char_i++;
	}
	return (char_i);
}

// Index of the first TRIMMABLE character to the right of the end block
static size_t	st_find_end(char const *s1, char const *set)
{
	size_t	char_i;
	size_t	set_i;
	int		b_found_trimmable;

	char_i = st_strlen(s1);
	while (char_i != 0)
	{
		char_i--;
		b_found_trimmable = 0;
		set_i = 0;
		while (set[set_i])
		{
			if (s1[char_i] == set[set_i])
			{
				b_found_trimmable = 1;
				break ;
			}
			set_i++;
		}
		if (!b_found_trimmable)
			return (char_i + 1);
	}
	return (char_i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_string;
	size_t	start_idx;
	size_t	end_idx;

	start_idx = st_find_start(s1, set);
	end_idx = st_find_end(s1, set);
	new_string = malloc(end_idx - start_idx + 1);
	if (new_string)
	{
		
		new_string[end_idx - start_idx] = '\0';
	}
	return (new_string);
}
