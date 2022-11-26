/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:25:09 by ametzen           #+#    #+#             */
/*   Updated: 2022/11/26 16:53:09 by ametzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Project allows:
// malloc() / free()
// write()
// va_start va_end va_arg va_copy

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//  Includes  //////////////////////////////////////////////////////////////////

# include "../libft.h"

//  Types and macros  //////////////////////////////////////////////////////////

enum e_block_type {
	e_block_unformatted,
	e_block_c_char,
	e_block_s_string,
	e_block_p_hexaddress,
	e_block_di_decimal,
	e_block_u_unsigned,
	e_block_x_hexmin,
	e_block_xx_hexmaj,
	e_block_percent
};

// type:	How should this block be treated when computing (final_content)?
// fmt_content:	The string of interest for this block, before being processed.
// final_content:	These will be concatenated to form the final result.
// fmt_start_idx:	Before fmt_content is filled
struct s_block {
	enum e_block_type	type;
	char				*fmt_content;
	char				*final_content;
	size_t				fmt_start_idx;
	bool				is_null;
};

//  libprintf.c  ///////////////////////////////////////////////////////////////

// ❗️ Uses: malloc() / free()
// ❗️ Uses: write()
// ❗️ Uses: va_start va_end va_arg va_copy
int				ft_printf(const char *fmt, ...);

//  ftt_misc/  /////////////////////////////////////////////////////////////////

// 🟢 Complete
// Pass to ft_lstdelone or ft_lstclear.
void			ftt_delete_block(void *block_voidp);

// 🟢 Complete
// Just call ft_lstclear, but return NULL so this can be placed inside return ()
// Wont set the source pointer to NULL since this is meant for returns
t_list			*ftt_clear_blocks(t_list *block_list);

// ❗️ Uses: malloc()
// Returns string, or NULL if error (should never happen?)
char			*ftt_num2str(long n);

// ❗️ Uses: malloc()
// Returns string, or NULL if error (base missing)
char			*ftt_num2str_base(long n, const char *base);

//  ftt_parser/  ///////////////////////////////////////////////////////////////

// Creates the s_block list.
// Returns a completely parsed list,
// or returns NULL if anything went wrong.(the functions it calls free the list)
t_list			*ftt_parse_fmt(const char *fmt, va_list args);

// 🟢 Complete
// - Creates the list
// - Sets block->fmt_start_idx
// - Sets block->type
// or clears the list and returns NULL if anything went wrong.
t_list			*ftt_parse1_find_splits(const char *fmt);

// - Replaces the temporary pointers with copies 
// or clears the list and returns NULL if anything went wrong.
t_list			*ftt_parse2_dup_fmt(t_list *block_list, const char *fmt);

// - Computes (s_block->final_result)
// or clears the list and returns NULL if anything went wrong.
t_list			*ftt_parse3_result(t_list *block_list, va_list args);

//  ftt_process/  //////////////////////////////////////////////////////////////

bool			ftt_process_unformatted(struct s_block *block);
bool			ftt_process_char(struct s_block *block, va_list args);
bool			ftt_process_string(struct s_block *block, va_list args);
bool			ftt_process_percent(struct s_block *block);
bool			ftt_process_hexaddress(struct s_block *block, va_list args);
bool			ftt_process_sint_decimal(struct s_block *block, va_list args);
bool			ftt_process_uint_decimal(struct s_block *block, va_list args);
bool			ftt_process_uint_hex(struct s_block *block, va_list args,
					char *base);

#endif
