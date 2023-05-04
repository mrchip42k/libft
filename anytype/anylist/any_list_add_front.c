/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   any_list_add_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:34:57 by ametzen           #+#    #+#             */
/*   Updated: 2023/05/04 16:50:23 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../anytype.h"

t_any_error	any_list_add_front(t_any_list **start, t_any_list *new)
{
	if (new == NULL || start == NULL)
		return (e_any_error_input);
	if (*start)
	{
		new->next = *start;
		(*start)->prev = new;
	}
	*start = new;
	return (e_any_error_ok);
}
