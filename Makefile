# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 17:06:07 by gsantill          #+#    #+#              #
#    Updated: 2024/11/11 15:21:09 by gsantill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# hide terminal output
.SILENT:

# Variables
NAME = push_swap
CC = gcc
CFLAGS	= -Wall -Werror -Wextra -g3
RM = rm -rf
AR = ar rcs

# Colors (ANSI escape sequence)
GREEN_PRE = '\033[32m'
RED_PRE = '\033[31m'
RESET_BLACK = '\033[0m'

# Paths
LIBFT_PATH = libft
SRCS_PATH = srcs
PRINTF_PATH = ft_printf

# Libraries
LIBFT_LIB = $(LIBFT_PATH)/libft.a
PRINTF_LIB = $(PRINTF_PATH)/ft_printf.a

# Files
SRCS = $(wildcard $(SRCS_PATH)/*.c)
OBJS = $(SRCS:.c=.o)

# Targets
all: $(LIBFT_LIB) $(PRINTF_LIB) $(NAME)

# Compile push_swap with libft and ft_printf
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_LIB) $(PRINTF_LIB)
	@echo $(GREEN_PRE)"PUSH_SWAP COMPILED !"$(RESET_BLACK)
	@echo "./push_swap <ARGS> to run"

# Compile libft library
$(LIBFT_LIB):
	@make -C $(LIBFT_PATH)

# Compile ft_printf library
$(PRINTF_LIB):
	@make -C $(PRINTF_PATH)

# Compile .c files into .o
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Test and count
checker_linux: $(NAME)
	$(eval ARG = $(shell shuf -i 0-5000 -n $(NUMS)))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

checker_mac: $(NAME)
	$(eval ARG = $(shell shuf -i 0-5000 -n $(NUMS)))
	./push_swap $(ARG) | ./checker_mac $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

# Clean object files
clean:
	@$(RM) $(OBJS)
	@make -C $(LIBFT_PATH) clean
	@make -C $(PRINTF_PATH) clean
	@echo $(RED_PRE)"OBJECT FILES DELETED !"$(RESET_BLACK)

# Clean object files & push_swap executable
fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBFT_PATH) fclean
	@make -C $(PRINTF_PATH) fclean
	@echo $(RED_PRE)"PUSH_SWAP EXEC DELETED !"$(RESET_BLACK)

re: fclean all

.PHONY: all clean fclean re
