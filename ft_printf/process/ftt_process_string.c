/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftt_process_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:43:49 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/22 14:15:47 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

bool	ftt_process_string(struct s_block *block, va_list args)
{
	char	*original;

	original = va_arg(args, char *);
	if (original == NULL)
		block->final_content = ft_strdup("(null)");
	else
		block->final_content = ft_prot_strdup(original);
	return (block->final_content != NULL);
}
