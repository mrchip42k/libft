/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   any_bool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:52:02 by ametzen           #+#    #+#             */
/*   Updated: 2023/05/07 20:53:14 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "anytype.h"

t_any_error	any_get_bool(const union u_any *any, bool *destination)
{
	if (any == NULL || destination == NULL)
		return (e_any_error_input);
	if (any->type != e_any_type_bool)
		return (e_any_error_wrong_type);
	*destination = any->_bool.data;
	return (e_any_error_ok);
}

t_any_error	any_set_bool(union u_any *any, bool value)
{
	if (any == NULL)
		return (e_any_error_input);
	any_try_destroy(any);
	any->_bool.type = e_any_type_bool;
	any->_bool.data = value;
	return (e_any_error_ok);
}
