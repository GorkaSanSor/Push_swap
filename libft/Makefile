# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/10 18:35:45 by gsantill          #+#    #+#              #
#    Updated: 2024/10/24 15:27:03 by gsantill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT_SRCS = $(wildcard *.c)
LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)

NAME = libft.a
HEADER = libft.h

all: $(NAME)

$(NAME): $(LIBFT_OBJS)
	ar rcs $(NAME) $(LIBFT_OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	rm -f $(LIBFT_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

