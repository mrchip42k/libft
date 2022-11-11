/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:46:56 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/11 09:47:36 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

////  Part 1 : Replicas of libc functions  ////

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
// (len) is the limit of (haystack), not (needle)
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
// /!\ Uses: malloc()
void	*ft_calloc(size_t count, size_t size);
// /!\ Uses: malloc()
char	*ft_strdup(const char *s1);

////  Part 2 : Other, see libft subject for full documentation  ////

// /!\ Uses: malloc()
// Allocate a new string,
// copied from (s), starting from (start), up to (len) long.
char	*ft_substr(char const *s, unsigned int start, size_t len);
// /!\ Uses: malloc()
// Allocate a new string,
// concatenating (s1) and (s2).
char	*ft_strjoin(char const *s1, char const *s2);
// /!\ Uses: malloc()
// Allocate a new string, long at most like (s1),
// that trims occurrences of characters in (set) at the start and end of (s1).
char	*ft_strtrim(char const *s1, char const *set);
// /!\ Uses: malloc(), free()
// Allocate a null terminated array of pointers
//   to allocated new strings,
// splitting (s) with the character (c).
// Array will be null if allocating either the array or any string fails.
char	**ft_split(char const *s, char c);
// /!\ Uses: malloc()
// Allocate a new string,
// representing the signed integer (n) as a string.
char	*ft_itoa(int n);
// /!\ Uses: malloc()
// Allocate a new string, with the same length as (s),
// where each character is the return of (f()).
// (f()) takes the index of the current character, and the character from (s).
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
// Apply the modifying function (f()) to each character of the string (s).
// (f()) takes the index of the current character,
// and the pointer to the current character from (s).
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
// /!\ Uses: write()
void	ft_putchar_fd(char c, int fd);
// /!\ Uses: write()
void	ft_putstr_fd(char *s, int fd);
// /!\ Uses: write()
// Like ft_putstr_fd, but appends a newline at the end.
void	ft_putendl_fd(char *s, int fd);
// /!\ Uses: write()
// Accepts anything in the signed int type.
void	ft_putnbr_fd(int n, int fd);

////  Bonus : Linked lists  ////

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// /!\ Uses: malloc()
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
// /!\ Uses: free()
void	ft_lstdelone(t_list *lst, void (*del)(void*));
// /!\ Uses: free()
void	ft_lstclear(t_list **lst, void (*del)(void*));
// Content is NOT null checked. That's the responsibility of ( f() ).
// ( f() ) will be called for EVERY item in the list.
// ( f() ) will be called as many times as there are list items.
void	ft_lstiter(t_list *lst, void (*f)(void *));
// /!\ Uses: malloc(), free()
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
