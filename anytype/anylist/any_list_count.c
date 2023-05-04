/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   any_list_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:53:17 by ametzen           #+#    #+#             */
/*   Updated: 2023/05/04 16:56:30 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../anytype.h"

u_int64_t	any_list_count(const t_any_list *start)
{
	u_int64_t		result;
	t_any_list	*current;

	if (start == NULL)
		return (0);
	result = 1;
	current = (t_any_list *)start;
	while (current->next)
	{
		current = current->next;
		result++;
	}
	return (result);
}
