/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:28:53 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/26 17:09:33 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Project allows system calls: read(), malloc() and free().

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

//malloc, free
# include <stdlib.h>
//read
# include <unistd.h>
# include <stdbool.h>

// Due to SIGNED size_t, both read() and this struct will break if BUFFER_SIZE
// ever needed to be larger than 9 exabytes.
// Unacceptable.
// size is directly out of read().
// Therefore, 
// size > 0: Read successfully
// size == 0: EOF reached
// size < 0: Error!
typedef struct s_buf
{
	ssize_t	size;
	char	chars[BUFFER_SIZE];
}			t_buf;

//  get_next_line.c  ///////////////////////////////////////////////////////////
// NOTE Deleted get_next_line's prototype, so it can stay just in libft.h

//  get_next_line_utils.c  /////////////////////////////////////////////////////

// 💥 (dst || src) == NULL
// Modified: no special case; no return instead of (dst)
void	gnl_memcpy(void *dst, const void *src, size_t n);

// Returns:
// -> Heap String, with ((previous)) and (buf) concatenated
// -> NULL if internal error
//     ... if (previous) == NULL && (buf)size <= 0 (consecutive EOF reads/ err)
// (previous) may be NULL, in that case (buf) is duplicated
// (previous) will be freed
// 💥 (buf) == NULL (buf should always be available, caller needs to fix)
char	*gnl_extend(char *previous, t_buf *buf);

// Returns:
// -> true if no newline has been found
// -> false if a newline has been found
// (buf) will be looked at if (wip_line) is NULL.
bool	gnl_has_newline(char *wip_line, t_buf *buf);

#endif
