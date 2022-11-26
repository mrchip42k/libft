/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftt_parse2_dup_fmt.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:22:00 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/19 15:25:38 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static size_t	st_calc_str_len(const char *fmt,
		struct s_block *current, t_list *next_list)
{
	size_t			count;
	size_t			i;
	struct s_block	*next;

	if (next_list == NULL)
	{
		count = 0;
		i = current->fmt_start_idx;
		while (fmt[i + count])
			count++;
		return (count);
	}
	else
	{
		next = next_list->content;
		return (next->fmt_start_idx - current->fmt_start_idx);
	}
}

t_list	*ftt_parse2_dup_fmt(t_list *block_list, const char *fmt)
{
	struct s_block	*block;
	t_list			*list_item;
	char			*new_string;
	size_t			new_string_len;
	size_t			i;

	list_item = block_list;
	i = 0;
	while (list_item)
	{
		block = list_item->content;
		new_string_len = st_calc_str_len(fmt, block, list_item->next);
		new_string = malloc(new_string_len + 1);
		if (new_string == NULL)
			return (ftt_clear_blocks(block_list));
		ft_memcpy(new_string, &fmt[block->fmt_start_idx], new_string_len);
		new_string[new_string_len] = '\0';
		block->fmt_content = new_string;
		list_item = list_item->next;
	}
	return (block_list);
}
