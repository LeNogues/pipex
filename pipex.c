/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:33:17 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/02/03 15:33:17 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipex(int argc, char **argv, char **envp)
{
	char	*full_path;
	int		id;
	char	**executable;
	int		pipe_fd[2];
	char	buffer[128];

	if (pipe(pipe_fd) == -1)
		return (-3);

	executable = create_executable(argc, argv);
	if (!executable)
		return (-1);
	full_path = verif_arg(argc, executable, envp);
	if (!full_path)
		return (free_executable(executable), -2);

	id = fork();
	if (id == 0)
		premiere_exec(full_path, executable, envp, pipe_fd);
	read(pipe_fd[0], buffer, sizeof(buffer));
	free_path_exec(full_path, executable);
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	int	pipex_state;

	pipex_state = pipex(argc, argv, envp);
	if (pipex_state != 1)
		error_message(pipex_state);
	return (0);
}
