
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

#ifndef PIPEX_H
# define PIPEX_H

    int	ft_strlen(const char *str);
    int	ft_strncmp(const char *s1, const char *s2, size_t n);
    char *get_path(char **envp);
    int	ft_strlcpy(char *dst, const char *src, int size);
    char	*ft_strdup(const char *s);

# endif