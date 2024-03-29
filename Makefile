# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 10:03:58 by ametzen           #+#    #+#              #
#    Updated: 2023/09/09 17:21:57 by ametzen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ametzen libft v3

NAME = libft.a

SOURCES =	$(SOURCES_PRINTF) \
			$(SOURCES_GNL) \
			$(SOURCES_DICT) \
			ft_putnbr_fd.c \
			ft_itoa.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_strlen.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_strdup.c \
			ft_calloc.c \
			ft_memcmp.c \
			ft_memchr.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_isspace.c \
			ft_mini_memcpy_left.c \
			ft_prot_strlen.c \
			ft_prot_lstclear.c \
			ft_prot_lstdelone.c \
			ft_prot_memset.c \
			ft_prot_bzero.c \
			ft_prot_memcpy.c \
			ft_prot_memmove.c \
			ft_prot_strlcpy.c \
			ft_prot_strlcat.c \
			ft_prot_strchr.c \
			ft_prot_strrchr.c \
			ft_prot_memchr.c \
			ft_prot_strnstr.c \
			ft_prot_atoi.c \
			ft_prot_strdup.c \
			ft_debug_print_list.c \
			ft_frull.c \
			ft_num2str.c \
			ft_num2str_special.c \
			ft_int_power.c \
			ft_shift_numbers.c \
			ft_exit.c \
			ft_int_minmax.c \
			ft_secure_atol.c \
			ft_kill_or_die.c \
			ft_lstpop.c \
			ft_delete_split.c \

SOURCES_PRINTF = $(addprefix ft_printf/, \
					ft_printf.c \
					wrappers.c \
					\
					misc/ftt_block_list_utils.c \
					\
					parser/ftt_parse1_find_splits.c \
					parser/ftt_parse2_dup_fmt.c \
					parser/ftt_parse3_result.c \
					parser/ftt_parse_fmt.c \
					\
					process/ftt_process_unformatted.c \
					process/ftt_process_char.c \
					process/ftt_process_string.c \
					process/ftt_process_percent.c \
					process/ftt_process_hexaddress.c \
					process/ftt_process_sint_decimal.c \
					process/ftt_process_uint_decimal.c \
					process/ftt_process_uint_hex.c \
				)

SOURCES_GNL = $(addprefix get_next_line/, \
					get_next_line.c \
					get_next_line_utils.c \
				)

SOURCES_DICT = $(addprefix dict/, \
				dict_delete.c \
				dict_find.c \
				dict_get.c \
				dict_pop.c \
				dict_set.c \
				)

OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(NAME): $(OBJECTS)
	ar -c -r -s $(NAME) $(OBJECTS)
