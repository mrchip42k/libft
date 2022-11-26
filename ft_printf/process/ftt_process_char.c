/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftt_process_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:02:33 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/22 15:44:58 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

// va_arg needs int type because it's promoted

bool	ftt_process_char(struct s_block *block, va_list args)
{
	char	c;

	c = va_arg(args, int);
	block->final_content = malloc(2);
	if (block->final_content == NULL)
		return (false);
	if (c == '\0')
	{
		block->final_content[0] = 'X';
		block->is_null = true;
	}
	else
		block->final_content[0] = c;
	block->final_content[1] = '\0';
	return (true);
}
