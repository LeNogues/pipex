/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:21:22 by seb               #+#    #+#             */
/*   Updated: 2025/03/01 12:21:27 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int			pipex_state;
	t_here_doc	hd;

	if (argc < 5)
	{
		write(1, "Usage: ./pipex infile \"command1 + arguments\" ", 46);
		write(1, "\"command2 + arguments\" outfile\n", 32);
		return (0);
	}
	if(argc == 6 && ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		hd.state = 0;
		hd.state = here_doc(argv, hd, envp);
		if (hd.state!= 1)
			error_message(hd.state);
	}
	else
	{
		pipex_state = pipex(argc, argv, envp);
		if (pipex_state != 1)
			error_message(pipex_state);
	}
	return (0);
}
