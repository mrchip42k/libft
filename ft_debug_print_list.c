/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug_print_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:13:39 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/12 17:25:10 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h> //FIXME replace with ft_printf when ready

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
	printf("---v LIST @%p/%d\t\"%s\" v---\n", lst, short_addr, description);
	while (current)
	{
		printf("Element %d\t@%p/%d\t: Content @%p/%d\t: ",
			i, current, st_ptr_short(current),
			current->content, st_ptr_short(current->content));
		content_printer(current->content);
		printf("\n");
		i++;
		current = current->next;
	}
	printf("---^ LIST @%p/%d\t\"%s\" ^--- Size = %d\n\n",
		lst, short_addr, description, i);
}
