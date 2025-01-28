#include "pipex.h"

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

extern char **environ;

int find_executable(const char *command, char *full_path) {
    char *path = ft_strdup(full_path); 
    if (!path)
		return (-1);
    char *dir = strtok(path, ":");
    struct stat buffer;

    while (dir != NULL) {
		printf("%s\n", dir);
        sprintf(full_path, "%s/%s", dir, command);
        if (stat(full_path, &buffer) == 0 && (buffer.st_mode & S_IXUSR)) {
            return 0;
        }
        dir = strtok(NULL, ":");
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
    if (find_executable(argv[1], full_path) == -1) {
        printf("Command not found: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if (execve(full_path, &argv[1], environ) == -1) {
        perror("execve");
        exit(EXIT_FAILURE);
    }
    return 0;
}
