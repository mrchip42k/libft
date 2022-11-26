/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:46:56 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/26 17:57:46 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ametzen libft v2

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
// va_start va_end va_arg va_copy
# include <stdarg.h>

//// Function description explanation
// ❗️ Uses system call(s). Check if it's allowed!
// 📂 The category this function is from.
// 💥 Will crash under this condition.
// ☢️❗️ Easily misused. Know what you're doing.
// - General explanation on how to use the function, or what it does, goes here-

////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////   ----  ////
////  Part 1 : Replicas of libc functions  ///////////////////////  /      /////
/////////////////////////////////////////////////////////////////   ----  //////
////////////////////////////////////////////////////////////////////////////////

// 💥 TLDR: these assume their arguments are correct, else crash.

// 📂 libc replica
int			ft_isalpha(int c);

// 📂 libc replica
int			ft_isdigit(int c);

// 📂 libc replica
int			ft_isalnum(int c);

// 📂 libc replica
int			ft_isascii(int c);

// 📂 libc replica
int			ft_isprint(int c);

// 📂 libc replica
// 💥 (s) == NULL (🛡 Protected version available)
size_t		ft_strlen(const char *s);

// 📂 libc replica
// 💥 (b) == NULL (🛡 Protected version available)
void		*ft_memset(void *b, int c, size_t len);

// 📂 libc replica
// 💥 (s) == NULL (🛡 Protected version available)
void		ft_bzero(void *s, size_t n);

// 📂 libc replica
// 💥 either (src) || (dst) == NULL,
//    DOESNT crash if BOTH (src) && (dst) == NULL
// (🛡 Protected version available)
void		*ft_memcpy(void *dst, const void *src, size_t n);

// 📂 libc replica
// 💥 Same crash rules as ft_memcpy, since it calls it. (🛡 Protected available)
void		*ft_memmove(void *dst, const void *src, size_t len);

// 📂 libc replica
// 💥 (dst || src) == NULL (🛡 Protected version available)
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);

// 📂 libc replica
// 💥 (src) == NULL (🛡 Protected version available)
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);

// 📂 libc replica
int			ft_toupper(int c);

// 📂 libc replica
int			ft_tolower(int c);

// 📂 libc replica
// 💥 (s) == NULL (🛡 Protected version available)
char		*ft_strchr(const char *s, int c);

// 📂 libc replica
// 💥 (s) == NULL (🛡 Protected version available)
char		*ft_strrchr(const char *s, int c);

// 📂 libc replica
// 💥 (s1 || s2) == NULL
int			ft_strncmp(const char *s1, const char *s2, size_t n);

// 📂 libc replica
// 💥 (s) == NULL (🛡 Protected version available)
void		*ft_memchr(const void *s, int c, size_t n);

// 📂 libc replica
// 💥 (s1 || s2) == NULL
int			ft_memcmp(const void *s1, const void *s2, size_t n);

// 📂 libc replica
// 💥 (haystack || needle) == NULL (🛡 Protected version available)
// (len) is the limit of (haystack), not (needle)
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);

// 📂 libc replica
// 💥 (str) == NULL (🛡 Protected version available)
int			ft_atoi(const char *str);

// ❗️ Uses: malloc()
// 📂 libc replica
// ❓ *REVIEW figure this out: No protection for 0 size or count?
void		*ft_calloc(size_t count, size_t size);

// ❗️ Uses: malloc()
// 📂 libc replica
// 💥 (s1) == NULL (🛡 Protected version available)
char		*ft_strdup(const char *s1);

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////  /----  --+--  ////
////  Part 2 : Other  /////////////////////////////////////  /----    /    /////
//////////////////////////////////////////////////////////  /        /    //////
////////////////////////////////////////////////////////////////////////////////

// ℹ️ See libft subject for original documentation

// ❗️ Uses: malloc()
// 📂 Part 2
// Allocate a new string,
// copied from (s), starting from (start), up to (len) long.
char		*ft_substr(char const *s, unsigned int start, size_t len);

// ❗️ Uses: malloc()
// 📂 Part 2
// Allocate a new string,
// concatenating (s1) and (s2).
char		*ft_strjoin(char const *s1, char const *s2);

// ❗️ Uses: malloc()
// 📂 Part 2
// Allocate a new string, long at most like (s1),
// that trims occurrences of characters in (set) at the start and end of (s1).
char		*ft_strtrim(char const *s1, char const *set);

