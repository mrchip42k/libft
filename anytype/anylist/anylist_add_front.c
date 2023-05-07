/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anylist_add_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:34:57 by ametzen           #+#    #+#             */
/*   Updated: 2023/05/07 19:18:39 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../anytype.h"

//TODO detect if there was an item before *start.
//     And relink that if needed

t_any_error	anylist_add_front(t_anylist **start, t_anylist *new)
{
	if (new == NULL || start == NULL)
		return (e_any_error_input);
	if (*start)
	{
		new->next = *start;
		(*start)->prev = new;
	}
	new->prev = NULL;
	*start = new;
	return (e_any_error_ok);
}
