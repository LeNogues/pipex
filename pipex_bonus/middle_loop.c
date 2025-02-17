/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:39:38 by seb               #+#    #+#             */
/*   Updated: 2025/02/17 16:01:47 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int count_middle_cmd(char **argv) 
{
	int i;
	int j;
	int size;

	i = 1;
	size = 0;
	while (argv[i]) {
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
	return size - 4;
}

char	*join_all_argv(char **argv, int nb_middle_cmd) {
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
	return str;
}

void	loop_on_middle_cmd(char **argv, char **envp, int pipe_fd[2])
{
	int i;
	const int nb_middle_cmd = count_middle_cmd(argv);
	char *argv_one_arg;
	char **executable;
	
	i = 0;
	
	(void)envp;
	(void)pipe_fd;
	argv_one_arg = join_all_argv(argv, nb_middle_cmd);
	//debut de la boucle
	//je ft_split(ft_strtok) pour chaque iteration
	executable = create_executable_middle(ft_strtok(argv_one_arg, '|'));
	printf("%s\n", executable[1]);
	while(i < nb_middle_cmd - 1)
	{
		executable = create_executable_middle(ft_strtok(NULL, '|'));
		printf("%s\n", executable[1]);
		i++;
	}
	printf("%d\n", nb_middle_cmd);
	free(argv_one_arg);
}