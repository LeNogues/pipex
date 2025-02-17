/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executable.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:35:14 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/02/17 15:53:30 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**create_executable_middle(char *str)
{
	char	**executable;

	executable = ft_split(str, ' ');
	return (executable);
}

char	**create_executable1(char **argv)
{
	char	**executable;

	executable = ft_split(argv[2], ' ');
	return (executable);
}

char	**create_executable2(char **argv)
{
	char	**executable;

	executable = ft_split(argv[3], ' ');
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
