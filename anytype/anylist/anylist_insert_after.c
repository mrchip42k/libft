/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anylist_insert_after.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:19:49 by ametzen           #+#    #+#             */
/*   Updated: 2023/05/07 19:26:18 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../anytype.h"

t_any_error	anylist_insert_after(t_anylist **destination, t_anylist *item)
{
	if (destination == NULL || item == NULL)
		return (e_any_error_input);
		
	if (*destination)
		item->next = *destination;
	*destination = item;
	
}
