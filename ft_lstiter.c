/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:59:49 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/10 18:03:40 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Content is NOT null checked. That's (f())'s responsibility.
// (f()) will be called for EVERY item in the list.
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*current;

	if (lst)
	{
		current = lst;
		while (current)
		{
			f(current->content);
			current = current->next;
		}
	}
}
