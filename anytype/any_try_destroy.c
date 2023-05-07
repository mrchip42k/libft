/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   any_try_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:55:15 by ametzen           #+#    #+#             */
/*   Updated: 2023/05/07 21:02:05 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "anytype.h"

void	any_try_destroy(union u_any *target)
{
	if (any_get_heaptype(target) != e_any_heaptype_owned_heap)
		return ;
	// REVIEW if a heap type is created, it must be handled here
}
