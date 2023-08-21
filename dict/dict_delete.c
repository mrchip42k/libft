/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_delete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 09:51:23 by ametzen           #+#    #+#             */
/*   Updated: 2023/08/21 11:22:57 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	dict_delete_one(t_dict *to_delete, t_dict_value_deleter *deleter)
{
	if (to_delete == NULL)
		return ;
	if (deleter && to_delete->value)
		deleter(to_delete->value);
	free(to_delete);
}

void	dict_remove_key(t_dict **dict, char *key, t_dict_value_deleter *deleter)
{
	if (dict == NULL || key == NULL)
		return ;
	dict_delete_one(dict_pop_key(dict, key), deleter);
}

void	dict_delete_all(t_dict **dict, t_dict_value_deleter *deleter)
{
	t_dict	*current;
	t_dict	*next;

	current = *dict;
	while (current)
	{
		next = current->next;
		dict_delete_one(current, deleter);
		current = next;
	}
	*dict = NULL;
}
