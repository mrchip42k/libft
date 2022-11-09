# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ametzen <ametzen@student.42mulhouse.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 10:03:58 by ametzen           #+#    #+#              #
#    Updated: 2022/11/08 19:13:07 by ametzen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SOURCES =	ft_char_checks.c \
			ft_fd_writes.c \
			ft_putnbr_fd.c \
			ft_str_iter.c \
			ft_itoa.c \
			ft_substr.c

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
