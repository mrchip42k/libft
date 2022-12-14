/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:05:10 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/26 18:08:42 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Norminette line savings
static t_list	*st_nevermind(t_list **delete_this, void (*del)(void *))
{
	ft_lstclear(delete_this, del);
	return (NULL);
}

// Norminette line savings
static void	st_null_last_next(t_list *last)
{
	if (last)
	{
		last->next = NULL;
	}
}

// If (lst) is NULL, *ft_lstmap does nothing and returns NULL.*
// If ( del() ) is NULL, ft_lstmap won't be able to free new things if something
//  fails. This would either:
//  - segfault if ft_lstmap tries calling ( del() ) anyways
//  - leak memory if ft_lstmap skips calling ( del() ) if it doesnt exist.
//  The compromise i chose: is to refuse doing the map.
//  **ft_lstmap does nothing and returns NULL.*
// If ( f() ) is NULL, it could make sense to create a new list with equal
//  content. However:
//  ft_lstmap can't duplicate content. That would require specialized functions.
//  ft_lstmap also shouldnt point to the original contents, since using a map
//  works on the assumption that the result is a copy.
//  **ft_lstmap does nothing and returns NULL.*

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*original_item;
	t_list	**next;
	t_list	*new_previous;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	next = &new_list;
	original_item = lst;
	new_previous = NULL;
	while (original_item)
	{
		*next = malloc(sizeof(t_list));
		if (*next == NULL)
			return (st_nevermind(&new_list, del));
		(*next)->content = f(original_item->content);
		if (new_previous)
			new_previous->next = (*next);
		new_previous = *next;
		original_item = original_item->next;
		next = &((*next)->next);
	}
	st_null_last_next(new_previous);
	return (new_list);
}
