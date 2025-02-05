/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:39:49 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/02/05 16:37:27 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec1(char *full_path, char **executable, char **envp, int pipe_fd[2])
{
	close(pipe_fd[0]);
	dup2(pipe_fd[1], STDOUT_FILENO);
	if (execve(full_path, executable, envp) == -1)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}
}

void	exec2(char *full_path, char **executable, char **envp, int pipe_fd[2])
{
	dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[0]);
	execve(full_path, executable, envp);
	perror("execlp");
	exit(EXIT_FAILURE);
}
