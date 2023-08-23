/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 09:40:59 by ametzen           #+#    #+#             */
/*   Updated: 2023/08/23 14:02:51 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

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
	t_dict	*new;

	if (dict == NULL || key == NULL)
		return (NULL);
	search_attempt = dict_find_key(dict, key);
	if (search_attempt != NULL)
		return (*search_attempt);
	new = ft_calloc(1, sizeof(t_dict));
	if (new == NULL)
		return (NULL);
	if (*dict == NULL)
		*dict = new;
	else
	{
		current = *dict;
		while (current->next)
			current = current->next;
		current->next = new;
	}
	ft_strlcpy(new->key, key, T_DICT_KEY_CAPACITY);
	new->next = NULL;
	new->value = NULL;
	return (new);
}
