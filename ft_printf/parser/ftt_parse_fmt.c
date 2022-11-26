/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftt_parse_fmt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:55:54 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/22 13:58:10 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_list	*ftt_parse_fmt(const char *fmt, va_list args)
{
	t_list	*block_list;

	block_list = ftt_parse1_find_splits(fmt);
	if (block_list == NULL)
		return (NULL);
	block_list = ftt_parse2_dup_fmt(block_list, fmt);
	if (block_list == NULL)
		return (NULL);
	block_list = ftt_parse3_result(block_list, args);
	return (block_list);
}
