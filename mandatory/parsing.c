/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:59:14 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/02/27 12:51:57 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*verif_arg1(char **executable, char **envp)
{
	char	*full_path;

	if (access(executable[0], X_OK) == 0)
		return (ft_strdup(executable[0]));
	full_path = get_path(envp);
	if (!full_path)
	{
		error_message(-2);
		free_path_exec(full_path, executable);
		exit(EXIT_FAILURE);
	}
	if (!executable)
		return (full_path);
	if (executable[0] == 0)
		return (full_path);
	else if (find_executable(executable[0], &full_path) == -1)
	{
		write(1, "Command not found\n", 19);
		full_path = ft_strdup("/usr/bin");
		if (!full_path)
			return (0);
	}
	return (full_path);
}

char	*verif_arg2(char **executable, char **envp)
{
	char	*full_path;

	if (access(executable[0], X_OK) == 0)
	{
		full_path = ft_strdup(executable[0]);
		return (full_path);
	}
	full_path = get_path(envp);
	if (!full_path)
	{
		error_message(-2);
		free_path_exec(full_path, executable);
		exit(EXIT_FAILURE);
	}
	else if (executable[0] == 0)
		return (full_path);
	if (find_executable(executable[0], &full_path) == -1)
	{
		write(1, "Command not found\n", 19);
		full_path = ft_strdup("/usr/bin");
	}
	return (full_path);
}
