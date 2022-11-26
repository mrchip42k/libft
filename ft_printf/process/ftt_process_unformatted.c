/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftt_process_unformatted.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:41:11 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/19 15:43:37 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

bool	ftt_process_unformatted(struct s_block *block)
{
	block->final_content = ft_prot_strdup(block->fmt_content);
	return (block->final_content != NULL);
}
