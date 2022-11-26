/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:28:51 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/26 12:42:06 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	gnl_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
}

char	*gnl_extend(char *previous, t_buf *buf)
{
	char	*result;
	ssize_t	prev_len;
	ssize_t	i;

	prev_len = 0;
	if (previous == NULL && buf->size <= 0)
		return (NULL);
	else if (previous)
		while (previous[prev_len])
			prev_len++;
	result = malloc(prev_len + buf->size + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < prev_len)
	{
		result[i] = previous[i];
		i++;
	}
	while (i++ - prev_len < buf->size)
		result[i - 1] = buf->chars[i - prev_len - 1];
	result[prev_len + buf->size] = '\0';
	if (previous)
		free (previous);
	return (result);
}

bool	gnl_has_newline(char *wip_line, t_buf *buf)
{
	ssize_t	i;

	i = 0;
	if (wip_line == NULL)
	{
		if ((buf->size) == 0)
			return (false);
		while (i < buf->size)
		{
			if (buf->chars[i] == '\n')
				return (true);
			i++;
		}
		return (false);
	}
	while (wip_line[i])
	{
		if (wip_line[i] == '\n')
			return (true);
		i++;
	}
	return (false);
}
