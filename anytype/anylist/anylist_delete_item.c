/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anylist_delete_item.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:48:41 by ametzen           #+#    #+#             */
/*   Updated: 2023/05/07 21:01:17 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../anytype.h"

t_any_error	anylist_delete_item(t_anylist **item)
{
	if (item == NULL)
		return (e_any_error_input);
	if (*item == NULL)
		return (e_any_error_ok);
	any_try_destroy(&(*item)->any_content);
	free(*item);
	*item = NULL;
	return (e_any_error_ok);
}
