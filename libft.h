/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:46:56 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/09 09:56:23 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

// Necessary for size_t
# include <stddef.h>

////  Part 1  ////

//// ft_char_checks.c
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);

////  Part 2  ////

// Allocate a new string,
// copied from (s), starting from (start), up to (len) long.
char	*ft_substr(char const *s, unsigned int start, size_t len);

// Allocate a new string,
// concatenating (s1) and (s2).
char	*ft_strjoin(char const *s1, char const *s2);

// Allocate a new string, long at most like (s1),
// that trims occurrences of characters in (set) at the start and end of (s1).
char	*ft_strtrim(char const *s1, char const *set);

// Allocate a new string,
// representing the signed integer (n) as a string.
char	*ft_itoa(int n);

//// ft_str_iter.c

// Allocate a new string, with the same length as (s),
// where each character is the return of (f()).
// (f()) takes the index of the current character, and the character from (s).
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
// Apply the modifying function (f()) to each character of the string (s).
// (f()) takes the index of the current character,
// and the pointer to the current character from (s).
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

//// ft_fd_writes.c

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
// Like ft_putstr_fd, but appends a newline at the end.
void	ft_putendl_fd(char *s, int fd);

// Accepts anything in the signed int type.
void	ft_putnbr_fd(int n, int fd);

#endif
