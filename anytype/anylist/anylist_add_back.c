/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anylist_add_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:28:54 by ametzen           #+#    #+#             */
/*   Updated: 2023/05/07 19:10:47 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../anytype.h"

t_any_error		anylist_add_back(t_anylist **start, t_anylist *new)
{
	if (start == NULL || new == NULL)
		return (e_any_error_input);
	if (*start == NULL)
	{
		*start = new;
		
		return e_any_error_ok;
	}
	//TODO continue here, WIP
}
