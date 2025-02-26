/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:23:26 by seb               #+#    #+#             */
/*   Updated: 2025/02/25 17:54:17 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	handle_last_cmd(int argc, char **argv, char **envp, t_pipe pipe_fd)
{
	char	**executable;
	char	*full_path;
	int		id;
	t_args	args;

	executable = create_executable2(argc, argv);
	full_path = verif_arg(executable, envp);
	if (!full_path)
		return (free_executable(executable), -2);
	args.file = argv[argc - 1];
	args.full_path = full_path;
	args.executable = executable;
	id = fork();
	if (id == 0 && executable[0] != 0)
		execute_with_output(&args, envp, pipe_fd);
	else
	{
		close(pipe_fd.old[0]);
		close(pipe_fd.old[1]);
	}
	free_path_exec(full_path, executable);
	return (0);
}

int	handle_first_cmd(char **argv, char **envp, t_pipe *pipe_fd)
{
	char	**executable;
	char	*full_path;
	int		id;
	t_args	args;

	executable = create_executable1(argv);
	full_path = verif_arg(executable, envp);
	if (!full_path)
		return (free_executable(executable), -2);
	args.file = argv[1];
	args.full_path = full_path;
	args.executable = executable;
	id = fork();
	if (id == 0 && executable[0] != 0)
		execute_with_input(&args, envp, *pipe_fd);
	free_path_exec(full_path, executable);
	return (0);
}
