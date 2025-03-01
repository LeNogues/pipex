/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:46:43 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/03/01 15:10:42 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	execute_first(t_here_doc hd, t_pipe pipe_fd, char *full_path,
		char **envp)
{
	dup2(pipe_fd.old[0], STDIN_FILENO);
	close(pipe_fd.old[0]);
	close(pipe_fd.old[1]);
	dup2(pipe_fd.new[1], STDOUT_FILENO);
	close(pipe_fd.new[1]);
	close(pipe_fd.new[0]);
	execve(full_path, hd.cmd1, envp);
}

static void	execute_second(t_here_doc hd, t_pipe pipe_fd, char *full_path,
		char **envp)
{
	int	file_fd;

	file_fd = open(hd.file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file_fd == -1)
	{
		perror("open");
		free_path_exec(full_path, hd.cmd2);
		exit(EXIT_FAILURE);
	}
	dup2(file_fd, STDERR_FILENO);
	close(file_fd);
	close(pipe_fd.new[1]);
	close(pipe_fd.old[0]);
	close(pipe_fd.old[1]);
	dup2(pipe_fd.new[0], STDIN_FILENO);
	close(pipe_fd.new[0]);
	execve(full_path, hd.cmd2, envp);
}

static void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

static void	here_doc_line(char *delim, t_pipe pipe_fd)
{
	char	*line;

	while (1)
	{
		write(1, "\e[32mhere_doc> \e[0m", 20);
		line = get_next_line(STDIN_FILENO);
		if (!line)
			return ;
		if (ft_strncmp(line, delim, ft_strlen(delim)) == 0)
		{
			free(line);
			return ;
		}
		ft_putstr_fd(line, pipe_fd.old[1]);
		free(line);
	}
}

int	here_doc(char **argv, t_here_doc hd, char **envp)
{
	t_pipe	pipe_fd;
	char	*full_path;

	int id1, id2;
	hd.limiter = argv[2];
	hd.cmd1 = ft_split(argv[3], ' ');
	hd.cmd2 = ft_split(argv[4], ' ');
	if (!hd.cmd1 || !hd.cmd2)
		return (0);
	hd.file = argv[5];
	if (pipe(pipe_fd.old) == -1 || pipe(pipe_fd.new) == -1)
		return (-3);
	here_doc_line(hd.limiter, pipe_fd);
	id1 = fork();
	if (id1 == 0)
	{
		full_path = verif_arg(hd.cmd1, envp);
		execute_first(hd, pipe_fd, full_path, envp);
	}

	id2 = fork();
	if (id2 == 0)
	{
		full_path = verif_arg(hd.cmd2, envp);
		execute_second(hd, pipe_fd, full_path, envp);
	}
	close(pipe_fd.old[0]);
	close(pipe_fd.old[1]);
	close(pipe_fd.new[0]);
	close(pipe_fd.new[1]);
	waitpid(id1, NULL, 0);
	waitpid(id2, NULL, 0);
	return (1);
}
