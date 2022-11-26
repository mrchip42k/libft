/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:28:52 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/26 14:43:51 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_raw_line(int fd, t_buf *buf);
char	*gnl_make_clean_line(char *raw_line);
void	gnl_clean_buf(t_buf *buf);

char	*get_next_line(int fd)
{
	char			*line;
	char			*raw_line;
	static t_buf	buf;

	if (fd < 0)
	{
		buf.size = -1;
		return (NULL);
	}
	raw_line = gnl_raw_line(fd, &buf);
	if (raw_line == NULL)
		return (NULL);
	line = gnl_make_clean_line(raw_line);
	gnl_clean_buf(&buf);
	free(raw_line);
	return (line);
}

// Returns:
// -> Heap String with a newline, and possibly excess content
//            ... without newline (if last line of file has content)
// -> NULL if the file has ended
//     ... if any error occurred
char	*gnl_raw_line(int fd, t_buf *buf)
{
	char	*wip_line;
	bool	first;

	first = true;
	wip_line = NULL;
	while (!gnl_has_newline(wip_line, buf))
	{
		if (!first || buf->size <= 0)
			buf->size = read(fd, buf->chars, BUFFER_SIZE);
		wip_line = gnl_extend(wip_line, buf);
		if (wip_line == NULL || buf->size < 0)
		{
			if (wip_line)
				free (wip_line);
			return (NULL);
		}
		if (buf->size == 0)
			break ;
		first = false;
	}
	if (wip_line == NULL)
		return (gnl_extend(NULL, buf));
	return (wip_line);
}

// Returns:
// -> Heap String, final result
// -> NULL if internal error
// (raw_line) is not NULL when this is called
// end_idx: Either the index where the first newline is found,
//          or the length of raw_line if none is found.
char	*gnl_make_clean_line(char *raw_line)
{
	char	*line;
	ssize_t	end_idx;

	end_idx = 0;
	while (raw_line[end_idx] && raw_line[end_idx] != '\n')
		end_idx++;
	if (raw_line[end_idx] == '\n')
		end_idx++;
	line = malloc(end_idx + 1);
	if (line == NULL)
		return (NULL);
	gnl_memcpy(line, raw_line, end_idx);
	line[end_idx] = '\0';
	return (line);
}

// Moves buffer content to eliminate up to, and including the first newline.
void	gnl_clean_buf(t_buf *buf)
{
	ssize_t	start_idx;

	start_idx = 0;
	while (start_idx++ < buf->size)
		if (buf->chars[start_idx - 1] == '\n')
			break ;
	if (start_idx >= buf->size)
	{
		buf->size = 0;
		return ;
	}
	gnl_memcpy(buf->chars, buf->chars + start_idx, buf->size - start_idx);
	buf->size -= start_idx;
}
