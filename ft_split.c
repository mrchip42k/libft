/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:25:50 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/09 17:06:42 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Necessary for malloc() and free()
#include <stdlib.h>

static size_t	st_count_words(char const *s, char separator)
{
	size_t	word_count;
	size_t	i;
	char	b_is_sep;
	char	b_was_sep;

	b_was_sep = 1;
	word_count = 0;
	i = 0;
	while (s[i])
	{
		b_is_sep = s[i] == separator;
		if (!b_is_sep && b_was_sep)
			word_count++;
		i++;
		b_was_sep = b_is_sep;
	}
	return (word_count);
}

// This function updates (*char_i)
// Must be called when there are still words following (char_i)
// (s) the start of the string passed to ft_split()
// (char_i) the character index to start from, potentially separator
// (separator) character
// (dest) where to malloc to
static void	st_handle_word(char const *s, size_t *char_i,
								char separator, char **dest)
{
	size_t	word_start_idx;
	size_t	write_i;

	// Skip initial separators
	while (s[*char_i] == separator)
		*char_i += 1;
	word_start_idx = *char_i;
	// Get the word length
	while (s[*char_i] && s[*char_i] != separator)
		*char_i += 1;
	// Alloc string
	*dest = malloc((*char_i - word_start_idx) + 1);
	if (*dest)
	{
		// Copy
		write_i = 0;
		while (write_i < (*char_i - word_start_idx))
		{
			(*dest)[write_i] = s[word_start_idx + write_i];
			write_i++;
		}
		(*dest)[*char_i - word_start_idx] = '\0';
	}
}

// When allocating a string fails, ft_split wants to return a null pointer.
// That way, users of the function only need to check if the array is null,
//   then they know the rest must be valid.
// However, before quitting, every string that was successfully allocated,
//   and the array have to be free()d to avoid leaks.
// I'm not certain if this behavior is *required* by the exercise, however
// it seems like a sensible choice.
static void	st_abort(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	**ft_split(char const *s, char c)
{
	char	**new_array;
	size_t	word_count;
	size_t	word_i;
	size_t	char_i;

	word_count = st_count_words(s, c);
	new_array = malloc(sizeof(*new_array) * (word_count + 1));
	if (new_array)
	{
		char_i = 0;
		word_i = 0;
		while (word_i < word_count)
		{
			st_handle_word(s, &char_i, c, &new_array[word_i]);
			if (new_array[word_i] == 0)
			{
				st_abort(new_array);
				return (0);
			}
			word_i++;
		}
		new_array[word_count] = 0;
	}
	return (new_array);
}
