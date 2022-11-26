/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftt_process_percent.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:54:59 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/19 16:57:52 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

bool	ftt_process_percent(struct s_block *block)
{
	block->final_content = ft_prot_strdup("%");
	return (block->final_content != NULL);
}
