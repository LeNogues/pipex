/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:21:22 by seb               #+#    #+#             */
/*   Updated: 2025/02/19 17:08:46 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	pipex_state;

	if (argc != 5)
	{
		write(1, "Usage: ./pipex infile \"command1 + arguments\" ", 46);
		write(1, "\"command2 + arguments\" outfile\n", 32);
		exit(EXIT_FAILURE);
	}
	pipex_state = pipex(argv, envp);
	if (pipex_state != 1)
		error_message(pipex_state);
	return (0);
}
