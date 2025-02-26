# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/26 10:14:48 by sle-nogu          #+#    #+#              #
#    Updated: 2025/02/26 10:40:44 by sle-nogu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=pipex
BONUS=pipex_bonus
CC=cc
CFLAGS=-Wall -Werror -Wextra

SRC=	./mandatory/pipex.c \
		./mandatory/mini_libft.c \
		./mandatory/executable.c \
		./mandatory/parsing.c \
		./mandatory/path.c \
		./mandatory/strtok.c \
		./mandatory/ft_split.c \
		./mandatory/clean.c \
		./mandatory/error.c \
		./mandatory/exec.c \
		./mandatory/main.c \
		./mandatory/handle_cmd.c

OBJS=$(SRC:.c=.o)

SRC_BONUS=	./bonus/pipex.c \
			./bonus/mini_libft.c \
			./bonus/executable.c \
			./bonus/parsing.c \
			./bonus/path.c \
			./bonus/strtok.c \
			./bonus/ft_split.c \
			./bonus/clean.c \
			./bonus/error.c \
			./bonus/exec.c \
			./bonus/main.c \
			./bonus/handle_cmd.c \
			./bonus/middle_loop.c \
			./bonus/verif.c

OBJS_BONUS=$(SRC_BONUS:.c=.o)

# Compilation rules
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(BONUS)

bonus: $(BONUS)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

all: $(NAME)

default: all

.PHONY: all re clean fclean bonus
