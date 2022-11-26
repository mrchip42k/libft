/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftt_parse1_find_splits.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:29:18 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/22 15:40:45 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static enum e_block_type	st_detect_format(size_t *i, const char *fmt,
		bool *fail)
{
	if (fmt[*i] == 'c')
		return (e_block_c_char);
	if (fmt[*i] == 's')
		return (e_block_s_string);
	if (fmt[*i] == 'p')
		return (e_block_p_hexaddress);
	if (fmt[*i] == 'd' || fmt[*i] == 'i')
		return (e_block_di_decimal);
	if (fmt[*i] == 'u')
		return (e_block_u_unsigned);
	if (fmt[*i] == 'x')
		return (e_block_x_hexmin);
	if (fmt[*i] == 'X')
		return (e_block_xx_hexmaj);
	if (fmt[*i] == '%')
		return (e_block_percent);
	*fail = true;
	return (0);
}

// Count up to the next block
// Exits when this block ended 
// (no matter if its because of another block, or if the (fmt) string ended)
// Last return should be irrelevant since fail will make the return unused.
static enum e_block_type	st_finish_str_block(size_t *i, const char *fmt,
		bool *fail)
{
	enum e_block_type	type;

	*fail = false;
	if (fmt[*i] == '%')
	{
		(*i)++;
		type = st_detect_format(i, fmt, fail);
		(*i)++;
		return (type);
	}
	else if (fmt[*i])
	{
		(*i)++;
		while (fmt[*i] && fmt[*i] != '%')
			(*i)++;
		return (e_block_unformatted);
	}
	*fail = true;
	return (e_block_unformatted);
}

// Also initializes the struct just in case
static t_list	*st_make_new(void)
{
	t_list			*new_list_item;
	struct s_block	*new_block;

	new_block = malloc(sizeof(struct s_block));
	if (new_block == NULL)
		return (NULL);
	new_block->final_content = NULL;
	new_block->fmt_content = NULL;
	new_block->fmt_start_idx = 0;
	new_block->type = 1234;
	new_block->is_null = false;
	new_list_item = ft_lstnew(new_block);
	if (new_list_item == NULL)
		free (new_block);
	return (new_list_item);
}

t_list	*ftt_parse1_find_splits(const char *fmt)
{
	t_list			*block_list;
	t_list			*new_list_item;
	struct s_block	*new_block;
	size_t			i;
	bool			fail;

	block_list = NULL;
	i = 0;
	while (fmt[i])
	{
		new_list_item = st_make_new();
		if (new_list_item == NULL)
			return (ftt_clear_blocks(block_list));
		new_block = new_list_item->content;
		ft_lstadd_back(&block_list, new_list_item);
		new_block->fmt_start_idx = i;
		new_block->type = st_finish_str_block(&i, fmt, &fail);
		if (fail)
			return (ftt_clear_blocks(block_list));
	}
	return (block_list);
}
