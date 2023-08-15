/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:01:38 by ametzen           #+#    #+#             */
/*   Updated: 2023/08/15 16:13:41 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_delete_split(char ***split)
{
	long	i;
	char	**real_split;

	real_split = *split;
	i = 0;
	while (real_split[i])
	{
		free(real_split[i]);
		i++;
	}
	free(real_split);
	*split = NULL;
}
