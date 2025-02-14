/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:21:22 by seb               #+#    #+#             */
/*   Updated: 2025/02/14 14:15:00 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	pipex_state;

	
	pipex_state = pipex(argc, argv, envp);
	if (pipex_state != 1)
		error_message(pipex_state);
	return (0);
}
