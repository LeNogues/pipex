/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:59:14 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/02/03 18:08:46 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*verif_arg(int argc, char **argv, char *full_path, char **envp)
{
	if (argc < 2)
	{
		printf("Usage: %s <commande> [arguments...]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	full_path = get_path(envp);
	if (find_executable(argv[2], &full_path) == -1)
	{
		printf("Command not found: %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	return (full_path);
}
