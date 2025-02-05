/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executable.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:35:14 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/02/05 16:34:19 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**create_executable(int argc, char **argv)
{
	int		i;
	char	**executable;

	i = 0;
	(void)argc;
	executable = ft_split(argv[2], ' ');
	while (executable[i])
		i++;
	executable[i] = ft_strdup(argv[1]);
	i++;
	executable[i] = NULL;
	return (executable);
}

int	find_executable(char *command, char **full_path)
{
	char	*path;
	char	*dir;

	path = ft_strdup(*full_path);
	if (!path)
		return (-1);
	dir = ft_strtok(path, ':');
	while (dir != NULL)
	{
		free(*full_path);
		*full_path = ft_write_mini_path(*full_path, dir, command);
		if (access(*full_path, X_OK) == 0)
		{
			free(path);
			return (0);
		}
		dir = ft_strtok(NULL, ':');
	}
	free(path);
	return (-1);
}
