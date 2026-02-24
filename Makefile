# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkisala <mkisala@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/23 20:14:17 by mkisala           #+#    #+#              #
#    Updated: 2026/02/23 20:15:55 by mkisala          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN := \033[0;32m
RESET := \033[0m

NAME := push_swap
CHECKER := checker

CC := cc
CFLAGS := -Wall -Wextra -Werror

# ======================
# Fontes
# ======================
SRC_PUSH := push_swap.c $(wildcard src/utils/*.c) $(wildcard src/algorithm/*.c) 
OBJ_PUSH := $(SRC_PUSH:.c=.o)

SRC_CHECKER := checker.c $(wildcard src/utils/*.c) $(wildcard src/algorithm/*.c) $(wildcard checker_utils/*.c)
OBJ_CHECKER := $(SRC_CHECKER:.c=.o)

# ======================
# Alvo principal push_swap
# ======================
all: $(NAME)

$(NAME): $(OBJ_PUSH)
	$(CC) $(CFLAGS) $(OBJ_PUSH) -o $(NAME)
	@echo "${GREEN}push_swap compiled${RESET}"

# ======================
# Alvo checker
# ======================
checker: $(OBJ_CHECKER)
	$(CC) $(CFLAGS) $(OBJ_CHECKER) -o $(CHECKER)
	@echo "${GREEN}checker compiled${RESET}"

# ======================
# Regra genérica .c -> .o
# ======================
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# ======================
# Limpeza
# ======================
clean:
	rm -f $(OBJ_PUSH) $(OBJ_CHECKER)

fclean: clean
	rm -f $(NAME) $(CHECKER)

re: fclean all

.PHONY: all clean fclean re checker