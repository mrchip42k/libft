/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftt_block_list_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:33:36 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/19 15:25:09 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This file includes functions to manage the linked list of s_block.         */

#include "../ft_printf.h"

void	ftt_delete_block(void *block_voidp)
{
	struct s_block	*block;

	block = block_voidp;
	if (block)
	{
		if (block->fmt_content)
			free(block->fmt_content);
		if (block->final_content)
			free(block->final_content);
		free(block);
	}
}

t_list	*ftt_clear_blocks(t_list *block_list)
{
	if (block_list)
	{
		ft_lstclear(&block_list, ftt_delete_block);
	}
	return (NULL);
}
