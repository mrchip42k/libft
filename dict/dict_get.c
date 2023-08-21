/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 10:32:07 by ametzen           #+#    #+#             */
/*   Updated: 2023/08/21 11:23:04 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*dict_get_value_by_key(t_dict **dict, char *key)
{
	t_dict	**found_item;

	if (dict == NULL || key == NULL)
		return (NULL);
	found_item = dict_find_key(dict, key);
	if (found_item == NULL)
		return (NULL);
	return ((*found_item)->value);
}
