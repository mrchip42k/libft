/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:55:57 by ametzen           #+#    #+#             */
/*   Updated: 2023/03/29 18:32:05 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*pop_last(t_list **lst)
{
	t_list	*last;
	t_list	**pointer_to_last;

	pointer_to_last = lst;
	last = *pointer_to_last;
	if (last == NULL)
		return (NULL);
	while (last->next != NULL)
	{
		pointer_to_last = &last->next;
		last = last->next;
	}
	*pointer_to_last = NULL;
	return (last);
}

static t_list	*pop_forward(t_list **lst, long index)
{
	t_list	*current;
	t_list	**pointer_to_current;
	long	i;

	pointer_to_current = lst;
	current = *pointer_to_current;
	i = 0;
	while (current && i < index)
	{
		pointer_to_current = &current->next;
		current = current->next;
		i++;
	}
	if (current->next)
		*pointer_to_current = current->next;
	else
		*pointer_to_current = NULL;
	current->next = NULL;
	return (current);
}

t_list	*ft_lstpop(t_list **lst, long index)
{
	if (lst == NULL || *lst == NULL)
		return (NULL);
	if (index < 0)
		return (pop_last(lst));
	else
		return (pop_forward(lst, index));
}
