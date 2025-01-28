
#include "pipex.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i] || !s2[i] || !s1[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	ft_strlcpy(char *dst, const char *src, int size)
{
	int			i;
	int			size_src;

	size_src = ft_strlen(src);
	i = 0;
	while (i + 1 < size && src[i] != 0)
	{
		dst[i] = src[i];
		i++;
	}
	if (size)
		dst[i] = 0;
	return (size_src);
}

#include <stdio.h>

char *ft_strtok(char *str, const char delim) {
    
    static char *last = NULL;
    char *token;
    if (str != NULL) 
        last = str;
    if (last == NULL)
        return NULL;
    while (*last == delim && *last != 0)
        last++;
    if (*last == 0)
        return NULL;
    token = last;
    while (*last != delim && *last != 0)
        last++;
    if (*last != 0) 
    {
        *last = 0;
        last++;
    } 
    else
        last = NULL;
    return token;
}

char	*ft_strdup(const char *s)
{
	int		size;
	char	*dup;
	int		i;

	i = 0;
	size = ft_strlen(s);
	dup = malloc(sizeof (char) * size + 1);
	if (!dup)
		return (0);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

char *get_path(char **envp) {
    int i;
    char *path = NULL;

    i = 0;
    while (envp[i]) {
        if (ft_strncmp(envp[i], "PATH=", 5) == 0) {
            path = malloc(ft_strlen(envp[i]) + 1);
            if (path == NULL)
                return (-1);
            ft_strlcpy(path, envp[i] +5, ft_strlen(envp[i]) - 4);
            break;
        }
        i++;
    }
    return path;
}
