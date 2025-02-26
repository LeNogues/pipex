/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:23:26 by seb               #+#    #+#             */
/*   Updated: 2025/02/19 16:01:41 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	handle_second_cmd(char **argv, char **envp, int pipe_fd[2])
{
	char	**executable;
	char	*full_path;
	int		id;
	t_args	args;

	executable = create_executable2(argv);
	full_path = verif_arg2(executable, envp);
	if (!full_path)
		return (free_executable(executable), -2);
	args.file = argv[4];
	args.full_path = full_path;
	args.executable = executable;
	id = fork();
	if (id == 0 && executable[0] != 0)
		execute_with_output(&args, envp, pipe_fd);
	else
		close(pipe_fd[0]);
	wait(NULL);
	free_path_exec(full_path, executable);
	return (0);
}

int	handle_first_cmd(char **argv, char **envp, int pipe_fd[2])
{
	char	**executable;
	char	*full_path;
	int		id;
	t_args	args;

	executable = create_executable1(argv);
	full_path = verif_arg1(executable, envp);
	if (!full_path)
		return (free_executable(executable), -2);
	args.file = argv[1];
	args.full_path = full_path;
	args.executable = executable;
	id = fork();
	if (id == 0 && executable[0] != 0)
		execute_with_input(&args, envp, pipe_fd);
	else
		close(pipe_fd[1]);
	free_path_exec(full_path, executable);
	return (0);
}
