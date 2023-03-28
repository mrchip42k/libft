/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_minmax.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:58:53 by ametzen           #+#    #+#             */
/*   Updated: 2023/03/06 17:27:46 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_imin(long a, long b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

long	ft_imax(long a, long b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
