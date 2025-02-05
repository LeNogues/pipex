/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:04:57 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/02/05 14:21:25 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_path_exec(char *full_path, char **executable)
{
	int	i;

	free(full_path);
	i = 0;
	while (executable[i])
		free(executable[i++]);
	free(executable);
}

void	free_executable(char **executable)
{
	int	i;

	i = 0;
	while (executable[i])
		free(executable[i++]);
	free(executable);
}
