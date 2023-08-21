/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 09:50:51 by ametzen           #+#    #+#             */
/*   Updated: 2023/08/21 11:23:06 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_dict	*dict_pop_key(t_dict **dict, char *key)
{
	t_dict	**item_pointer;
	t_dict	*item;

	if (dict == NULL || key == NULL)
		return (NULL);
	item_pointer = dict_find_key(dict, key);
	if (item_pointer == NULL)
		return (NULL);
	item = *item_pointer;
	*item_pointer = item->next;
	item->next = NULL;
	return (item);
}
