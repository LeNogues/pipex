# Nom de la bibliothèque
NAME = pipex

# Fichiers sources
SRCS =	test.c \
		utils.c

OBJS = $(SRCS:.c=.o)

# Compilateur et options de compilation
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Commandes de Makefile
all: $(NAME)

# Compilation de la bibliothèque statique
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# Compilation des fichiers objets
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


# Nettoyage des objets
clean:
	rm -f $(OBJS)

# Nettoyage complet
fclean: clean
	rm -f $(NAME)

# Recompilation complète
re: fclean all

.PHONY: all clean fclean re
