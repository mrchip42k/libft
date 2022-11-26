/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug_print_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:13:39 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/26 16:19:58 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// number is arbitrary to give small results and hopefully align less to blocks
// that would easily give collisions
static int	st_ptr_short(void *addr)
{
	return ((uint64_t)addr % 123);
}

void	ft_debug_print_list(t_list **lst
		, void (*content_printer)(void *), char *description)
{
	int		i;
	int		short_addr;
	t_list	*current;

	i = 0;
	short_addr = st_ptr_short(lst);
	current = *lst;
	ft_printf("---v LIST @%p/%d\t\"%s\" v---\n", lst, short_addr, description);
	while (current)
	{
		ft_printf("Element %d\t@%p/%d\t: Content @%p/%d\t: ",
			i, current, st_ptr_short(current),
			current->content, st_ptr_short(current->content));
		content_printer(current->content);
		ft_printf("\n");
		i++;
		current = current->next;
	}
	ft_printf("---^ LIST @%p/%d\t\"%s\" ^--- Size = %d\n\n",
		lst, short_addr, description, i);
}
