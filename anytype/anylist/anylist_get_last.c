/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   any_list_get_last.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:18:48 by ametzen           #+#    #+#             */
/*   Updated: 2023/05/04 17:27:11 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../anytype.h"

t_anylist	*anylist_get_last(const t_anylist *start)
{
	t_anylist	*current;

	if (start == NULL)
		return (NULL);
	current = (t_anylist *)start;
	while (current->next)
	{
		current = current->next;
	}
	return (current);
}
