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
	int	pipe_fd[2];
	int	result;

	if (pipe(pipe_fd) == -1)
		return (-3);
	result = handle_first_cmd(argc, argv, envp, pipe_fd);
	if (result != 0)
		return (result);
	result = handle_second_cmd(argc, argv, envp, pipe_fd);
	if (result != 0)
		return (result);
	close(pipe_fd[0]);
	wait(NULL);
	return (1);
}
