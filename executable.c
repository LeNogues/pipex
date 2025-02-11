/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executable.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:35:14 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/02/11 15:36:32 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**create_executable1(int argc, char **argv)
{
	int		i;
	char	**executable;

	i = 0;
	if (argc != 5)
	{
		write(1, "Usage: ./pipex infile \"command1 + arguments\" ", 46);
		write(1, "\"command2 + arguments\" outfile\n", 32);
		exit(EXIT_FAILURE);
	}
	executable = ft_split(argv[2], ' ');
	while (executable[i])
	{
		i++;
	}
	return (executable);
}

char	**create_executable2(int argc, char **argv)
{
	int		i;
	char	**executable;

	i = 0;
	(void)argc;
	executable = ft_split(argv[3], ' ');
	while (executable[i])
		i++;
	return (executable);
}

int	find_executable(char *command, char **full_path)
{
	char	*path;
	char	*dir;

	if (access(command, X_OK) == 0)
	{
		free(*full_path);
		*full_path = ft_strdup(command);
		return (0);
	}
	path = ft_strdup(*full_path);
	if (!path)
		return (-1);
	dir = ft_strtok(path, ':');
	while (dir != NULL)
	{
		free(*full_path);
		*full_path = ft_write_mini_path(*full_path, dir, command);
		if (access(*full_path, X_OK) == 0)
			return (free(path), 0);
		dir = ft_strtok(NULL, ':');
	}
	free(*full_path);
	free(path);
	return (-1);
}
