/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anytype.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:32:57 by ametzen           #+#    #+#             */
/*   Updated: 2023/05/04 17:06:17 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// NOTE At the time of writing this, this entire concept is an experiment.
// It's definetly misusable.
// I don't know yet if this is actually worth it and useful,
// or if it can lead to bugs too easily.

// NOTE THIS ENTIRE SYSTEM relies on the assumption that the
// e_any_type field in the u_any union always line up.
// If that is not the case, there will be undefined behaviour.

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
// e_any_error_input: (any) and (destination) can't be NULL.
// e_any_error_wrong_type: (any)'s type must match the choosen function.

// any_set_*()
// Requirements:
// e_any_error_input: (any) can't be NULL.

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

/*------< 2 way linked list using Anytype >-----------------------------------*/

typedef struct s_any_list {
	struct s_any_list	*prev;
	struct s_any_list	*next;
	union u_any			any;
}		t_any_list;

// ❗️ Uses: malloc()
// Returns NULL if memory allocation failed.
t_any_list		*any_list_new_item();

// An input of (*start) == NULL is accepted
//  (means empty list, that will be populated with (new).)
// Requirements:
// e_any_error_input: (new) and (start) can't be NULL.
t_any_error		any_list_add_front(t_any_list **start, t_any_list *new);

// Returns 0 if (start) is NULL.
u_int64_t		any_list_count(const t_any_list *start);

#endif //ANYTYPE_H
