/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anylist_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:53:17 by ametzen           #+#    #+#             */
/*   Updated: 2023/05/07 19:31:11 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../anytype.h"

u_int64_t	anylist_count(const t_anylist *start)
{
	u_int64_t	count;
	t_anylist	*current;

	if (start == NULL)
		return (0);
	count = 1;
	current = (t_anylist *)start;
	while (current->next)
	{
		current = current->next;
		count++;
	}
	return (count);
}
