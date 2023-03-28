/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:31:48 by ametzen           #+#    #+#             */
/*   Updated: 2023/03/25 18:58:05 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_generic(int fd, const char *fmt, va_list	args)
{
	ssize_t	print_length;

	if (fmt == NULL)
		return (-1);
	if (fmt[0] == '\0')
		return (0);
	print_length = ftt_write_and_return(fd, fmt, args);
	return (print_length);
}

int	ft_printf_fd(int fd, const char *fmt, ...)
{
	va_list	args;
	ssize_t	return_value;

	va_start(args, fmt);
	return_value = ft_printf_generic(fd, fmt, args);
	va_end(args);
	return (return_value);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	ssize_t	return_value;

	va_start(args, fmt);
	return_value = ft_printf_generic(STDOUT_FILENO, fmt, args);
	va_end(args);
	return (return_value);
}

char	*ft_fmt(const char *fmt, ...)
{
	va_list	args;
	char	*result;
	size_t	size;

	va_start(args, fmt);
	result = ft_fmt_va(fmt, args, &size);
	va_end(args);
	return (result);
}

char	*ft_fmt_va(const char *fmt, va_list args, size_t *size)
{
	char	*result;
	t_list	*block_list;
	size_t	alternative_size;

	block_list = ftt_parse_fmt(fmt, args);
	if (block_list == NULL)
		return (NULL);
	if (size != NULL)
		result = st_combine(size, block_list);
	else
		result = st_combine(&alternative_size, block_list);
	ftt_clear_blocks(block_list);
	if (result == NULL)
		return (NULL);
	return (result);
}
