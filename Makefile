# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 10:03:58 by ametzen           #+#    #+#              #
#    Updated: 2022/11/13 10:07:44 by ametzen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ametzen libft v1: completely validated
# v2: TODO changelog + update v number in libft.h

NAME = libft.a

SOURCES =	ft_putnbr_fd.c \
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
			ft_mini_memcpy_left.c
#			ft_debug_print_list.c # FIXME unacceptable dependencies

OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(NAME): $(OBJECTS)
	ar -c -r -s $(NAME) $(OBJECTS)
