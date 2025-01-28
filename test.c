#include "pipex.h"

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

extern char **environ;

int find_executable(const char *command, char **full_path) {
    char *path = ft_strdup(*full_path); 
    if (!path)
		return (-1);
    char *dir = ft_strtok(path, ':');

    while (dir != NULL) 
    {
        *full_path = ft_write_mini_path(*full_path, dir, command);
        if (access(*full_path, X_OK) == 0) 
            return 0;
        dir = ft_strtok(NULL, ':');
    }
    return -1;
}

int main(int argc, char **argv, char **envp) {
    char *full_path;

	if (argc < 2) {
        printf("Usage: %s <commande> [arguments...]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    full_path = get_path(envp);
    if (find_executable(argv[1], &full_path) == -1) {
        printf("Command not found: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if (execve(full_path, &argv[1], environ) == -1) {
        printf("test");
        perror("execve");
        exit(EXIT_FAILURE);
    }
    return 0;
}
