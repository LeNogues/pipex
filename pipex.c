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
	int		file_fd;

	if (pipe(pipe_fd) == -1)
		return (-3);
	executable = create_executable1(argc, argv);
	if (!executable)
		return (-1);
	full_path = verif_arg(argc, executable, envp);
	if (!full_path)
		return (free_executable(executable), -2);
	id = fork();
	if (id == 0)
		exec1(full_path, executable, envp, pipe_fd);
	else
	{
		close(pipe_fd[1]);
		wait(NULL);
	}
	free_path_exec(full_path, executable);
	executable = create_executable2(argc, argv);
	if (!executable)
		return (-1);
	full_path = verif_arg(argc, executable, envp);
	if (!full_path)
		return (free_executable(executable), -2);
	id = fork();
	if (id == 0)
	{
		file_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (file_fd == -1)
		{
			perror("open");
			exit(EXIT_FAILURE);
		}
		dup2(file_fd, STDOUT_FILENO);
		close(file_fd);
		exec2(full_path, executable, envp, pipe_fd);
	}
	else
	{
		close(pipe_fd[0]);
		wait(NULL);
	}
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
