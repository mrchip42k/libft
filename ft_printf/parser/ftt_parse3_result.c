/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftt_parse3_result.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:02:34 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/22 13:51:44 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

// last return never happens
static bool	st_block_dispatcher(struct s_block *block, va_list args)
{
	if (block->type == e_block_unformatted)
		return (ftt_process_unformatted(block));
	else if (block->type == e_block_c_char)
		return (ftt_process_char(block, args));
	else if (block->type == e_block_s_string)
		return (ftt_process_string(block, args));
	else if (block->type == e_block_p_hexaddress)
		return (ftt_process_hexaddress(block, args));
	else if (block->type == e_block_di_decimal)
		return (ftt_process_sint_decimal(block, args));
	else if (block->type == e_block_u_unsigned)
		return (ftt_process_uint_decimal(block, args));
	else if (block->type == e_block_x_hexmin)
		return (ftt_process_uint_hex(block, args, "0123456789abcdef"));
	else if (block->type == e_block_xx_hexmaj)
		return (ftt_process_uint_hex(block, args, "0123456789ABCDEF"));
	else if (block->type == e_block_percent)
		return (ftt_process_percent(block));
	return (false);
}

t_list	*ftt_parse3_result(t_list *block_list, va_list args)
{
	t_list			*current_list;
	struct s_block	*current_block;
	bool			success;

	current_list = block_list;
	while (current_list)
	{
		current_block = current_list->content;
		success = st_block_dispatcher(current_block, args);
		if (!success)
			return (ftt_clear_blocks(block_list));
		current_list = current_list->next;
	}
	return (block_list);
}
