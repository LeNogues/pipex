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

int	verif_infile(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		write(1, "file not found or open\n", 23);
		return (-1);
	}
	close(fd);
	return (1);
}

int	verif_outfile(char *file)
{
	int	fd;

	fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
	{
		write(1, "file not found or open\n", 23);
		return (-1);
	}
	close(fd);
	return (1);
}

int	pipex(char **argv, char **envp)
{
	int	pipe_fd[2];
	int	result;

	if (pipe(pipe_fd) == -1)
		return (-3);
	if (verif_infile(argv[1]) != -1)
	{
		result = handle_first_cmd(argv, envp, pipe_fd);
		if (result != 0)
			return (result);
	}
	if (verif_outfile(argv[4]) != -1)
	{
		result = handle_second_cmd(argv, envp, pipe_fd);
		if (result != 0)
			return (result);
	}
	wait(NULL);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	return (1);
}
