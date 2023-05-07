/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anylist_add_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:34:57 by ametzen           #+#    #+#             */
/*   Updated: 2023/05/07 19:28:42 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../anytype.h"

t_any_error	anylist_add_front(t_anylist **destination, t_anylist *new)
{
	if (new == NULL || destination == NULL)
		return (e_any_error_input);
	if (*destination)
	{
		new->next = *destination;
	}
	*destination = new;
	return (e_any_error_ok);
}
