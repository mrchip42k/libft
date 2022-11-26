/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftt_process_hexaddress.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:49:02 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/22 12:39:10 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static size_t	st_calc_size(size_t addr)
{
	size_t	result;

	result = 0;
	while (addr > 0)
	{
		result++;
		addr /= 0x10;
	}
	return (result);
}

static char	*st_addr2str(size_t addr)
{
	char	*result;
	size_t	size;
	size_t	i;

	if (addr == 0)
		return (ft_strdup("0x0"));
	size = 2 + st_calc_size(addr);
	result = malloc(size + 1);
	if (result == NULL)
		return (NULL);
	result[0] = '0';
	result[1] = 'x';
	i = size - 1;
	while (i > 1)
	{
		result[i] = "0123456789abcdef"[addr % 0x10];
		i--;
		addr /= 0x10;
	}
	result[size] = '\0';
	return (result);
}

bool	ftt_process_hexaddress(struct s_block *block, va_list args)
{
	size_t	arg;

	arg = va_arg(args, size_t);
	block->final_content = st_addr2str((long long)arg);
	return (block->final_content != NULL);
}
