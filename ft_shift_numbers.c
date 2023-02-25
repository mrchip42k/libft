/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shift_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 11:26:15 by ametzen           #+#    #+#             */
/*   Updated: 2023/02/25 11:27:45 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_int_shift(int input)
{
	return (0x80000000 + input);
}

// Get digit at index, but shift it.
unsigned int	ft_get_digit_shifted(int input, int digit_index)
{
	long	divided;

	divided = ft_int_shift(input) / ft_int_power(10, digit_index);
	return (divided % 10l);
}
