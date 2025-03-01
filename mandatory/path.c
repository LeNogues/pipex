/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:23:22 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/02/26 15:59:15 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_write_mini_path(char *mini_path, char *dir, char *command)
{
	const int	size = ft_strlen(dir) + ft_strlen(command) + 2;
	int			i;
	int			j;

	mini_path = malloc(sizeof(char) * size);
	if(!mini_path)
		return (0);
	j = 0;
	i = 0;
	while (dir[j])
		mini_path[i++] = dir[j++];
	mini_path[i++] = '/';
	j = 0;
	while (command[j])
		mini_path[i++] = command[j++];
	mini_path[i] = 0;
	return (mini_path);
}

char	*get_path(char **envp)
{
	int		i;
	char	*path;

	i = 0;
	path = NULL;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = malloc(ft_strlen(envp[i]) + 1);
			if (!path)
				return (0);
			ft_strlcpy(path, envp[i] +5, ft_strlen(envp[i]) - 4);
			break ;
		}
		i++;
	}
	return (path);
}
