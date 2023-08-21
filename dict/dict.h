/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:20:52 by ametzen           #+#    #+#             */
/*   Updated: 2023/08/21 10:23:42 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_H
# define DICT_H

# include "../libft.h"

# define T_DICT_KEY_CAPACITY 4242

typedef struct s_dict {
	char			key[T_DICT_KEY_CAPACITY + 1];
	void			*value;
	struct s_dict	*next;
}		t_dict;

typedef void (t_dict_value_deleter)(void *to_delete);

// Returns the pointer to the found element (so it can be replaced)
// Return NULL if not found (even if dict is empty)
//             if (dict | key) == NULL (incorrect function use) (undetectable)
t_dict		**dict_find_key(t_dict **dict, char *key);

// ❗️ Uses: malloc()
// Returns the pointer to the found element
// Return NULL if allocation error.
//             if (dict | key) == NULL (incorrect function use) (undetectable)
t_dict		*dict_find_key_or_create(t_dict **dict, char *key);

// Replace the value on an already found element.
void		dict_item_replace_value(t_dict *element, void *new_value,
				t_dict_value_deleter *deleter);

// ❗️ Uses: malloc() free()
// Create an element, OR find and replace its value, by key name.
// Return the adress of the element if successful.
// Return NULL if allocation error.
//             if (dict | key) == NULL (incorrect function use) (undetectable)
t_dict		*dict_set_value(t_dict **dict, char *key, void *new_value,
				t_dict_value_deleter *deleter);

// Return disconnected item if found.
// Return NULL if item not found.
//             if (dict | key) == NULL (incorrect function use) (undetectable)
t_dict		*dict_pop_key(t_dict **dict, char *key);

// ❗️ Uses: free()
// Does nothing if (key) does not exist in (dict)
// Returns early if (dict | key) == NULL (incorrect function use) (undetectable)
void		dict_remove_key(t_dict **dict, char *key,
				t_dict_value_deleter *deleter);

// ❗️ Uses: free()
// Clears entire list.
void		dict_delete_all(t_dict **dict, t_dict_value_deleter *deleter);

#endif //DICT_H
