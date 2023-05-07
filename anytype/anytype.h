/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anytype.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:32:57 by ametzen           #+#    #+#             */
/*   Updated: 2023/05/07 21:01:40 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// README: ALL documentation should be read before using anything from this.
// In particular, almost all functions *might* fail, with specific returned
//   error values. If those are not handled, or misunderstood, bugs are easy.
// Like void pointers, this system removes the compiler's help that comes from
//   static types.
// In certain cases, this system may provide more safety than a void pointer
//   that never even carries information on its type, but there is still
//   significant room for error.

// NOTE At the time of writing this, this entire concept is an experiment.
// It's definetly misusable.
// I don't know yet if this is actually worth it and useful,
//   or if it can lead to bugs too easily.

// NOTE THIS ENTIRE SYSTEM relies on the assumption that the
//   e_any_type field in the u_any union always line up.
// If that is not the case, there WILL be undefined behaviour.

// TODO should set_*() ONLY set if the previous type matched?
//    - Current behaviour functions should then be renamed: any_force_set_*()
//    - This is useless for anylist. False sense of security?

#ifndef  ANYTYPE_H
# define ANYTYPE_H

// REVIEW can i include libft in here and then include this in libft?
//        instead of reimporting everything and missing libft functions
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>

/*----------------------------------------------------------------------------*/

enum e_any_type {
	e_any_type_none,
	e_any_type_bool,
	e_any_type_int32_t,
};

// Return values for functions in here.
typedef enum e_any_error {
	e_any_error_ok = 0,
	e_any_error_input,
	e_any_error_wrong_type,
}		t_any_error;

// Return value for any_get_heaptype().
typedef enum e_any_heaptype {
	e_any_heaptype_not_heap = 0,
	e_any_heaptype_owned_heap,
	e_any_heaptype_shared_heap,
}		t_any_heaptype;

// Declared in advance so the rest of the header knows it exists
union	u_any;

/*------< General helper functions >------------------------------------------*/

t_any_heaptype	any_get_heaptype(const union u_any *any);

// ❗️ Uses: WHATEVER ALL DESTRUCTORS CAN USE
// Automatically run the appropriate destructor on (target)'s data,
//   if it is an owned heap type.
// Otherwise, do nothing.
void			any_try_destroy(union u_any *target);

/*------< Individual types >--------------------------------------------------*/

// any_get_*()
// Requirements:
//   e_any_error_input: (any) and (destination) can't be NULL.
//   e_any_error_wrong_type: (any)'s type must match the choosen function.

// any_set_*()
// Requirements:
//   e_any_error_input: (any) can't be NULL.

struct s_any_bool {
	enum e_any_type	type;
	bool			data;
};
t_any_error		any_get_bool(const union u_any *any, bool *destination);
t_any_error		any_set_bool(union u_any *any, bool value);

struct s_any_int32_t {
	enum e_any_type	type;
	int32_t			data;
};
t_any_error		any_get_int32_t(const union u_any *any, int32_t *destination);
t_any_error		any_set_int32_t(union u_any *any, int32_t value);

/*------< Main union >--------------------------------------------------------*/

// (type) is ALWAYS present, and at the same place.
// (is_heap_owned) is ONLY PRESENT for heap types.
union u_any {
	enum e_any_type			type;
	bool					is_heap_owned;
	struct s_any_bool		_bool;
	struct s_any_int32_t	_int32_t;
};

/*------< Linked list using Anytype >-----------------------------------------*/

// For the most part, most functions to handle Anylists are equivalent to
// those made for t_list.
// Notable difference is t_list functions that returned void, now return
// an error code enum to at the very least notify if the function has been
// misused instead of crashing or (what t_list does) silently doing nothing.

typedef struct s_anylist {
	struct s_anylist	*next;
	union u_any			any_content;
}		t_anylist;

// t_list equivalent: ft_lstnew()
// ❗️ Uses: malloc()
// Returns NULL if memory allocation failed.
t_anylist		*anylist_new_item();

// t_list equivalent: ft_lstadd_front()
// An input of (*start) == NULL is accepted
// Note that this won't try to traverse to items before *start.
// However providing a *start that isnt the actual start is supported.
//  (means empty list, that will be populated with (new).)
// Requirements:
//   e_any_error_input: (new) and (start) can't be NULL.
t_any_error		anylist_add_front(t_anylist **destination, t_anylist *new);

// t_list equivalent: ft_lstsize()
// Returns 0 if (start) is NULL.
u_int64_t		anylist_count(const t_anylist *start);

// t_list equivalent: ft_lstlast()
// Returns NULL if (start) is NULL.
t_anylist		*anylist_get_last(const t_anylist *search_start_item);

// t_list equivalent: ft_lstadd_back()
t_any_error		anylist_add_back(t_anylist **start, t_anylist *new);

// t_list equivalent: ft_lstdelone()
// Will set (*item) to NULL.
// Will automatically run a destructor for the item's type if it exists.
// Wont error if (*item) is NULL, but
// Requirements:
//   e_any_error_input: (item) can't be NULL.
t_any_error		anylist_delete_item(t_anylist **item);

//TODO continue making the rest of list functions from t_list
// t_list equivalent: 
// t_list equivalent: 
// t_list equivalent: 
// t_list equivalent: 

//TODO does this need more functions than t_list?

#endif //ANYTYPE_H
