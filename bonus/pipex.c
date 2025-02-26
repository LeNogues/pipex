/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/02/03 15:33:17 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/02/03 15:33:17 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipex(int argc, char **argv, char **envp)
{
	t_pipe	pipe_fd;
	int		result;

	if (pipe(pipe_fd.old) == -1)
		return (-3);
	if (verif_infile(argv[1]) != -1)
	{
		result = handle_first_cmd(argv, envp, &pipe_fd);
		if (result != 0)
			return (result);
	}
	loop_on_middle_cmd(argc, argv, envp, &pipe_fd);
	if (verif_outfile(argv[argc - 1]) != -1)
	{
		result = handle_last_cmd(argc, argv, envp, pipe_fd);
		if (result != 0)
			return (result);
	}
	while (waitpid(0, NULL, 0) != -1)
		;
	return (1);
}