// ❗️ Uses: malloc(), free()
// 📂 Part 2
// Allocate a null terminated array of pointers
//   to allocated new strings,
// splitting (s) with the character (c).
// Array will be null if allocating either the array or any string fails.
char		**ft_split(char const *s, char c);

// ❗️ Uses: malloc()
// 📂 Part 2
// Allocate a new string,
// representing the signed integer (n) as a string.
char		*ft_itoa(int n);

// ❗️ Uses: malloc()
// 📂 Part 2
// Allocate a new string, with the same length as (s),
// where each character is the return of (f()).
// (f()) takes the index of the current character, and the character from (s).
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

// 📂 Part 2
// Apply the modifying function (f()) to each character of the string (s).
// (f()) takes the index of the current character,
// and the pointer to the current character from (s).
void		ft_striteri(char *s, void (*f)(unsigned int, char*));

// ❗️ Uses: write()
// 📂 Part 2
void		ft_putchar_fd(char c, int fd);

// ❗️ Uses: write()
// 📂 Part 2
void		ft_putstr_fd(char *s, int fd);

// ❗️ Uses: write()
// 📂 Part 2
// Like ft_putstr_fd, but appends a newline at the end.
void		ft_putendl_fd(char *s, int fd);

// ❗️ Uses: write()
// 📂 Part 2
// Accepts anything in the signed int type.
void		ft_putnbr_fd(int n, int fd);

////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////       * -> *      ////
////  Bonus : Linked lists  ////////////////////////////       /'     \.   /////
///////////////////////////////////////////////////////  * -> *        *  //////
////////////////////////////////////////////////////////////////////////////////

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// 📂 Bonus
// ❗️ Uses: malloc()
t_list		*ft_lstnew(void *content);

// 📂 Bonus
void		ft_lstadd_front(t_list **lst, t_list *new);

// 📂 Bonus
int			ft_lstsize(t_list *lst);

// 📂 Bonus
t_list		*ft_lstlast(t_list *lst);

// 📂 Bonus
void		ft_lstadd_back(t_list **lst, t_list *new);

// ❗️ Uses: free()
// 📂 Bonus
// 💥 ( del() ) == NULL. (🛡 Protected version available)
// I'd rather find out this crashed, than let this silently leak memory
void		ft_lstdelone(t_list *lst, void (*del)(void*));

// ❗️ Uses: free()
// 📂 Bonus
// 💥 ( lst || del() ) == NULL. (🛡 Protected version available)
// I'd rather find out this crashed, than let this silently leak memory
void		ft_lstclear(t_list **lst, void (*del)(void*));

// 📂 Bonus
// Content is NOT null checked. That's the responsibility of ( f() ).
// ( f() ) will be called for EVERY item in the list.
// ( f() ) will be called as many times as there are list items.
void		ft_lstiter(t_list *lst, void (*f)(void *));

// ❗️ Uses: malloc(), free()
// 📂 Bonus
// ( f() ) needs to malloc the element it returns. (f() may return NULL)
// Does nothing and returns NULL if (lst), ( f() ), or ( del() ) are NULL.
// (More info in source code)
// Will free whatever was created using ( del() ) if mallocs fail.
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////  ++++++++  ////
////  Personal additions ft++ : Protected versions  ///////////  ++++++++  /////
//////////////////////////////////////////////////////////////  ++++++++  //////
////////////////////////////////////////////////////////////////////////////////

// ℹ️ A comment on protected functions
// The original versions are not protected because they assume they are fed
// correct arguments.
// Calling protected versions has its place, but:
// A. Their behaviour may differ
// B. They may silently do nonsense, and push crashes downstream in their users.
// Prot fn only care about "I should never crash. Not my problem". Nothing else.
// Use braincells, as usual. Read the comments. Read the implementations.

// 📂 ft++ / 🛡 prot libc
// 🔁💥 Will get stuck / potentially segfault if (s) is non-terminated.
// Like strlen, but returns 0 instead of crashing if (s) == NULL.
size_t		ft_prot_strlen(const char *s);

// 📂 ft++ / 🛡 prot libc
// Like memset, but does nothing if (b) == NULL.
// 🤔 Probably useless
void		*ft_prot_memset(void *b, int c, size_t len);

// 📂 ft++ / 🛡 prot libc
// Like bzero, but does nothing if (s) == NULL.
void		ft_prot_bzero(void *s, size_t n);

// 📂 ft++ / 🛡 prot libc
// Like memcpy, but returns (dst) immediately if either == NULL.
// 🤔 Maybe useless
void		*ft_prot_memcpy(void *dst, const void *src, size_t n);

