/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:05:10 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/11 13:58:29 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* //TODO: delete?
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*original_current;
	t_list	**write_here_RENAME;

	new_list = NULL;
	if (lst)
	{
		original_current = lst;
		write_here_RENAME = &new_list;
		while (original_current)
		{
			*write_here_RENAME = malloc(sizeof(t_list));
			if (*write_here_RENAME == NULL)
			{
				ft_lstclear(&new_list, del);
				return (NULL);
			}
			(*write_here_RENAME)->content = f(original_current->content);
			write_here_RENAME = &(*write_here_RENAME)->next;
			original_current = original_current->next;
		}
		(*write_here_RENAME)->next = NULL; // added today
	}
	return (new_list);
}
*/

// TODO: is this still true? Update libft.h
// 	Protect as long as paco sees segfaults and aborts, 
//  try letting ft_lstmap segfault if ( del() ) == NULL to avoid user confusion.
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

/* //TODO: delete?
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*current_lst;
	t_list	*current_new;
	t_list	*past_new;

	new_lst = malloc(sizeof(t_list));
	if (lst == NULL || f == NULL || del == NULL || new_lst == NULL)
		return (NULL);
	current_lst = lst;
	current_new = new_lst;
	past_new = NULL;
	while (current_lst)
	{
		if (current_new == NULL) // needed to skip first iteration
			current_new = malloc(sizeof(t_list));
		if (current_new == NULL) // this time check allocation worked
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		current_new->content = f(current_lst->content);
		if (past_new)
			past_new->next = current_new;
		past_new = current_new;
		current_lst = current_lst->next;
		current_new = NULL;
	}
	return (new_lst);
}
*/

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
