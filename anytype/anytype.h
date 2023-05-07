/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anytype.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:32:57 by ametzen           #+#    #+#             */
/*   Updated: 2023/05/07 19:28:20 by ametzen          ###   ########.fr       */
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

// Declared in advance so the rest of the header knows it exists
union	u_any;

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

union u_any {
	enum e_any_type			type;
	struct s_any_bool		_bool;
	struct s_any_int32_t	_int32_t;
};

/*------< Linked list using Anytype >-----------------------------------------*/

typedef struct s_anylist {
	struct s_anylist	*next;
	union u_any			any;
}		t_anylist;

// ❗️ Uses: malloc()
// Returns NULL if memory allocation failed.
t_anylist		*anylist_new_item();

// An input of (*start) == NULL is accepted
// Note that this won't try to traverse to items before *start.
// However providing a *start that isnt the actual start is supported.
//  (means empty list, that will be populated with (new).)
// Requirements:
//   e_any_error_input: (new) and (start) can't be NULL.
t_any_error		anylist_add_front(t_anylist **destination, t_anylist *new);

// Returns 0 if (start) is NULL.
u_int64_t		anylist_count(const t_anylist *start);

// Returns NULL if (start) is NULL.
t_anylist		*anylist_get_last(const t_anylist *search_start_item);

t_any_error		anylist_add_back(t_anylist **start, t_anylist *new);

//TODO continue making the rest of list functions from t_list

//TODO does this need more functions than t_list?

#endif //ANYTYPE_H
