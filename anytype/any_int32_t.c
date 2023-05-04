/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   any_int32_t.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:52:02 by ametzen           #+#    #+#             */
/*   Updated: 2023/05/04 16:44:02 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "anytype.h"

t_any_error	any_get_int32_t(const union u_any *any, int32_t *destination)
{
	if (any->type != e_any_type_int32_t)
		return (-1);
	*destination = any->_int32_t.data;
	return (0);
}

t_any_error	any_set_int32_t(union u_any *any, int32_t value)
{
	if (any == NULL)
		return (e_any_error_input);
	any->_int32_t.type = e_any_type_int32_t;
	any->_int32_t.data = value;
	return (e_any_error_ok);
}
