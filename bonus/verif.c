/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:38:24 by seb               #+#    #+#             */
/*   Updated: 2025/02/25 18:46:15 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	verif_infile(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		write(1, "file not found or open\n", 23);
		return (-1);
	}
	close(fd);
	return (1);
}

int	verif_outfile(char *file)
{
	int	fd;

	fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
	{
		write(1, "file not found or open\n", 23);
		return (-1);
	}
	close(fd);
	return (1);
}
