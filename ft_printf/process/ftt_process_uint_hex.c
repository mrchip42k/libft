/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftt_process_uint_hex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:34:56 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/21 17:25:03 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

bool	ftt_process_uint_hex(struct s_block *block, va_list args,
			char *base)
{
	unsigned int	arg;

	arg = va_arg(args, unsigned int);
	block->final_content = ftt_num2str_base((long long) arg, base);
	return (block->final_content != NULL);
}
