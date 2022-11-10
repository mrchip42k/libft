/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:05:10 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/10 18:39:25 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	}
	return (new_list);
}
