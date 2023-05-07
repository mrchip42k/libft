/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anylist_new_item.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:27:36 by ametzen           #+#    #+#             */
/*   Updated: 2023/05/07 19:40:19 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../anytype.h"

t_anylist		*anylist_new_item()
{
	t_anylist	*new_item;

	new_item = malloc(sizeof(t_anylist));
	if (new_item == NULL)
		return (NULL);
	new_item->next = NULL;
	new_item->any_content.type = e_any_type_none;
	return (new_item);
}
