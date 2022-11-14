/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prot_strnstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:56:19 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/14 13:00:39 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_prot_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (haystack == NULL || needle == NULL || len == 0)
		return (NULL);
	return (ft_strnstr(haystack, needle, len));
}