// 📂 ft++ / 🛡 prot libc
// 💥 *REVIEW can this crash if len is incorrect?
// Like memmove, but returns (dst) immediately if (src || dst) == NULL.
// 🤔 Maybe useless
void		*ft_prot_memmove(void *dst, const void *src, size_t len);

// 📂 ft++ / 🛡 prot libc
// Like strlcpy, but returns (prot_len(src)) immediately if (dst || src) == NULL
// 🤔 ?
size_t		ft_prot_strlcpy(char *dst, const char *src, size_t dstsize);

// 📂 ft++ / 🛡 prot libc
// Like strlcat, but can't crash.
// 🤔 ?
size_t		ft_prot_strlcat(char *dst, const char *src, size_t dstsize);

// 📂 ft++ / 🛡 prot libc
// Like strchr, but can't crash.
char		*ft_prot_strchr(const char *s, int c);

// 📂 ft++ / 🛡 prot libc
// Like strrchr, but can't crash.
char		*ft_prot_strrchr(const char *s, int c);

// 📂 ft++ / 🛡 prot libc
// Like memchr, but can't crash.
void		*ft_prot_memchr(const void *s, int c, size_t n);

// 📂 ft++ / 🛡 prot libc
// Like strnstr, but can't crash.
char		*ft_prot_strnstr(const char *haystack,
				const char *needle, size_t len);

// 📂 ft++ / 🛡 prot libc
// Like atoi, but if (str) == NULL, return 0.
int			ft_prot_atoi(const char *str);

// ❗️ Uses: malloc()
// 📂 ft++ / 🛡 prot libc
// Like strdup, but returns NULL instead of crashing if (s1) == NULL.
// ☢️❗️ Ambiguous return: null input, OR malloc error
char		*ft_prot_strdup(const char *s1);

// ❗️ Uses: free()
// 📂 ft++ / 🛡 prot bonus
// ☢️❗️ WARNING: Protection may cause this to silently leak.
//  Consider using the unprotected version to notice if the function is misused.
void		ft_prot_lstclear(t_list **lst, void (*del)(void*));

// ❗️ Uses: free()
// 📂 ft++ / 🛡 prot bonus
// ☢️❗️ WARNING: Protection may cause this to silently leak.
//  Consider using the unprotected version to notice if the function is misused.
void		ft_prot_lstdelone(t_list *lst, void (*del)(void*));

////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////    /    /    ////
////  Other projects ft++  //////////////////////////////////  --+----+--  /////
////////////////////////////////////////////////////////////    /    /    //////
////////////////////////////////////////////////////////////////////////////////

// ❗️ Uses: malloc() / free()
// ❗️ Uses: write()
// ❗️ Uses: va_start va_end va_arg va_copy
int			ft_printf(const char *fmt, ...);

// ❗️Uses: read(), malloc(), free()
// Can return:
// -> Heap String ended by 1 newline
//            ... without newline (if last line of file has content)
// -> NULL if the file has ended
//     ... if any error occurred
// Undefined behaviour if you feed it a binary file
//                    ... the file changes between calls
// Note: This implementation can NOT handle multiple file descriptors.
char		*get_next_line(int fd);

////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////    /    /    ////
////  Personal additions ft++  //////////////////////////////  --+----+--  /////
////////////////////////////////////////////////////////////    /    /    //////
////////////////////////////////////////////////////////////////////////////////

//// These two were moved from static

// 📂 ft++ (libc replica)
int			ft_isspace(char c);

// 📂 ft++
// 💥 (dst || src) == NULL
// Similar to ft_memcpy.
// Goes from right to left, skips the special case check and does not return.
void		ft_mini_memcpy_left(void *dst, const void *src, size_t len);

// ❗️ Uses: free()
// 📂 ft++
void		*ft_frull(void **ptr);

// ❗️ Uses: malloc()
// Returns:
// -> new Heap String
// -> NULL, if error (should never happen?)
char		*ft_num2str(long n);

// ❗️ Uses: malloc()
// -> new Heap String
// -> NULL, if error (base is missing or invalid)
char		*ft_num2str_base(long n, const char *base);

// 📂 ft++
// ( content_printer() ) takes a pointer to the content,
//  and prints it.
// It should NOT newline.
// Description is shown at the start of the list.
void		ft_debug_print_list(t_list **lst,
				void (*content_printer)(void *), char *description);

#endif
