/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 21:03:51 by seb               #+#    #+#             */
/*   Updated: 2025/02/23 21:11:36 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	int         is_heredoc;
	t_heredoc   heredoc;

	is_heredoc = 0;
	if(argc >= 2)
		is_heredoc = (ft_strcmp(argv[1], "here_doc") == 0);
	if(argc < 5 || (is_heredoc == 1 && argc != 6))
		return (error(1));
	if (is_heredoc == 1)
	{
		heredoc.cmd1 = argv[3];
		heredoc.cmd1 = argv[4];
		heredoc.limiter = argv[2];
		heredoc.ofile = argv[5];
		manage_heredoc(heredoc, envp);
		return (0);
	}
}