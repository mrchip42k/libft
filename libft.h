/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:46:56 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/09 18:19:58 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

// Necessary for size_t
# include <stddef.h>

////  Part 1 : Replicas of libc functions  ////

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
//memcpy
//memmove
//strlcpy
//strlcat
int		ft_toupper(int c);
int		ft_tolower(int c);
//strchr
//strrchr
//strncmp
//memchr
//memcmp
//strnstr
//atoi

// Malloc allowed:
//calloc
//strdup

////  Part 2 : Other, see libft subject for full documentation  ////

// Allocate a new string,
// copied from (s), starting from (start), up to (len) long.
char	*ft_substr(char const *s, unsigned int start, size_t len);
// Allocate a new string,
// concatenating (s1) and (s2).
char	*ft_strjoin(char const *s1, char const *s2);
// Allocate a new string, long at most like (s1),
// that trims occurrences of characters in (set) at the start and end of (s1).
char	*ft_strtrim(char const *s1, char const *set);
// Allocate a null terminated array of pointers
//   to allocated new strings,
// splitting (s) with the character (c).
// Array will be null if allocating either the array or any string fails.
char	**ft_split(char const *s, char c);
// Allocate a new string,
// representing the signed integer (n) as a string.
char	*ft_itoa(int n);
// Allocate a new string, with the same length as (s),
// where each character is the return of (f()).
// (f()) takes the index of the current character, and the character from (s).
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
// Apply the modifying function (f()) to each character of the string (s).
// (f()) takes the index of the current character,
// and the pointer to the current character from (s).
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
// Like ft_putstr_fd, but appends a newline at the end.
void	ft_putendl_fd(char *s, int fd);
// Accepts anything in the signed int type.
void	ft_putnbr_fd(int n, int fd);

////  Bonus : Linked lists  ////

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

#endif
