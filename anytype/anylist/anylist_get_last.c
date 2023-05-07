/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anylist_get_last.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:18:48 by ametzen           #+#    #+#             */
/*   Updated: 2023/05/07 19:31:31 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../anytype.h"

t_anylist	*anylist_get_last(const t_anylist *search_start_item)
{
	t_anylist	*current;

	if (search_start_item == NULL)
		return (NULL);
	current = (t_anylist *)search_start_item;
	while (current->next)
	{
		current = current->next;
	}
	return (current);
}
