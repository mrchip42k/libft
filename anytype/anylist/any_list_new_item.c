/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   any_list_new_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:27:36 by ametzen           #+#    #+#             */
/*   Updated: 2023/05/04 16:34:17 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../anytype.h"

t_any_list		*any_list_new_item()
{
	t_any_list	*new_item;

	new_item = malloc(sizeof(t_any_list));
	if (new_item == NULL)
		return (NULL);
	new_item->prev = NULL;
	new_item->next = NULL;
	new_item->any.type = e_any_type_none;
	return (new_item);
}
