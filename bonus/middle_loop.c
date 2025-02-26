/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:39:38 by seb               #+#    #+#             */
/*   Updated: 2025/02/26 10:56:05 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipecpy(int new_fd[2], int old_fd[2])
{
	close(old_fd[0]);
	close(old_fd[1]);
	old_fd[0] = new_fd[0];
	old_fd[1] = new_fd[1];
}

int	loop_on_middle_cmd(int argc, char **argv, char **envp, t_pipe *pipe_fd)
{
	int		i;
	int		id;
	t_args	args;

	i = 3;
	while (i < argc - 2)
	{
		if (pipe(pipe_fd->new) == -1)
			return (-3);
		args.file = NULL;
		args.executable = ft_split(argv[i], ' ');
		args.full_path = verif_arg(args.executable, envp);
		if (!args.full_path)
			return (free_executable(args.executable), -2);
		id = fork();
		if (id == 0 && args.executable[0] != 0)
			execute_middle(&args, envp, *pipe_fd);
		free_path_exec(args.full_path, args.executable);
		pipecpy(pipe_fd->new, pipe_fd->old);
		i++;
	}
	return (0);
}
