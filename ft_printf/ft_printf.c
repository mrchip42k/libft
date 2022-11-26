/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:24:27 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/22 16:23:27 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  This is the "main" file, containing ft_printf().                          */

#include "ft_printf.h"

static size_t	st_findsize(t_list *block_list)
{
	size_t			result;
	t_list			*current_lst;
	struct s_block	*current_block;

	result = 0;
	current_lst = block_list;
	while (current_lst)
	{
		current_block = current_lst->content;
		if (current_block->is_null)
			result++;
		else
			result += ft_prot_strlen(current_block->final_content);
		current_lst = current_lst->next;
	}
	return (result);
}

static void	st_copy(t_list *block_list, char *start)
{
	t_list			*current_lst;
	struct s_block	*current_block;
	size_t			i;
	size_t			sub_size;

	i = 0;
	current_lst = block_list;
	while (current_lst)
	{
		current_block = current_lst->content;
		if (current_block->is_null)
			start[i++] = '\0';
		else
		{
			sub_size = ft_strlen(current_block->final_content);
			ft_memcpy(start + i, current_block->final_content, sub_size);
			i += ft_strlen(current_block->final_content);
		}
		current_lst = current_lst->next;
	}
}

static char	*st_combine(size_t *size, t_list *block_list)
{
	char			*charr;

	*size = st_findsize(block_list);
	charr = malloc(*size);
	if (charr == NULL)
		return (NULL);
	st_copy(block_list, charr);
	return (charr);
}

// fmt isn't NULL or an empty string.
// Like printf, with FD and va_list
ssize_t	ftt_write_and_return(int fd, const char *fmt, va_list args)
{
	char	*final_charr;
	size_t	final_size;
	ssize_t	ret;
	t_list	*block_list;

	block_list = ftt_parse_fmt(fmt, args);
	if (block_list == NULL)
		return (-1);
	final_charr = st_combine(&final_size, block_list);
	if (final_charr == NULL)
		ret = -1;
	else
	{
		ret = write(fd, final_charr, final_size);
		free(final_charr);
	}
	ftt_clear_blocks(block_list);
	return (ret);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	ssize_t	print_length;

	if (fmt == NULL)
		return (-1);
	if (fmt[0] == '\0')
		return (0);
	va_start(args, fmt);
	print_length = ftt_write_and_return(1, fmt, args);
	va_end(args);
	return (print_length);
}
