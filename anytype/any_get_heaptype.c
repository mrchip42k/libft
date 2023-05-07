/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   any_get_heaptype.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:58:22 by ametzen           #+#    #+#             */
/*   Updated: 2023/05/07 21:02:11 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "anytype.h"

static bool	is_heap(enum e_any_type	t)
{// REVIEW if a heap type is created, it must be handled here
	return (t == ... || t == ...);
}

t_any_heaptype	any_get_heaptype(const union u_any *any)
{
	if (is_heap(any->type) == false)
		return (e_any_heaptype_not_heap);
	else if (any->is_heap_owned == false)
		return (e_any_heaptype_shared_heap);
	else
		return (e_any_heaptype_owned_heap);
}
