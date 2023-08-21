/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 09:40:59 by ametzen           #+#    #+#             */
/*   Updated: 2023/08/21 10:22:41 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

t_dict	**dict_find_key(t_dict **dict, char *key)
{
	t_dict	**pointer_to;
	t_dict	*current;

	if (dict == NULL || *dict == NULL || key == NULL)
		return (NULL);
	pointer_to = dict;
	current = *dict;
	while (current)
	{
		if (ft_strncmp(key, current->key, T_DICT_KEY_CAPACITY) == 0)
			return (pointer_to);
		pointer_to = &current->next;
		current = *pointer_to;
	}
	return (NULL);
}

t_dict	*dict_find_key_or_create(t_dict **dict, char *key)
{
	t_dict	*current;
	t_dict	**search_attempt;

	if (dict == NULL || key == NULL)
		return (NULL);
	search_attempt = dict_find_key(dict, key);
	if (search_attempt != NULL)
		return (*search_attempt);
	current = *dict;
	while (current->next)
		current = current->next;
	current->next = ft_calloc(1, sizeof(t_dict));
	if (current->next == NULL)
		return (NULL);
	current = current->next;
	ft_strlcpy(current->key, key, T_DICT_KEY_CAPACITY);
	return (current);
}
