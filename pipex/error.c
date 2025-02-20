/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:25:14 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/02/18 16:06:56 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_message(int error_code)
{
	if (error_code == -1)
		write(1, "Could not create executable\n", 28);
	else if (error_code == -2)
		write(1, "Could not create full_path\n", 27);
	else if (error_code == -3)
		write(1, "Could not create pipe\n", 22);
}
