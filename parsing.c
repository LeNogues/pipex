/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:59:14 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/02/11 15:28:04 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*verif_arg1(char **executable, char **envp)
{
	char	*full_path;

	full_path = get_path(envp);
	if (!full_path)
	{
		error_message(-2);
		free_path_exec(full_path, executable);
		exit(EXIT_FAILURE);
	}
	else if (find_executable(executable[0], &full_path) == -1)
	{
		write(1, "Command not found\n", 19);
		full_path = ft_strdup("/usr/bin");
	}
	return (full_path);
}

char	*verif_arg2(char **executable, char **envp)
{
	char	*full_path;

	full_path = get_path(envp);
	if (!full_path)
	{
		error_message(-2);
		free_path_exec(full_path, executable);
		exit(EXIT_FAILURE);
	}
	if (find_executable(executable[0], &full_path) == -1)
	{
		write(1, "Command not found\n", 19);
	}
	return (full_path);
}
