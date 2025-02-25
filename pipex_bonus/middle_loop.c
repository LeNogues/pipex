/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:39:38 by seb               #+#    #+#             */
/*   Updated: 2025/02/24 17:11:16 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
static int	count_middle_cmd(char **argv)
{
	int	i;
	int	j;
	int	size;

	i = 1;
	size = 0;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '"')
		{
			while (argv[i] && argv[i][j] != '"')
			{
				if (!argv[i][j])
				{
					i++;
					j = 0;
				}
				else
					j++;
			}
		}
		size++;
		i++;
	}
	return (size - 4);
}

char	*join_all_argv(char **argv, int nb_middle_cmd)
{
	int		i;
	char	*str;
	char	*temp;
	int		nb_rotation;

	i = 4;
	nb_rotation = 1;
	str = ft_strdup(argv[3]);
	while (argv[i] != 0 && nb_rotation < nb_middle_cmd)
	{
		temp = ft_strjoin(str, "|");
		free(str);
		str = ft_strjoin(temp, argv[i]);
		free(temp);
		i++;
		nb_rotation++;
	}
	return (str);
}*/

static void pipecpy(int new_fd[2], int old_fd[2])
{
    close(old_fd[0]);
    close(old_fd[1]);
    old_fd[0] = new_fd[0];
    old_fd[1] = new_fd[1];
    if (pipe(new_fd) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
}

int	loop_on_middle_cmd(int argc, char **argv, char **envp, t_pipe pipe_fd)
{
	int i;
	int id;
	t_args	args;
	
	i = 3;
	while(i < argc - 2)
	{
		args.file = NULL;
		args.executable = ft_split(argv[i], ' ');
		args.full_path = verif_arg(args.executable, envp);
		if (!args.full_path)
			return (free_executable(args.executable), -2);
		id = fork();
		if (id == 0 && args.executable[0] != 0)
			execute_middle(&args, envp, pipe_fd);
		else
			pipecpy(pipe_fd.new, pipe_fd.old);
		free_path_exec(args.full_path, args.executable);
		i++;
	}
	return (0);
}
