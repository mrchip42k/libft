/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:24:45 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/10 17:02:43 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_item;

	new_item = malloc(sizeof(t_list));
	if (new_item)
	{
		new_item->content = content;
		new_item->next = NULL;
	}
	return (new_item);
}
