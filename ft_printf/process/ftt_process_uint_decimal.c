/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftt_process_uint_decimal.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:27:36 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/26 17:22:06 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

bool	ftt_process_uint_decimal(struct s_block *block, va_list args)
{
	unsigned int	arg;

	arg = va_arg(args, unsigned int);
	block->final_content = ft_num2str((long long) arg);
	return (block->final_content != NULL);
}
