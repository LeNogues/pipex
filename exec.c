/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:39:49 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/02/14 18:19:51 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec1(char *full_path, char **executable, char **envp, int pipe_fd[2])
{
	close(pipe_fd[0]);
	dup2(pipe_fd[1], STDOUT_FILENO);
	execve(full_path, executable, envp);
	free_path_exec(full_path, executable);
	exit(EXIT_FAILURE);
}

void	exec2(char *full_path, char **executable, char **envp, int pipe_fd[2])
{
	dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[0]);
	execve(full_path, executable, envp);
	free_path_exec(full_path, executable);
	exit(EXIT_FAILURE);
}

void	execute_with_input(t_args *args, char **envp, int pipe_fd[2])
{
	int	file_fd;

	file_fd = open(args->file, O_RDONLY);
	if (file_fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	else
	{
		dup2(file_fd, STDIN_FILENO);
		close(file_fd);
	}
	exec1(args->full_path, args->executable, envp, pipe_fd);
}

void	execute_with_output(t_args *args, char **envp, int pipe_fd[2])
{
	int	file_fd;

	file_fd = open(args->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file_fd == -1)
	{
		perror("open");
		free_path_exec(args->full_path, args->executable);
		exit(EXIT_FAILURE);
	}
	else
	{
		dup2(file_fd, STDOUT_FILENO);
		close(file_fd);
		exec2(args->full_path, args->executable, envp, pipe_fd);
	}
}
