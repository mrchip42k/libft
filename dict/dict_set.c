/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:40:54 by ametzen           #+#    #+#             */
/*   Updated: 2023/08/21 10:23:53 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

void	dict_item_replace_value(t_dict *element, void *new_value,
			t_dict_value_deleter *deleter)
{
	if (element == NULL)
		return ;
	if (element->value && deleter)
		deleter(element->value);
	element->value = new_value;
}

t_dict	*dict_set_value(t_dict **dict, char *key, void *new_value,
			t_dict_value_deleter *deleter)
{
	t_dict	*element;

	if (dict == NULL || key == NULL)
		return (NULL);
	element = dict_find_key_or_create(dict, key);
	if (element == NULL)
		return (NULL);
	dict_item_replace_value(element, new_value, deleter);
	return (element);
}
