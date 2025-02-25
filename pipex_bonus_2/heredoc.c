/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 21:11:58 by seb               #+#    #+#             */
/*   Updated: 2025/02/23 21:27:36 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <fcntl.h>

static void validate(int *outfile_fd, int *pipe_fd, char *outfile)
{
    *outfile_fd = open(outfile, O_WRONLY | O_APPEND | O_CREAT, 0644); 
    if (*outfile_fd == -1)
        error("outfile");
    if (pipe(pipe_fd) < 0)
    {
        close(*outfile_fd);
        error("pipe_val");
    }
}

static void get_content(t_heredoc heredoc)
{
    char    *buff;
    int     limit_found;

    limit_found = 0;
    while (!limit_found)
    {
        ft_putstr
    }
    
}

int heredoc(t_heredoc heredoc, char **envp)
{
    int pipe_fd[2];
    int id[2];
    int outfile_fd;

    validate(&outfile_fd, heredoc.pipe, heredoc.ofile);
    get_content(heredoc);
}