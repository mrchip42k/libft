/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:24:27 by ametzen           #+#    #+#             */
/*   Updated: 2023/03/25 18:58:16 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*st_combine(size_t *size, t_list *block_list)
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
	char	*formatted_result;
	size_t	final_size;
	ssize_t	ret;

	formatted_result = ft_fmt_va(fmt, args, &final_size);
	if (formatted_result == NULL)
		ret = -1;
	else
	{
		ret = write(fd, formatted_result, final_size);
		free(formatted_result);
	}
	return (ret);
}
